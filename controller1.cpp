#include "main.cpp"
#include "helper.h"
#include <chrono>
#include <ctime>
#include "inttypes.h"
std::time_t  current_time = 0;
enum AutState
{
  S0,
  S1
};
struct TState_Controller1
{
  float  rear_max_acc;
  float  rear_bra_acc;
  float  response_time;
  float  front_max_bra;
  AutState  autState;

};
TState_Controller1  ts_Controller1;
std::time_t  step_time = 1.0E9;
Timer  last_event_time = 0;

int    Step()
{
	int  exec = 0;
	current_time = step_time+current_time;
	if(ts_Controller1.autState == S0)
	{
		
		// vehicle_env=initializeEnv();
		initPython();
		generate_action_from_state();
		update_state_from_action();
		;ts_Controller1.autState = S1;
		exec = 1;
	
	}else if(ts_Controller1.autState == S1)
	{
		
		generate_action_from_state();
		update_state_from_action();
		bool validAction = control_safety(ts_Controller1.response_time, ts_Controller1.rear_max_acc,ts_Controller1.front_max_bra, ts_Controller1.rear_bra_acc);
		;
		ts_Controller1.autState = S1;
		exec = 1;
	
	}
	if(exec == 1)
	{
		last_event_time.reset_clock(current_time);
	
	}
	return exec;

}
int main(int argc, char** argv)
{
	IO::configInputStream(argc, argv);
	ts_Controller1.autState = S0;
	ts_Controller1.rear_max_acc = 5;
	ts_Controller1.rear_bra_acc = 3;
	ts_Controller1.response_time = 1;
	ts_Controller1.front_max_bra = 5;
	while (1)
	{
		Event  _evt = IO::read_event(argc);
		if(_evt.label.empty())
		{
			break;
		
		}else if(_evt.label.compare("Step") == 0)
		{
			if(Step())
			{
				continue;
			}
		}else if(_evt.label.compare("advanceTo") == 0){
			if(Types::get_str(_evt.params[0]).find(":") != std::string::npos){
				long int numberOfSteps = advanceToV1(current_time, step_time, Types::get_str(_evt.params[0]));
				while (numberOfSteps > 0)
				{
					Step();
					numberOfSteps--;
				}
			}
			else{
				long int numberOfSteps = advanceToV2(current_time, step_time, Types::get_str(_evt.params[0]), (std::time_t) Types::get_double(_evt.params[1]));
				while (numberOfSteps > 0)
				{
					Step();
					numberOfSteps--;
				}
			}
		}else if(_evt.label.compare("advanceOf") == 0){
			if(Types::get_str(_evt.params[0]).find(":") != std::string::npos){
				long int numberOfSteps = advanceOfV1(step_time, Types::get_str(_evt.params[0]));
				while (numberOfSteps > 0)
				{
					Step();
					numberOfSteps--;
				}
			}
			else{
				long int numberOfSteps = advanceOfV2(step_time, Types::get_str(_evt.params[0]), (std::time_t) Types::get_double(_evt.params[1]));
				while (numberOfSteps > 0)
				{
					Step();
					numberOfSteps--;
				}
			}	
		}
		else 
		{
			ERROR_1;
		
		}
	
	}
	return 0;

}