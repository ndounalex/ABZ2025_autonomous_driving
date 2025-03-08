#include </usr/include/python3.8/Python.h>
#include </usr/include/python3.8/pyconfig.h>
#include "iostream"
#include <stdio.h>

double** vehicle_env;
double** vehicle_env_temp;
bool first = true;
PyObject *name, *load_module, *func, *callfunc, *args, *update_state;

double fun1_out;
double vehicle_lane;
int lane_number = 3;
int count;
double **generate_state;
int action_count = 1;
double action;
double tolerance = 0.1;
bool crashed = false;

int* get_front_and_rear_vehicle_temp(){
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
            std::cout << vehicle_env_temp[i][j]<<", ";
        }
        std::cout << "]"<< std::endl;
        
    }

    for(int i=1;i<nb_vehicles;i++){
        if(abs(vehicle_env_temp[i][2])<tolerance){
            if(vehicle_env_temp[i][1]<0){
                if((rear!=0) && (vehicle_env_temp[rear][1]<vehicle_env_temp[i][1])){
                    rear = i;
                }else if(rear==0){rear=i;}
            }else if(vehicle_env_temp[i][1]>0){
                if((front!=0) && (vehicle_env_temp[front][1]>vehicle_env_temp[i][1])){
                    front = i;
                }else if(front==0){front=i;}
            }
        }
    }
    frontAndRear[0]=front;
    frontAndRear[1]=rear;
   return frontAndRear; 
}

int* get_front_and_rear_vehicle(){
    // return get_front_and_rear_vehicle_temp();
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

void generate_first_env(){
    std::cout << "generate fist env "<< std::endl;
    func = PyObject_GetAttrString(load_module,(char*)"generate_first_env");
    callfunc =PyObject_CallObject(func,NULL);
    //std::cout << "Init python 3"<< std::endl;
    //std::cout << "Init python 4"<< std::endl;
    count = (int) PyList_Size(callfunc);
    //std::cout << count<< std::endl;
    vehicle_env = new double*[count];
    PyObject *ptemp,  *ptempsub;
    //std::cout << "Init python 4"<< std::endl;
    for (int i = 0 ; i < count ; i++ )
    {
        ptemp = PyList_GetItem(callfunc,i);
        vehicle_env[i]= new double[5];
        for(int j=0; j < 5 ; j++ ){
            ptempsub = PyList_GetItem(ptemp,j);
            vehicle_env[i][j]=PyFloat_AsDouble(ptempsub);
        }
        
    }
    vehicle_env_temp = vehicle_env;
}

void initPython(bool multi_lane, std::string mode)
{
    Py_Initialize();
    PyObject *sysmodule = PyImport_ImportModule("sys");
    PyObject *syspath = PyObject_GetAttrString(sysmodule, "path");
    PyList_Append(syspath, PyUnicode_FromString("."));
    Py_DECREF(syspath);
    Py_DECREF(sysmodule);
    //name = PyUnicode_FromString((char*)"TestSingleBase");
    std::cout << "multi_lane: "<< multi_lane<< std::endl;
    std::cout << "mode: "<< mode<< std::endl;
    if(multi_lane){
        if(mode=="base"){
            name = PyUnicode_FromString((char*)"Astd_Highway_Base");
        }else{
            name = PyUnicode_FromString((char*)"Astd_Highway_Adversarial");
        }
    }else{
        if(mode=="adversarial"){
            name = PyUnicode_FromString((char*)"Astd_Highway_Single_Adversarial");
        }else{
            name = PyUnicode_FromString((char*)"Astd_Highway_Single_Base");
        }
    }
    // name = PyUnicode_FromString((char*)"Astd_Highway_Adversarial");
    load_module  = PyImport_Import(name);
    generate_first_env();
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

void validate_safe_action(){
    vehicle_env= vehicle_env_temp;
    func = PyObject_GetAttrString(load_module,(char*)"validate_action");
    callfunc =PyObject_CallObject(func,NULL);
    return;
}


void generate_action_from_state(){
    PyObject* next_state = createPyListFromArray(vehicle_env, count);
    func = PyObject_GetAttrString(load_module,(char*)"generate_action");
    args = PyTuple_Pack(1, next_state);
    callfunc =PyObject_CallObject(func, args);
    fun1_out = PyFloat_AsDouble(callfunc);
    action = fun1_out;
}

void stop_test(){
    func = PyObject_GetAttrString(load_module,(char*)"stop_test");
    // args = PyTuple_Pack(2, PyFloat_FromDouble(fun1_out), PyFloat_FromDouble(1));
    callfunc =PyObject_CallObject(func,NULL);//args);
    PyObject* min_speed = PyDict_GetItemString(callfunc, (char*)"min_speed");
    PyObject* max_speed = PyDict_GetItemString(callfunc, (char*)"max_speed");
    PyObject*  total_reward= PyDict_GetItemString(callfunc, (char*)"total_reward");
    PyObject* total_rewards = PyDict_GetItemString(callfunc, (char*)"total_rewards");
    PyObject* action_counter = PyDict_GetItemString(callfunc, (char*)"action_counter");
    PyObject* crashes = PyDict_GetItemString(callfunc, (char*)"crashes");
    PyObject* collision_reward = PyDict_GetItemString(total_rewards, (char*)"collision_reward");
    PyObject* right_lane_reward = PyDict_GetItemString(total_rewards, (char*)"right_lane_reward");
    PyObject* high_speed_reward = PyDict_GetItemString(total_rewards, (char*)"high_speed_reward");
    PyObject* on_road_reward = PyDict_GetItemString(total_rewards, (char*)"on_road_reward");
    std::cout << "************************* Rewards ***************** "<< std::endl;
    std::cout << "on_road_reward: "<<PyFloat_AsDouble(on_road_reward)<< std::endl;
    std::cout << "high_speed_reward: "<<PyFloat_AsDouble(high_speed_reward) << std::endl;
    std::cout << "right_lane_reward: "<< PyFloat_AsDouble(right_lane_reward)<< std::endl;
    std::cout << "collision_reward: "<< PyFloat_AsDouble(collision_reward)<< std::endl;
    std::cout << "crashes: "<< PyFloat_AsDouble(crashes)<< std::endl;
    std::cout << "total_reward: "<< PyFloat_AsDouble(total_reward)<< std::endl;
    std::cout << "min_speed: "<< PyFloat_AsDouble(min_speed)<< std::endl;
    std::cout << "max_speed: "<< PyFloat_AsDouble(max_speed)<< std::endl;
    std::cout << "action counters : ["<<PyFloat_AsDouble(PyList_GetItem(action_counter,0))
                <<","<<PyFloat_AsDouble(PyList_GetItem(action_counter,1))<<","
                <<PyFloat_AsDouble(PyList_GetItem(action_counter,2))<<","
                <<PyFloat_AsDouble(PyList_GetItem(action_counter,3))<<","
                <<PyFloat_AsDouble(PyList_GetItem(action_counter,4))
                <<"]"<< std::endl;
    std::cout << "*************************************************** "<< std::endl;
    Py_ssize_t c_defaults_len = 2;
}


void update_state_from_action(bool pre_check){
    func = PyObject_GetAttrString(load_module,(char*)"update_state");
    args = PyTuple_Pack(2, PyFloat_FromDouble(fun1_out), PyFloat_FromDouble(1));
    callfunc =PyObject_CallObject(func,args);
    if(!callfunc){
        PyErr_WriteUnraisable(callfunc);
    }
    PyObject* new_state = PyDict_GetItemString(callfunc, (char*)"state");
    PyObject* lane = PyDict_GetItemString(callfunc, (char*)"lane");
    PyObject* colision = PyDict_GetItemString(callfunc, (char*)"colision");
    Py_ssize_t c_defaults_len = 2;
    
    PyObject* current_line = PyTuple_GetItem(lane, c_defaults_len);
    vehicle_lane = PyFloat_AsDouble(current_line);
    count = (int) PyList_Size(new_state);
    crashed = !!(PyObject_IsTrue(colision));
    //std::cout << count<< std::endl;
    double **temp;
    temp = new double*[count];
    PyObject *ptemp,  *ptempsub;
    for (int i = 0 ; i < count ; i++ )
    {
        ptemp = PyList_GetItem(new_state,i);
        temp[i]= new double[5];
        for(int j=0; j < 5 ; j++ ){
            ptempsub = PyList_GetItem(ptemp,j);
            temp[i][j]=PyFloat_AsDouble(ptempsub);
        }
    }
if(pre_check){
    vehicle_env_temp = temp;
}else{
    vehicle_env = temp;
}
      
}

void continues_braking_until_safe_distance (float response_time, float rear_max_acc, float front_max_bra, float rear_bra_acc, bool pre_check){
    std::cout<<" Before crashed value : "<<crashed<<"\n";
    update_state_from_action(false);
    std::cout<<" crashed value : "<<crashed<<"\n";
    if(crashed){return;}
    int* frontAndRear;
    double** vehicles;
    vehicles = pre_check?vehicle_env_temp:vehicle_env;

    if(pre_check){
        frontAndRear = get_front_and_rear_vehicle_temp();
    }else{
        frontAndRear = get_front_and_rear_vehicle();
    }

    double yFront = vehicles[0][1]*100;
    double relative_distance = vehicles[frontAndRear[0]][1];
    double yRear =vehicles[0][1]*100;
    int front_row =0;
    double front_speed = vehicles[0][3];
    double rear_speed = vehicles[0][3];
    double dmin=0;
    double exact_distance;
    /* actions value:
        0: 'slower'
        1: 'idle'
        2: 'faster'
    */
   std::cout<<" nouveaux voisins = "<< frontAndRear[0]<<" "<<frontAndRear[1] <<"\n";
    if(frontAndRear[0]==0)return;
    yFront = ((vehicles[frontAndRear[0]][1]*100)+yFront);
    front_row = frontAndRear[0];
    front_speed = front_speed + vehicles[front_row][3];
    dmin = ((rear_speed*20*response_time) + (0.5*rear_max_acc*pow(response_time,2))
        +(pow((rear_speed*20)+(response_time*rear_max_acc),2)/(2*rear_bra_acc))-
        (pow(front_speed*20,2)/(2*front_max_bra)));
    
    if(dmin<0){
        dmin=0;
    }
    // la lageur d'une cellule est de 5
    exact_distance = abs(yFront - yRear);
    std::cout<<" exact_distance vs dmi : "<<dmin<<" , "<<exact_distance<<"\n";
    bool validAction = !(exact_distance < (dmin+5));
    if(!validAction){
        action = 4;
        fun1_out = 4;
        continues_braking_until_safe_distance (response_time, rear_max_acc, front_max_bra, rear_bra_acc, pre_check);
    }
}

bool single_control_safety(float response_time, float rear_max_acc, float front_max_bra, float rear_bra_acc, bool pre_check) {
    if(action==0||action==2){action=1;}
    bool validAction = true;
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
        0: 'slower'
        1: 'idle'
        2: 'faster'
    */
   // std::cout<<" Vehicle index Front: "<<frontAndRear[0]<<", Rear: "<<frontAndRear[1]<<",   Action : "<<action<<"\n";
   if((frontAndRear[0]==frontAndRear[1])||(action==1 && (frontAndRear[1]==0))){
    return validAction;
   }
   int detect_case = 0;
    if((action==3)||(action==1 && (frontAndRear[1]==0))){
        yFront = ((vehicle_env[frontAndRear[0]][1]*100)+yFront);
        front_row = frontAndRear[0];
        front_speed = front_speed + vehicle_env[front_row][3];
        detect_case = 1;
    }else if((action==4)||(action==1 && (frontAndRear[0]==0))){
        yRear = ((vehicle_env[frontAndRear[1]][1]*100)+yRear);
        rear_row= frontAndRear[1];
        detect_case = 2;
        rear_speed = rear_speed + vehicle_env[rear_row][3];
    }else if((action==1)&&(frontAndRear[0]!=0)&&(frontAndRear[0]!=0)){
        yFront = ((vehicle_env[frontAndRear[0]][1]*100)+yFront);
        front_row = frontAndRear[0];
        front_speed = front_speed + vehicle_env[front_row][3];
        detect_case = 1;
    }
    if(((action==4)&&(frontAndRear[1]==0))||((action==3)&&(frontAndRear[0]==0))){
        return validAction;
    }
    //std::cout<<" Detection des véhicules entrant en jeu: Front: "<<yFront<<", Rear: "<<yRear<<"\n";
    dmin = ((rear_speed*20*response_time) + (0.5*rear_max_acc*pow(response_time,2))
        +(pow(rear_speed*20+response_time*rear_max_acc,2)/(2*rear_bra_acc))-
        (pow(front_speed*20,2)/(2*front_max_bra)));
    //std::cout<<" Dmin value : "<<dmin<<"\n";
    
    if(dmin<0){
        dmin=0;
    }
    //std::cout<<" Dmin value : "<<dmin+5<<" "<<(dmin+5)/5<<" "<<(dmin/5+1)<<"\n";
    // la lageur d'une cellule est de 5
    exact_distance = abs(yFront - yRear);
    //std::cout<<" valeur de dmin: "<<(dmin+5)<<" distance actuelle: "<<exact_distance<<"\n";
    validAction = !(exact_distance < ((dmin+5)));
    if((!validAction)){
        // std::cout<<" environnement non valide: "<<action<<"\n";
        if(/*action==3*/detect_case==1){
            action=4;
        }else{
            action=3;
        }
        fun1_out=action;
        // std::cout<<" correction: "<<fun1_out<<"\n";
        // update_state_from_action();
        continues_braking_until_safe_distance (response_time, rear_max_acc, front_max_bra, rear_bra_acc, pre_check);
    }
    return validAction;
}

bool control_safety(float response_time, float rear_max_acc, float front_max_bra, float rear_bra_acc, bool pre_check) {
    // return single_control_safety(response_time, rear_max_acc, front_max_bra, rear_bra_acc);
    bool multi_lane = false;
    if((!multi_lane)&&(action==0||action==2)){action=1;}
    bool validAction = true;
    int* frontAndRear= pre_check? get_front_and_rear_vehicle_temp():get_front_and_rear_vehicle();
    double** vehicles;
    if(pre_check){
        vehicles = vehicle_env_temp;
    }else{
        vehicles = vehicle_env;
    }
    double yFront = vehicles[0][1]*100;
    double yRear =vehicles[0][1]*100;
    int front_row =0;
    int rear_row = 0;
    double front_speed = vehicles[0][3];
    double rear_speed = vehicles[0][3];
    double dmin=0;
    double exact_distance;

    /* actions value:
        0: 'lane left'
        1: 'idle'
        2: 'lane right'
        3: 'faster'
        4; 'slower'std::cout<<" valeurs comparées : tata "<< action<<"\n";
    */
   std::cout<<" IA action =  "<< action<<"\n";
   std::cout<<" Vehicle lane =  "<< vehicle_lane<<"\n";
   //std::cout<<" lane = "<< vehicle_lane << " lane_number :"<<lane_number <<"\n";
   if(((vehicle_lane==(lane_number-1))&&(action==2))||((vehicle_lane==0)&&(action==0))){
    //std::cout<<" valeurs tutu "<<frontAndRear[1]<<" "<<frontAndRear[0]<<"\n";
    action=5;
   }
   std::cout<<" valeurs tutu "<<frontAndRear[1]<<" "<<frontAndRear[0]<<"\n";
   std::cout<<" IA action =  1111"<< action<<"\n";
   if((frontAndRear[0]==frontAndRear[1])||((action==2)||(action==0))||(action==1 && (frontAndRear[1]==0))){
    return validAction;
   }
   std::cout<<" IA action =  1111"<< frontAndRear[0]<<" "<<frontAndRear[1] <<"\n";
   if(action==5)action=1;
   int detect_case = 0;
    if((action==3) ||(((action==2)||(action==0))&&(abs(vehicles[frontAndRear[0]][1])<abs(vehicles[frontAndRear[1]][1])))||(action==1 && (frontAndRear[1]==0))){
        yFront = (vehicles[frontAndRear[0]][1]*100+yFront);
        front_row = frontAndRear[0];
        front_speed = front_speed + vehicles[front_row][3];
        detect_case = 1;
    }else if((action==4)||(action==1 && (frontAndRear[0]==0))){
        yRear = (vehicles[frontAndRear[1]][1]*100+yRear);
        rear_row= frontAndRear[1];
        rear_speed = rear_speed + vehicles[rear_row][3];
        detect_case = 2;
    }else if((action==1)&&(frontAndRear[0]!=0)&&(frontAndRear[0]!=0)){
        yFront = ((vehicles[frontAndRear[0]][1]*100)+yFront);
        front_row = frontAndRear[0];
        front_speed = front_speed + vehicles[front_row][3];
        detect_case = 1;
    }
    //std::cout<<" valeurs comparées : toto"<<"\n";
    if(((action==4)&&(frontAndRear[1]==0))||((action==3)&&(frontAndRear[0]==0))){
        return validAction;
    }

    dmin = ((rear_speed*20*response_time) + (0.5*rear_max_acc*pow(response_time,2))
        +(pow(rear_speed*20+response_time*rear_max_acc,2)/(2*rear_bra_acc))-
        (pow(front_speed*20,2)/(2*front_max_bra)));
    
    if(dmin<0){
        dmin=0;
    }

    // la lageur d'une cellule est de 5
    exact_distance = abs(yFront - yRear);
    validAction = !(exact_distance < ((dmin+5)));
    std::cout<<" valeurs comparées : "<<dmin+5<<" "<<exact_distance<<"\n";
    if((!validAction) && ((2< action)||detect_case)){
        if(/*action==3*/detect_case==1){
            action=4;
        }else if(action==4){
            action=3;
        }/*else if((action==2)||(action==0)||(action==1)){
            if(front_row==0){
                action=3;
            }else{
                action=4;
            }
        }*/
        fun1_out=action;
        std::cout<<" correct Action : "<<action<<"\n";
        // update_state_from_action();
        // continues_braking_until_safe_distance (response_time, rear_max_acc, front_max_bra, rear_bra_acc);
    }
    return validAction;
}

int mainTest(int argc, char *argv[]){
    // Py_Initialize();
    // initPython();

    while(true){
        if(first){
            first = false;
            func = PyObject_GetAttrString(load_module,(char*)"generate_action");
            callfunc =PyObject_CallObject(func,NULL);
            fun1_out = PyFloat_AsDouble(callfunc);
        }else{
            PyObject* next_state = createPyListFromArray(generate_state, count);
            func = PyObject_GetAttrString(load_module,(char*)"generate_action");
            args = PyTuple_Pack(1, next_state);
            callfunc =PyObject_CallObject(func,args);
            fun1_out = PyFloat_AsDouble(callfunc);
        }
        func = PyObject_GetAttrString(load_module,(char*)"update_state");
        args = PyTuple_Pack(1, PyFloat_FromDouble(fun1_out));
        callfunc =PyObject_CallObject(func,args);

        count = (int) PyList_Size(callfunc);
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