#include "main.cpp"
#include "helper_bis.h"
#include <thread>
#include <mutex>
#include <chrono>
#include <ctime>
#include <atomic>
enum AutState
{
  CoreController,
  S0,
  S1,
  S2
};
struct TState_ControllerUpdateAction
{
  AutState  autState;

};
struct TState_ChooseAction
{
  AutState  autState;

};
struct TState_CoreController
{
  Timer  left_clock_ChooseAction;
  Timer  right_clock_ControllerUpdateAction;
  TState_ChooseAction  ts_ChooseAction;
  TState_ControllerUpdateAction  ts_ControllerUpdateAction;

};
struct TState_ControllerLoop
{
  bool  multi_lane;
  bool  valid_action;
  float  rear_max_acc;
  float  response_time;
  bool  pre_check;
  bool  isStart;
  float  rear_bra_acc;
  float  front_max_bra;
  AutState  autState;
  TState_CoreController  ts_CoreController;

};
const std::vector<AutState>  shallow_final_ChooseAction = {S1, S2};
const std::vector<AutState>  shallow_final_ControllerUpdateAction = {S1};
TState_ControllerLoop  ts_ControllerLoop;
std::mutex  mtx;
std::time_t  step_time = 1.0E9;
Timer  last_event_time;
Timer  last_step_time;
Timer  exec_start;
bool  continue_signal = 1;

int    Step()
{
	int  exec = 0;
	exec_start.reset_clock();
	if((ts_ControllerLoop.autState == CoreController && ts_ControllerLoop.valid_action ))
	{
		
		// vehicle_env=initializeEnv();
		if(ts_ControllerLoop.isStart){
		 initPython();
		ts_ControllerLoop.isStart=false;
		}
		generate_action_from_state();
		update_state_from_action(ts_ControllerLoop.pre_check);
		std::cout<<" Get Environment, Get action and update current environment "<<"\n";
		add_new_action("control_safe");
		ts_ControllerLoop.valid_action = false;
		;ts_ControllerLoop.autState = CoreController;
		ts_ControllerLoop.ts_CoreController.left_clock_ChooseAction.reset_clock(last_event_time);
		ts_ControllerLoop.ts_CoreController.right_clock_ControllerUpdateAction.reset_clock(last_event_time);
		ts_ControllerLoop.ts_CoreController.ts_ChooseAction.autState = S0;
		ts_ControllerLoop.ts_CoreController.ts_ControllerUpdateAction.autState = S0;
		exec = 1;
	
	}else if(ts_ControllerLoop.autState == S1)
	{
		
		// vehicle_env=initializeEnv();
		if(ts_ControllerLoop.isStart){
		 initPython();
		ts_ControllerLoop.isStart=false;
		}
		generate_action_from_state();
		update_state_from_action(ts_ControllerLoop.pre_check);
		std::cout<<" Get Environment, Get action and update current environment "<<"\n";
		add_new_action("control_safe");
		;ts_ControllerLoop.autState = CoreController;
		ts_ControllerLoop.ts_CoreController.left_clock_ChooseAction.reset_clock(last_event_time);
		ts_ControllerLoop.ts_CoreController.right_clock_ControllerUpdateAction.reset_clock(last_event_time);
		ts_ControllerLoop.ts_CoreController.ts_ChooseAction.autState = S0;
		ts_ControllerLoop.ts_CoreController.ts_ControllerUpdateAction.autState = S0;
		exec = 1;
	
	}
	if(exec == 1)
	{
		last_event_time = exec_start;
	
	}
	return exec;

}

int    safe()
{
	int  exec = 0;
	exec_start.reset_clock();
	if((ts_ControllerLoop.autState == CoreController && ts_ControllerLoop.ts_CoreController.ts_ChooseAction.autState == S0))
	{
		if(ts_ControllerLoop.ts_CoreController.ts_ChooseAction.autState == S0)
		{
			if(ts_ControllerLoop.ts_CoreController.ts_ChooseAction.autState == S0)
			{
				
				 std::cout<<" Safe Action "<<"\n";
				if(ts_ControllerLoop.pre_check){
				validate_safe_action();
				}
				;ts_ControllerLoop.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_ControllerLoop.ts_CoreController.ts_ChooseAction.autState = S1;
				exec = 1;
			
			}
		
		}
	
	}
	if(exec == 1)
	{
		last_event_time = exec_start;
	
	}
	return exec;

}

int    unsafe()
{
	int  exec = 0;
	exec_start.reset_clock();
	if((ts_ControllerLoop.autState == CoreController && ts_ControllerLoop.ts_CoreController.ts_ChooseAction.autState == S0))
	{
		if(ts_ControllerLoop.ts_CoreController.ts_ChooseAction.autState == S0)
		{
			if(ts_ControllerLoop.ts_CoreController.ts_ChooseAction.autState == S0)
			{
				
				std::cout<<" UnSafe Action "<<"\n";
				if(!ts_ControllerLoop.pre_check){
				continues_braking_until_safe_distance (ts_ControllerLoop.response_time, ts_ControllerLoop.rear_max_acc, ts_ControllerLoop.front_max_bra, ts_ControllerLoop.rear_bra_acc, ts_ControllerLoop.pre_check);
				}
				ts_ControllerLoop.valid_action=true;
				;ts_ControllerLoop.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_ControllerLoop.ts_CoreController.ts_ChooseAction.autState = S2;
				exec = 1;
			
			}
		
		}
	
	}
	if(exec == 1)
	{
		last_event_time = exec_start;
	
	}
	return exec;

}

int    control_safe()
{
	int  exec = 0;
	exec_start.reset_clock();
	if((ts_ControllerLoop.autState == CoreController && ts_ControllerLoop.ts_CoreController.ts_ControllerUpdateAction.autState == S0))
	{
		if(ts_ControllerLoop.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
		{
			if(ts_ControllerLoop.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
			{
				
				ts_ControllerLoop.valid_action = control_safety(ts_ControllerLoop.response_time, ts_ControllerLoop.rear_max_acc,ts_ControllerLoop.front_max_bra, ts_ControllerLoop.rear_bra_acc, ts_ControllerLoop.pre_check);
				{
				std::cout<<" Action Validation"<<"\n";
				if(ts_ControllerLoop.valid_action){add_new_action("safe");
				}else{add_new_action("unsafe");}
				}
				;ts_ControllerLoop.ts_CoreController.right_clock_ControllerUpdateAction.reset_clock();ts_ControllerLoop.ts_CoreController.ts_ControllerUpdateAction.autState = S1;
				exec = 1;
			
			}
		
		}
	
	}
	if(exec == 1)
	{
		last_event_time = exec_start;
	
	}
	return exec;

}
void* producers_event_func(void* arg)
{
	while (continue_signal)
	{
		int*  argc = (int*) arg;
		if (mtx.try_lock()) {
			mtx.lock();
		}
		Event  _evt = IO::read_event(*argc);
		if(_evt.label.empty())
		{
			continue_signal = 0;
			ERROR_5;
		
		}else if(_evt.label.compare("safe") == 0)
		{
			if(!(safe()))
			{
				ERROR_2;
			
			}
		
		}else if(_evt.label.compare("unsafe") == 0)
		{
			if(!(unsafe()))
			{
				ERROR_2;
			
			}
		
		}else if(_evt.label.compare("control_safe") == 0)
		{
			if(!(control_safe()))
			{
				ERROR_2;
			
			}
		
		}else 
		{
			ERROR_1;
		
		}
		mtx.unlock();
	
	}
	return NULL;

}
void* producers_Step_func(void* arg)
{
	while (continue_signal)
	{
		if(last_step_time.expired(step_time))
		{
			last_step_time.reset_clock();
			if (mtx.try_lock()) {
				mtx.lock();
			}
			Step();
			mtx.unlock();
		
		}
		std::this_thread::sleep_for(std::chrono::nanoseconds(step_time/1000));
	
	}
	return NULL;

}
int main(int argc, char** argv)
{
	IO::configInputStream(argc, argv);
	ts_ControllerLoop.autState = S1;
	ts_ControllerLoop.multi_lane = multi_lane;
	ts_ControllerLoop.valid_action = true;
	ts_ControllerLoop.rear_max_acc = 5;
	ts_ControllerLoop.response_time = 1;
	ts_ControllerLoop.pre_check = pre_check;
	ts_ControllerLoop.isStart = true;
	ts_ControllerLoop.rear_bra_acc = 3;
	ts_ControllerLoop.front_max_bra = 5;
	pthread_t  producers[2];
	pthread_create(& producers[0], NULL, producers_event_func, (void*) &argc);
	pthread_create(& producers[1], NULL, producers_Step_func, NULL);
	pthread_join(producers[0], NULL);
	pthread_join(producers[1], NULL);
	return 0;

}
