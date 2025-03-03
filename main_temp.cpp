#include <Python.h>
#include </usr/include/python3.8/pyconfig.h>
#include "iostream"
#include <stdio.h>

void initPython()
{
    Py_Initialize();
    PyObject *sysmodule = PyImport_ImportModule("sys");
    PyObject *syspath = PyObject_GetAttrString(sysmodule, "path");
    PyList_Append(syspath, PyUnicode_FromString("."));
    Py_DECREF(syspath);
    Py_DECREF(sysmodule);
}

PyObject* createPyListFromArray(double my_list[][5], int list_size){
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

int main(int argc, char *argv[]){
    // Py_Initialize();
    initPython();
    bool first = true;
    PyObject *name, *load_module, *func, *callfunc, *args;
    name = PyUnicode_FromString((char*)"TestSingleBase");
    load_module  = PyImport_Import(name);
    func = PyObject_GetAttrString(load_module,(char*)"generate_action");
    callfunc =PyObject_CallObject(func,NULL);
    double fun1_out = PyFloat_AsDouble(callfunc);

    func = PyObject_GetAttrString(load_module,(char*)"update_state");
    args = PyTuple_Pack(1, PyFloat_FromDouble(fun1_out));
    callfunc =PyObject_CallObject(func,args);
    std::cout << "Tata ========= " << callfunc << std::endl;
    // double fun2_out = PyFloat_AsDouble(callfunc);
    // std::string fun4_out = _PyUnicode_AsString(callfunc);
    // printf("Result of call: %d\n", PyList_Check(pValue));
    std::cout<< "Pylist check ========= " << PyList_Check(callfunc)<< std::endl;
    int count = (int) PyList_Size(callfunc);
    std::cout << count<< std::endl;
    double temp[count][5];
    PyObject *ptemp, *objectsRepresentation, *ptempsub;
    double a11;

    for (int i = 0 ; i < count ; i++ )
    {
        ptemp = PyList_GetItem(callfunc,i);
        // std::cout<< "Pylist check ========= "<< i<< " " << PyList_Check(ptemp)<< std::endl;
        for(int j=0; j < 5 ; j++ ){
            ptempsub = PyList_GetItem(ptemp,j);
            // std::cout<< "Pyfloat check ========= "<< j<< " " << PyFloat_Check(ptempsub)<< std::endl;
            objectsRepresentation = PyObject_Repr(ptempsub);
            a11 = PyFloat_AsDouble(objectsRepresentation);
            // temp[i][j] = a11;
            temp[i][j]=PyFloat_AsDouble(ptempsub);
        }
        
    }
    /* std::cout << "["<< std::endl;
    for (int i = 0 ; i < count ; i++ )
    {
        std::cout << "[";
        ptemp = PyList_GetItem(callfunc,i);
        for(int j=0; j < 5 ; j++ ){
            std::cout << temp[i][j]<<", ";
        }
        std::cout << "]"<< std::endl;
        
    }
    std::cout << "]"<< std::endl;*/
    std::cout << fun1_out << std::endl;
    /************* appel de la fonction pour transformer un tableau en list =========== */
    PyObject* next_state = createPyListFromArray(temp, count);
    func = PyObject_GetAttrString(load_module,(char*)"generate_action");
    args = PyTuple_Pack(1, next_state);
    callfunc =PyObject_CallObject(func,args);
    fun1_out = PyFloat_AsDouble(callfunc);
    std::cout<< "New Action ===== " << fun1_out << std::endl;
    
    /* func = PyObject_GetAttrString(load_module,(char*)"func2");
    args = PyTuple_Pack(1, PyFloat_FromDouble(3.0));
    callfunc =PyObject_CallObject(func,args);
    double fun2_out = PyFloat_AsDouble(callfunc);

        
    func = PyObject_GetAttrString(load_module,(char*)"func3");
    args = PyTuple_Pack(2, PyFloat_FromDouble(3.0), PyFloat_FromDouble(3.0));
    callfunc =PyObject_CallObject(func,args);
    double fun3_out = PyFloat_AsDouble(callfunc);

            
    func = PyObject_GetAttrString(load_module,(char*)"func4");
    args = PyTuple_Pack(1, PyUnicode_FromString((char*)"Alex"));
    callfunc =PyObject_CallObject(func,args);
    std::string fun4_out = _PyUnicode_AsString(callfunc);*/

    // Py_Finalize();

    std::cout << fun1_out << std::endl;
    /* std::cout << fun2_out << std::endl;
    std::cout << fun3_out << std::endl;*/
    // std::cout << fun4_out << std::endl;

    return 0;
}