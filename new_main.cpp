#include <Python.h>
#include </usr/include/python3.8/pyconfig.h>
#include "iostream"
#include <stdio.h>

double** vehicle_env;
double** temp_vehicle_env;
bool first = true;
PyObject *name, *load_module, *func, *callfunc, *args;

double fun1_out;
int count;
double **generate_state;
int action_count = 1;
double action;
double tolerance = 0.0001;

int* get_front_and_rear_vehicle(){
    int* frontAndRear= new int[2];
    int front = 0;
    int rear = 0;
    int row = 0;
    int nb_vehicles = count;
    std::cout << "["<< std::endl;
    for (int i = 0 ; i < count ; i++ )
    {
        std::cout << "[";
        for(int j=0; j < 5 ; j++ ){
            std::cout << vehicle_env[i][j]<<", ";
        }
        std::cout << "]"<< std::endl;
        
    }

    for(int i=1;i<nb_vehicles;i++){
        if(abs(vehicle_env[i][2])<tolerance){
            if(vehicle_env[i][1]<0){
                if((rear!=0) && (vehicle_env[rear][1]<vehicle_env[i][1])){
                    rear = i;
                }else if(rear==0){rear=i;}
            }else if(vehicle_env[i][1]>0){
                if((front!=0) && (vehicle_env[front][1]>vehicle_env[i][1])){
                    front = i;
                }else if(front==0){front=i;}
            }
        }
    }
    frontAndRear[0]=front;
    frontAndRear[1]=rear;
   return frontAndRear; 
}

void initPython()
{
    std::cout << "Init python 1"<< std::endl;
    Py_Initialize();
    PyObject *sysmodule = PyImport_ImportModule("sys");
    PyObject *syspath = PyObject_GetAttrString(sysmodule, "path");
    PyList_Append(syspath, PyUnicode_FromString("."));
    Py_DECREF(syspath);
    Py_DECREF(sysmodule);
    //std::cout << "Init python 2"<< std::endl;
    name = PyUnicode_FromString((char*)"TestSingleBase");
    //std::cout << "Init python 2.3"<< std::endl;
    //std::cout << name<< std::endl;
    load_module  = PyImport_Import(name);
    //std::cout << load_module<< std::endl;
    //std::cout << "Init python 2.4"<< std::endl;
    func = PyObject_GetAttrString(load_module,(char*)"generate_first_env");
    //std::cout << "Init python 2.2"<< std::endl;
    callfunc =PyObject_CallObject(func,NULL);
    //std::cout << "Init python 3"<< std::endl;
    count = (int) PyList_Size(callfunc);
    //std::cout << count<< std::endl;
    vehicle_env = new double*[count];
    PyObject *ptemp,  *ptempsub;
    for (int i = 0 ; i < count ; i++ )
    {
        ptemp = PyList_GetItem(callfunc,i);
        vehicle_env[i]= new double[5];
        for(int j=0; j < 5 ; j++ ){
            ptempsub = PyList_GetItem(ptemp,j);
            vehicle_env[i][j]=PyFloat_AsDouble(ptempsub);
        }
        
    }
    //std::cout << "Init python 4"<< std::endl;
}

double** initializeEnv(){
        double** my_env = new double*[5];
        for (int i = 0 ; i < 5 ; i++ )
        {
            my_env[i]= new double[5];
            for(int j=0; j < 5 ; j++ ){
                my_env[i][j]=1;
            }
            
        }
    return my_env;
} 

PyObject* createPyListFromArray(double** my_list, int list_size){
    PyObject* final_list = PyList_New(list_size);
    for (int i = 0 ; i < list_size ; i++ )
    {
        PyObject* list_item = PyList_New(5);
        for(int j=0; j < 5 ; j++ ){
            PyList_SetItem(list_item, j, PyFloat_FromDouble(my_list[i][j]));
        }
        PyList_SetItem(final_list, i, list_item);
    }
    return final_list;
}


void generate_action_from_state(){
    PyObject* next_state = createPyListFromArray(vehicle_env, count);
    func = PyObject_GetAttrString(load_module,(char*)"generate_action");
    args = PyTuple_Pack(1, next_state);
    callfunc =PyObject_CallObject(func,args);
    fun1_out = PyFloat_AsDouble(callfunc);
    action = fun1_out;
}

void validate_action(){
    func = PyObject_GetAttrString(load_module,(char*)"validate_action");
    callfunc =PyObject_CallObject(func,NULL);
    fun1_out = PyFloat_AsDouble(callfunc);
}

void update_state_from_action(int is_validation){
    func = PyObject_GetAttrString(load_module,(char*)"update_state");
        args = PyTuple_Pack(2, PyFloat_FromDouble(fun1_out), PyFloat_FromDouble(is_validation));
        callfunc =PyObject_CallObject(func,args);
        //std::cout<< "Pylist check ========= " << PyList_Check(callfunc)<< std::endl;

        count = (int) PyList_Size(callfunc);
        //std::cout << count<< std::endl;
        double **temp;
        temp = new double*[count];
        PyObject *ptemp,  *ptempsub;
        for (int i = 0 ; i < count ; i++ )
        {
            ptemp = PyList_GetItem(callfunc,i);
            temp[i]= new double[5];
            for(int j=0; j < 5 ; j++ ){
                ptempsub = PyList_GetItem(ptemp,j);
                temp[i][j]=PyFloat_AsDouble(ptempsub);
            }
        }
    if(is_validation==1){
        vehicle_env = temp;
    }else{
        temp_vehicle_env = temp;
    }
}

bool control_safety(float response_time, float rear_max_acc, float front_max_bra, float rear_bra_acc) {
    bool validAction = true;
    double** observation;
    
    int* frontAndRear= get_front_and_rear_vehicle();
    double yFront = vehicle_env[0][1]*100;
    double yRear =vehicle_env[0][1]*100;
    int front_row =0;
    int rear_row = 0;
    double front_speed = vehicle_env[0][3];
    double rear_speed = vehicle_env[0][3];
    double dmin=0;
    double exact_distance;

    /* actions value:
        0: 'lane left'
        1: 'idle'
        2: 'lane right'
        3: 'faster'
        4; 'slower'
    */
   std::cout<<" Vehicle index Front: "<<frontAndRear[0]<<", Rear: "<<frontAndRear[1]<<",   Action : "<<action<<"\n";
   if((frontAndRear[0]==frontAndRear[1])||((action==2)||(action==0))){
    return validAction;
   }
    if((action==3) ||(((action==2)||(action==0))&&(abs(vehicle_env[frontAndRear[0]][1])<abs(vehicle_env[frontAndRear[1]][1])))){
        yFront = (vehicle_env[frontAndRear[0]][1]*100+yFront);
        front_row = frontAndRear[0];
        front_speed = front_speed + vehicle_env[front_row][3];
    }else if((action==4)||(action==1)){
        yRear = (vehicle_env[frontAndRear[1]][1]*100+yRear);
        rear_row= frontAndRear[1];
        rear_speed = rear_speed + vehicle_env[rear_row][3];
    }
    if(((action==4)&&(frontAndRear[1]==0))||((action==3)&&(frontAndRear[0]==0))){
        return validAction;
    }
    std::cout<<" Detection des véhicules entrant en jeu: Front: "<<yFront<<", Rear: "<<yRear<<"\n";
    dmin = ((rear_speed*20*response_time) + (0.5*rear_max_acc*pow(response_time,2))
        +(pow(rear_speed*20+response_time*rear_max_acc,2)/(2*front_max_bra))-
        (pow(front_speed*20,2)/(2*rear_bra_acc)));
    std::cout<<" Dmin value : "<<dmin<<"\n";
    
    if(dmin<0){
        dmin=0;
    }
    std::cout<<" Dmin value : "<<dmin+5<<" "<<(dmin+5)/5<<" "<<(dmin/5+1)<<"\n";
    // la lageur d'une cellule est de 5
    exact_distance = abs(yFront - yRear);
    std::cout<<" valeur de dmin: "<<((dmin+5))<<" distance actuelle: "<<exact_distance<<"\n";
    validAction = !(exact_distance < ((dmin+5)));
    if((!validAction) && (2< action)){
        std::cout<<" environnement non valide: "<<action<<"\n";
        if(action==3){
            action=4;
        }else if(action==4){
            action=3;
        }else if((action==2)||(action==0)||(action==1)){
            if(front_row==0){
                action=3;
            }else{
                action=4;
            }
        }
        fun1_out=action;
        std::cout<<" correction: "<<fun1_out<<"\n";
        update_state_from_action();
    }
    return validAction;
}

int mainTest(int argc, char *argv[]){
    // Py_Initialize();
    initPython();

    while(true){
        if(first){
            first = false;
            func = PyObject_GetAttrString(load_module,(char*)"generate_action");
            callfunc =PyObject_CallObject(func,NULL);
            fun1_out = PyFloat_AsDouble(callfunc);
            std::cout<< "New Action ===== " << action_count << " : " << fun1_out << std::endl;
        }else{
            PyObject* next_state = createPyListFromArray(generate_state, count);
            func = PyObject_GetAttrString(load_module,(char*)"generate_action");
            args = PyTuple_Pack(1, next_state);
            callfunc =PyObject_CallObject(func,args);
            fun1_out = PyFloat_AsDouble(callfunc);
            std::cout<< "New Action ===== " << action_count << " : " << fun1_out << std::endl;
        }
        func = PyObject_GetAttrString(load_module,(char*)"update_state");
        args = PyTuple_Pack(1, PyFloat_FromDouble(fun1_out));
        callfunc =PyObject_CallObject(func,args);
        std::cout<< "Pylist check ========= " << PyList_Check(callfunc)<< std::endl;

        count = (int) PyList_Size(callfunc);
        std::cout << count<< std::endl;
        double **temp;
        temp = new double*[count];
        PyObject *ptemp,  *ptempsub;
        for (int i = 0 ; i < count ; i++ )
        {
            ptemp = PyList_GetItem(callfunc,i);
            temp[i]= new double[5];
            for(int j=0; j < 5 ; j++ ){
                ptempsub = PyList_GetItem(ptemp,j);
                temp[i][j]=PyFloat_AsDouble(ptempsub);
            }
            
        }
        generate_state = temp;
        action_count++;
    }

    return 0;

}