#include "main.cpp"
#include "helper_bis.h"
#include <thread>
#include <mutex>
#include <chrono>
#include <ctime>
#include <atomic>
enum GuardState
{
  GUARD_NOTSTARTED,
  GUARD_STARTED
};
enum InterruptState
{
  INT_FIRST,
  INT_SECOND
};
enum KleeneState
{
  KLEENE_NOTSTARTED,
  KLEENE_STARTED
};
enum ChoiceState
{
  NONE,
  LEFT,
  RIGHT
};
enum CallState
{
  NOTCALLED,
  CALLED
};
enum AutState
{
  StopTestInstance,
  ControllerLoopCall,
  S0,
  CheckCrash,
  S1,
  S2
};
struct TState_choice2StopTest_guard
{
  AutState  autState;

};
struct TState_StopTestInstance
{
  AutState  autState;

};
struct TState_choice_1choiceStopTest_guard
{
  AutState  autState;
  TState_StopTestInstance  ts_StopTestInstance;

};
struct TState_choiceStopTest_guard
{
  ChoiceState  choiceState;
  TState_choice_1choiceStopTest_guard  ts_choice_1choiceStopTest_guard;
  TState_choice2StopTest_guard  ts_choice2StopTest_guard;

};
struct TState_guardStopTest
{
  GuardState  guardState;
  TState_choiceStopTest_guard  ts_choiceStopTest_guard;

};
struct TState_StopController
{
  AutState  autState;

};
struct TState_WithCrash
{
  GuardState  guardState;
  TState_StopController  ts_StopController;

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
struct TState_NoCrash
{
  GuardState  guardState;
  TState_CoreController  ts_CoreController;

};
struct TState_CheckCrash
{
  ChoiceState  choiceState;
  TState_NoCrash  ts_NoCrash;
  TState_WithCrash  ts_WithCrash;

};
struct TState_SafetyController
{
  bool  valid_action;
  float  rear_max_acc;
  float  response_time;
  bool  isStart;
  float  rear_bra_acc;
  float  front_max_bra;
  AutState  autState;
  TState_CheckCrash  ts_CheckCrash;

};
struct TState_ControllerLoopCall
{
  CallState  callState;
  TState_SafetyController  ts_SafetyController;

};
struct TState_LaunchTest
{
  AutState  autState;
  TState_ControllerLoopCall  ts_ControllerLoopCall;

};
struct TState_pguardStopTest
{
  TState_LaunchTest  ts_LaunchTest;

};
struct TState_StopTest
{
  Timer  clock_timed_interrupt;
  InterruptState  interruptState;
  TState_pguardStopTest  ts_pguardStopTest;
  TState_guardStopTest  ts_guardStopTest;

};
struct TState_LoopTest
{
  KleeneState  kleeneState;
  TState_StopTest  ts_StopTest;

};
struct TState_Test
{
  bool  multi_lane;
  int  i;
  std::string  mode;
  TState_LoopTest  ts_LoopTest;

};
const std::vector<AutState>  deep_final_LaunchTest = {ControllerLoopCall};
const std::vector<AutState>  deep_final_SafetyController = {CheckCrash};
const std::vector<AutState>  shallow_final_StopController = {S1};
const std::vector<AutState>  deep_final_choice_1choiceStopTest_guard = {S0};
const std::vector<AutState>  shallow_final_StopTestInstance = {S0};
const std::vector<AutState>  shallow_final_choice2StopTest_guard = {S0};
TState_Test  ts_Test;
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
	if((ts_Test.i < 50  && (((((ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && (((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (0 && 0)) || (GUARD_NOTSTARTED == GUARD_STARTED && (0 && 0))) || ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (GUARD_NOTSTARTED == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end())))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (0 && 0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && (0 && 0)))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState) !=shallow_final_StopController.end()))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && (((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (0 && 0)) || (GUARD_NOTSTARTED == GUARD_STARTED && (0 && 0))) || ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (GUARD_NOTSTARTED == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end())))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (0 && 0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && (0 && 0)))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState) !=shallow_final_StopController.end()))))))) || (ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_SECOND && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_NOTSTARTED && ((NONE == NONE && (std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end() || std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), S0) !=shallow_final_choice2StopTest_guard.end())) || (NONE == LEFT && std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end()) || (NONE == RIGHT && std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice2StopTest_guard.autState) !=shallow_final_choice2StopTest_guard.end()))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_STARTED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == NONE && (std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end() || std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), S0) !=shallow_final_choice2StopTest_guard.end())) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == LEFT && std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end()) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == RIGHT && std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice2StopTest_guard.autState) !=shallow_final_choice2StopTest_guard.end())))))) || KLEENE_NOTSTARTED == ts_Test.ts_LoopTest.kleeneState) && ((INT_FIRST == INT_FIRST && (last_event_time.expired(6.0E10) == false  && (ControllerLoopCall == ControllerLoopCall && ((NOTCALLED == NOTCALLED && ((S1 == CheckCrash && ! crashed && true ) || S1 == S1)) || (NOTCALLED == CALLED && ((S1 == CheckCrash && ! crashed && true ) || S1 == S1)))))) || (INT_FIRST == INT_FIRST && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (ts_Test.ts_LoopTest.ts_StopTest.clock_timed_interrupt.expired(6.0E10)  && ((NONE == NONE && S0 == S0) || (NONE == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)))) || (GUARD_NOTSTARTED == GUARD_STARTED && ((NONE == NONE && S0 == S0) || (NONE == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0))))) || (INT_FIRST == INT_SECOND && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_NOTSTARTED && (ts_Test.ts_LoopTest.ts_StopTest.clock_timed_interrupt.expired(6.0E10)  && ((NONE == NONE && S0 == S0) || (NONE == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_STARTED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == NONE && S0 == S0) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0))))))) || ((ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && (last_event_time.expired(6.0E10) == false  && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && ((S1 == CheckCrash && ! crashed && true ) || S1 == S1)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ! crashed && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action ) || ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == S1)))))) || (ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (ts_Test.ts_LoopTest.ts_StopTest.clock_timed_interrupt.expired(6.0E10)  && ((NONE == NONE && S0 == S0) || (NONE == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)))) || (GUARD_NOTSTARTED == GUARD_STARTED && ((NONE == NONE && S0 == S0) || (NONE == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0))))) || (ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_SECOND && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_NOTSTARTED && (ts_Test.ts_LoopTest.ts_StopTest.clock_timed_interrupt.expired(6.0E10)  && ((NONE == NONE && S0 == S0) || (NONE == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_STARTED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == NONE && S0 == S0) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)))))))))
	{
		if(((((ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && (((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (0 && 0)) || (GUARD_NOTSTARTED == GUARD_STARTED && (0 && 0))) || ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (GUARD_NOTSTARTED == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end())))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (0 && 0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && (0 && 0)))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState) !=shallow_final_StopController.end()))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && (((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (0 && 0)) || (GUARD_NOTSTARTED == GUARD_STARTED && (0 && 0))) || ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (GUARD_NOTSTARTED == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end())))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (0 && 0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && (0 && 0)))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState) !=shallow_final_StopController.end()))))))) || (ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_SECOND && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_NOTSTARTED && ((NONE == NONE && (std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end() || std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), S0) !=shallow_final_choice2StopTest_guard.end())) || (NONE == LEFT && std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end()) || (NONE == RIGHT && std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice2StopTest_guard.autState) !=shallow_final_choice2StopTest_guard.end()))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_STARTED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == NONE && (std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end() || std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), S0) !=shallow_final_choice2StopTest_guard.end())) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == LEFT && std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end()) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == RIGHT && std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice2StopTest_guard.autState) !=shallow_final_choice2StopTest_guard.end())))))) || KLEENE_NOTSTARTED == ts_Test.ts_LoopTest.kleeneState) && ((INT_FIRST == INT_FIRST && (last_event_time.expired(6.0E10) == false  && (ControllerLoopCall == ControllerLoopCall && ((NOTCALLED == NOTCALLED && ((S1 == CheckCrash && ! crashed && true ) || S1 == S1)) || (NOTCALLED == CALLED && ((S1 == CheckCrash && ! crashed && true ) || S1 == S1)))))) || (INT_FIRST == INT_FIRST && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (ts_Test.ts_LoopTest.ts_StopTest.clock_timed_interrupt.expired(6.0E10)  && ((NONE == NONE && S0 == S0) || (NONE == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)))) || (GUARD_NOTSTARTED == GUARD_STARTED && ((NONE == NONE && S0 == S0) || (NONE == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0))))) || (INT_FIRST == INT_SECOND && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_NOTSTARTED && (ts_Test.ts_LoopTest.ts_StopTest.clock_timed_interrupt.expired(6.0E10)  && ((NONE == NONE && S0 == S0) || (NONE == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_STARTED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == NONE && S0 == S0) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0))))))))
		{
			ts_Test.ts_LoopTest.kleeneState = KLEENE_STARTED;
			ts_Test.ts_LoopTest.ts_StopTest.interruptState = INT_FIRST;
			// ts_Test.ts_LoopTest.ts_StopTest.clock_timed_interrupt.reset_clock(last_event_time);
            ts_Test.ts_LoopTest.ts_StopTest.clock_timed_interrupt.reset_clock(exec_start);
            last_event_time = exec_start;
			ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState = ControllerLoopCall;
			ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState = NOTCALLED;
			if((ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && (last_event_time.expired(6.0E10) == false  && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && ((S1 == CheckCrash && ! crashed && true ) || S1 == S1)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ! crashed && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action ) || ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == S1)))))))
			{
				if((last_event_time.expired(6.0E10) == false  && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && ((S1 == CheckCrash && ! crashed && true ) || S1 == S1)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ! crashed && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action ) || ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == S1))))))
				{
					if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && ((S1 == CheckCrash && ! crashed && true ) || S1 == S1)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ! crashed && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action ) || ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == S1)))))
					{
						if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && ((S1 == CheckCrash && ! crashed && true ) || S1 == S1)))
						{
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState = CALLED;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState = S1;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action = true;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc = 5;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time = 1;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.isStart = true;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc = 3;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra = 5;
							if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ! crashed && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action ))
							{
								
								if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.isStart){
								 initPython(ts_Test.multi_lane, ts_Test.mode);
								ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.isStart=false;
								}
								generate_action_from_state();
								update_state_from_action(pre_check);
								std::cout<<" Get Environment, Get action and update current environment "<<"\n";
								if(!crashed){
								add_new_action("control_safe");
								}else{
								add_new_action("crashed_callback");
								}
								ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action = false;
								;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState = CheckCrash;
								ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState = NONE;
								exec = 1;
							
							}else if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == S1)
							{
								
								// vehicle_env=initializeEnv();
								if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.isStart){
								 initPython(ts_Test.multi_lane, ts_Test.mode);
								ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.isStart=false;
								}else{
								generate_first_env();
								}
								generate_action_from_state();
								update_state_from_action(pre_check);
								std::cout<<" Get Environment, Get action and update current environment "<<"\n";
								if(!crashed){
								add_new_action("control_safe");
								}else{
								add_new_action("crashed_callback");
								}
								
								;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState = CheckCrash;
								ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState = NONE;
								exec = 1;
							
							}
						
						}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ! crashed && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action ) || ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == S1)))
						{
							if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ! crashed && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action ))
							{
								
								if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.isStart){
								 initPython(ts_Test.multi_lane, ts_Test.mode);
								ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.isStart=false;
								}
								generate_action_from_state();
								update_state_from_action(pre_check);
								std::cout<<" Get Environment, Get action and update current environment "<<"\n";
								if(!crashed){
								add_new_action("control_safe");
								}else{
								add_new_action("crashed_callback");
								}
								ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action = false;
								;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState = CheckCrash;
								ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState = NONE;
								exec = 1;
							
							}else if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == S1)
							{
								
								// vehicle_env=initializeEnv();
								if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.isStart){
								 initPython(ts_Test.multi_lane, ts_Test.mode);
								ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.isStart=false;
								}else{
								generate_first_env();
								}
								generate_action_from_state();
								update_state_from_action(pre_check);
								std::cout<<" Get Environment, Get action and update current environment "<<"\n";
								if(!crashed){
								add_new_action("control_safe");
								}else{
								add_new_action("crashed_callback");
								}
								
								;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState = CheckCrash;
								ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState = NONE;
								exec = 1;
							
							}
						
						}
					
					}
				
				}
				
				if(crashed){ts_Test.i++;stop_test();std::cout<<" ASTD Action "<<"\n";}
				;
			}else if((ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (ts_Test.ts_LoopTest.ts_StopTest.clock_timed_interrupt.expired(6.0E10)  && ((NONE == NONE && S0 == S0) || (NONE == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)))) || (GUARD_NOTSTARTED == GUARD_STARTED && ((NONE == NONE && S0 == S0) || (NONE == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0))))))
			{
				ts_Test.i++;stop_test();add_new_action("empty");std::cout<<"Interrupt Action "<<"\n";ts_Test.ts_LoopTest.ts_StopTest.interruptState = INT_SECOND;
				ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState = GUARD_NOTSTARTED;
				ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState = NONE;
				if((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_NOTSTARTED && (ts_Test.ts_LoopTest.ts_StopTest.clock_timed_interrupt.expired(6.0E10)  && ((NONE == NONE && S0 == S0) || (NONE == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)))))
				{
					ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState = GUARD_STARTED;
					if((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == NONE && S0 == S0))
					{
						ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState = LEFT;
						ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState = S0;
						if(ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)
						{
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState = StopTestInstance;
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState = S0;
							exec = 1;
						
						}
					
					}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0))
					{
						if(ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)
						{
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState = StopTestInstance;
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState = S0;
							exec = 1;
						
						}
					
					}
				
				}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_STARTED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == NONE && S0 == S0) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0))))
				{
					if((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == NONE && S0 == S0))
					{
						ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState = LEFT;
						ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState = S0;
						if(ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)
						{
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState = StopTestInstance;
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState = S0;
							exec = 1;
						
						}
					
					}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0))
					{
						if(ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)
						{
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState = StopTestInstance;
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState = S0;
							exec = 1;
						
						}
					
					}
				
				}
				
				if(crashed){ts_Test.i++;stop_test();std::cout<<" ASTD Action "<<"\n";}
				;
			}else if((ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_SECOND && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_NOTSTARTED && (ts_Test.ts_LoopTest.ts_StopTest.clock_timed_interrupt.expired(6.0E10)  && ((NONE == NONE && S0 == S0) || (NONE == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_STARTED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == NONE && S0 == S0) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0))))))
			{
				if((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_NOTSTARTED && (ts_Test.ts_LoopTest.ts_StopTest.clock_timed_interrupt.expired(6.0E10)  && ((NONE == NONE && S0 == S0) || (NONE == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)))))
				{
					ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState = GUARD_STARTED;
					if((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == NONE && S0 == S0))
					{
						ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState = LEFT;
						ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState = S0;
						if(ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)
						{
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState = StopTestInstance;
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState = S0;
							exec = 1;
						
						}
					
					}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0))
					{
						if(ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)
						{
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState = StopTestInstance;
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState = S0;
							exec = 1;
						
						}
					
					}
				
				}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_STARTED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == NONE && S0 == S0) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0))))
				{
					if((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == NONE && S0 == S0))
					{
						ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState = LEFT;
						ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState = S0;
						if(ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)
						{
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState = StopTestInstance;
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState = S0;
							exec = 1;
						
						}
					
					}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0))
					{
						if(ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)
						{
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState = StopTestInstance;
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState = S0;
							exec = 1;
						
						}
					
					}
				
				}
				
				if(crashed){ts_Test.i++;stop_test();std::cout<<" ASTD Action "<<"\n";}
				;
			}
		
		}else if(((ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && (last_event_time.expired(6.0E10) == false  && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && ((S1 == CheckCrash && ! crashed && true ) || S1 == S1)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ! crashed && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action ) || ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == S1)))))) || (ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (ts_Test.ts_LoopTest.ts_StopTest.clock_timed_interrupt.expired(6.0E10)  && ((NONE == NONE && S0 == S0) || (NONE == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)))) || (GUARD_NOTSTARTED == GUARD_STARTED && ((NONE == NONE && S0 == S0) || (NONE == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0))))) || (ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_SECOND && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_NOTSTARTED && (ts_Test.ts_LoopTest.ts_StopTest.clock_timed_interrupt.expired(6.0E10)  && ((NONE == NONE && S0 == S0) || (NONE == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_STARTED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == NONE && S0 == S0) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)))))))
		{
			ts_Test.ts_LoopTest.kleeneState = KLEENE_STARTED;
			if((ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && (last_event_time.expired(6.0E10) == false  && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && ((S1 == CheckCrash && ! crashed && true ) || S1 == S1)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ! crashed && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action ) || ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == S1)))))))
			{
				if((last_event_time.expired(6.0E10) == false  && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && ((S1 == CheckCrash && ! crashed && true ) || S1 == S1)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ! crashed && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action ) || ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == S1))))))
				{
					if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && ((S1 == CheckCrash && ! crashed && true ) || S1 == S1)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ! crashed && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action ) || ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == S1)))))
					{
						if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && ((S1 == CheckCrash && ! crashed && true ) || S1 == S1)))
						{
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState = CALLED;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState = S1;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action = true;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc = 5;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time = 1;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.isStart = true;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc = 3;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra = 5;
							if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ! crashed && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action ))
							{
								
								if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.isStart){
								 initPython(ts_Test.multi_lane, ts_Test.mode);
								ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.isStart=false;
								}
								generate_action_from_state();
								update_state_from_action(pre_check);
								std::cout<<" Get Environment, Get action and update current environment "<<"\n";
								if(!crashed){
								add_new_action("control_safe");
								}else{
								add_new_action("crashed_callback");
								}
								ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action = false;
								;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState = CheckCrash;
								ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState = NONE;
								exec = 1;
							
							}else if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == S1)
							{
								
								// vehicle_env=initializeEnv();
								if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.isStart){
								 initPython(ts_Test.multi_lane, ts_Test.mode);
								ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.isStart=false;
								}else{
								generate_first_env();
								}
								generate_action_from_state();
								update_state_from_action(pre_check);
								std::cout<<" Get Environment, Get action and update current environment "<<"\n";
								if(!crashed){
								add_new_action("control_safe");
								}else{
								add_new_action("crashed_callback");
								}
								
								;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState = CheckCrash;
								ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState = NONE;
								exec = 1;
							
							}
						
						}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ! crashed && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action ) || ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == S1)))
						{
							if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ! crashed && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action ))
							{
								
								if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.isStart){
								 initPython(ts_Test.multi_lane, ts_Test.mode);
								ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.isStart=false;
								}
								generate_action_from_state();
								update_state_from_action(pre_check);
								std::cout<<" Get Environment, Get action and update current environment "<<"\n";
								if(!crashed){
								add_new_action("control_safe");
								}else{
								add_new_action("crashed_callback");
								}
								ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action = false;
								;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState = CheckCrash;
								ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState = NONE;
								exec = 1;
							
							}else if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == S1)
							{
								
								// vehicle_env=initializeEnv();
								if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.isStart){
								 initPython(ts_Test.multi_lane, ts_Test.mode);
								ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.isStart=false;
								}else{
								generate_first_env();
								}
								generate_action_from_state();
								update_state_from_action(pre_check);
								std::cout<<" Get Environment, Get action and update current environment "<<"\n";
								if(!crashed){
								add_new_action("control_safe");
								}else{
								add_new_action("crashed_callback");
								}
								
								;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState = CheckCrash;
								ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState = NONE;
								exec = 1;
							
							}
						
						}
					
					}
				
				}
				
				if(crashed){ts_Test.i++;stop_test();std::cout<<" ASTD Action "<<"\n";}
				;
			}else if((ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (ts_Test.ts_LoopTest.ts_StopTest.clock_timed_interrupt.expired(6.0E10)  && ((NONE == NONE && S0 == S0) || (NONE == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)))) || (GUARD_NOTSTARTED == GUARD_STARTED && ((NONE == NONE && S0 == S0) || (NONE == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0))))))
			{
				ts_Test.i++;stop_test();add_new_action("empty");std::cout<<"Interrupt Action "<<"\n";ts_Test.ts_LoopTest.ts_StopTest.interruptState = INT_SECOND;
				ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState = GUARD_NOTSTARTED;
				ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState = NONE;
				if((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_NOTSTARTED && (ts_Test.ts_LoopTest.ts_StopTest.clock_timed_interrupt.expired(6.0E10)  && ((NONE == NONE && S0 == S0) || (NONE == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)))))
				{
					ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState = GUARD_STARTED;
					if((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == NONE && S0 == S0))
					{
						ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState = LEFT;
						ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState = S0;
						if(ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)
						{
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState = StopTestInstance;
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState = S0;
							exec = 1;
						
						}
					
					}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0))
					{
						if(ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)
						{
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState = StopTestInstance;
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState = S0;
							exec = 1;
						
						}
					
					}
				
				}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_STARTED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == NONE && S0 == S0) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0))))
				{
					if((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == NONE && S0 == S0))
					{
						ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState = LEFT;
						ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState = S0;
						if(ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)
						{
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState = StopTestInstance;
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState = S0;
							exec = 1;
						
						}
					
					}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0))
					{
						if(ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)
						{
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState = StopTestInstance;
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState = S0;
							exec = 1;
						
						}
					
					}
				
				}
				
				if(crashed){ts_Test.i++;stop_test();std::cout<<" ASTD Action "<<"\n";}
				;
			}else if((ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_SECOND && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_NOTSTARTED && (ts_Test.ts_LoopTest.ts_StopTest.clock_timed_interrupt.expired(6.0E10)  && ((NONE == NONE && S0 == S0) || (NONE == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_STARTED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == NONE && S0 == S0) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0))))))
			{
				if((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_NOTSTARTED && (ts_Test.ts_LoopTest.ts_StopTest.clock_timed_interrupt.expired(6.0E10)  && ((NONE == NONE && S0 == S0) || (NONE == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)))))
				{
					ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState = GUARD_STARTED;
					if((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == NONE && S0 == S0))
					{
						ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState = LEFT;
						ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState = S0;
						if(ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)
						{
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState = StopTestInstance;
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState = S0;
							exec = 1;
						
						}
					
					}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0))
					{
						if(ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)
						{
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState = StopTestInstance;
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState = S0;
							exec = 1;
						
						}
					
					}
				
				}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_STARTED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == NONE && S0 == S0) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0))))
				{
					if((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == NONE && S0 == S0))
					{
						ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState = LEFT;
						ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState = S0;
						if(ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)
						{
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState = StopTestInstance;
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState = S0;
							exec = 1;
						
						}
					
					}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == LEFT && ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0))
					{
						if(ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState == S0)
						{
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.autState = StopTestInstance;
							ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState = S0;
							exec = 1;
						
						}
					
					}
				
				}
				
				if(crashed){ts_Test.i++;stop_test();std::cout<<" ASTD Action "<<"\n";}
				;
			}
		
		}
	
	}
	if(exec == 1)
	{
		// last_event_time = exec_start;
	
	}
	return exec;

}

int    safe()
{
	int  exec = 0;
	exec_start.reset_clock();
	if((ts_Test.i < 50  && (((((ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && (((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (0 && 0)) || (GUARD_NOTSTARTED == GUARD_STARTED && (0 && 0))) || ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (GUARD_NOTSTARTED == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end())))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (0 && 0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && (0 && 0)))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState) !=shallow_final_StopController.end()))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && (((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (0 && 0)) || (GUARD_NOTSTARTED == GUARD_STARTED && (0 && 0))) || ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (GUARD_NOTSTARTED == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end())))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (0 && 0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && (0 && 0)))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState) !=shallow_final_StopController.end()))))))) || (ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_SECOND && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_NOTSTARTED && ((NONE == NONE && (std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end() || std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), S0) !=shallow_final_choice2StopTest_guard.end())) || (NONE == LEFT && std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end()) || (NONE == RIGHT && std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice2StopTest_guard.autState) !=shallow_final_choice2StopTest_guard.end()))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_STARTED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == NONE && (std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end() || std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), S0) !=shallow_final_choice2StopTest_guard.end())) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == LEFT && std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end()) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == RIGHT && std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice2StopTest_guard.autState) !=shallow_final_choice2StopTest_guard.end())))))) || KLEENE_NOTSTARTED == ts_Test.ts_LoopTest.kleeneState) && (INT_FIRST == INT_FIRST && (last_event_time.expired(6.0E10) == false  && (ControllerLoopCall == ControllerLoopCall && ((NOTCALLED == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))) || (NOTCALLED == CALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))))))))))) || (ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && (last_event_time.expired(6.0E10) == false  && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))))))))))
	{
		if(((((ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && (((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (0 && 0)) || (GUARD_NOTSTARTED == GUARD_STARTED && (0 && 0))) || ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (GUARD_NOTSTARTED == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end())))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (0 && 0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && (0 && 0)))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState) !=shallow_final_StopController.end()))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && (((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (0 && 0)) || (GUARD_NOTSTARTED == GUARD_STARTED && (0 && 0))) || ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (GUARD_NOTSTARTED == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end())))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (0 && 0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && (0 && 0)))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState) !=shallow_final_StopController.end()))))))) || (ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_SECOND && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_NOTSTARTED && ((NONE == NONE && (std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end() || std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), S0) !=shallow_final_choice2StopTest_guard.end())) || (NONE == LEFT && std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end()) || (NONE == RIGHT && std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice2StopTest_guard.autState) !=shallow_final_choice2StopTest_guard.end()))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_STARTED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == NONE && (std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end() || std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), S0) !=shallow_final_choice2StopTest_guard.end())) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == LEFT && std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end()) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == RIGHT && std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice2StopTest_guard.autState) !=shallow_final_choice2StopTest_guard.end())))))) || KLEENE_NOTSTARTED == ts_Test.ts_LoopTest.kleeneState) && (INT_FIRST == INT_FIRST && (last_event_time.expired(6.0E10) == false  && (ControllerLoopCall == ControllerLoopCall && ((NOTCALLED == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))) || (NOTCALLED == CALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))))))))))))
		{
			ts_Test.ts_LoopTest.kleeneState = KLEENE_STARTED;
			ts_Test.ts_LoopTest.ts_StopTest.interruptState = INT_FIRST;
			ts_Test.ts_LoopTest.ts_StopTest.clock_timed_interrupt.reset_clock(last_event_time);
			ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState = ControllerLoopCall;
			ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState = NOTCALLED;
			if((ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && (last_event_time.expired(6.0E10) == false  && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))))))))
			{
				if((last_event_time.expired(6.0E10) == false  && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))))))))))
				{
					if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))))))
					{
						if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))))
						{
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState = CALLED;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState = S1;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action = true;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc = 5;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time = 1;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.isStart = true;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc = 3;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra = 5;
							if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))))))
							{
								if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))))
								{
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState = LEFT;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_NOTSTARTED;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock(last_event_time);
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.right_clock_ControllerUpdateAction.reset_clock(last_event_time);
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S0;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState = S0;
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												 std::cout<<" Safe Action "<<"\n";
												if(pre_check){
												validate_safe_action();
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												 std::cout<<" Safe Action "<<"\n";
												if(pre_check){
												validate_safe_action();
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}
								
								}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))))
								{
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												 std::cout<<" Safe Action "<<"\n";
												if(pre_check){
												validate_safe_action();
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												 std::cout<<" Safe Action "<<"\n";
												if(pre_check){
												validate_safe_action();
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}
								
								}
							
							}
						
						}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))))
						{
							if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))))))
							{
								if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))))
								{
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState = LEFT;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_NOTSTARTED;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock(last_event_time);
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.right_clock_ControllerUpdateAction.reset_clock(last_event_time);
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S0;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState = S0;
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												 std::cout<<" Safe Action "<<"\n";
												if(pre_check){
												validate_safe_action();
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												 std::cout<<" Safe Action "<<"\n";
												if(pre_check){
												validate_safe_action();
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}
								
								}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))))
								{
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												 std::cout<<" Safe Action "<<"\n";
												if(pre_check){
												validate_safe_action();
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												 std::cout<<" Safe Action "<<"\n";
												if(pre_check){
												validate_safe_action();
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}
								
								}
							
							}
						
						}
					
					}
				
				}
				
				if(crashed){ts_Test.i++;stop_test();std::cout<<" ASTD Action "<<"\n";}
				;
			}
		
		}else if((ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && (last_event_time.expired(6.0E10) == false  && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))))))))
		{
			ts_Test.ts_LoopTest.kleeneState = KLEENE_STARTED;
			if((ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && (last_event_time.expired(6.0E10) == false  && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))))))))
			{
				if((last_event_time.expired(6.0E10) == false  && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))))))))))
				{
					if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))))))
					{
						if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))))
						{
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState = CALLED;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState = S1;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action = true;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc = 5;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time = 1;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.isStart = true;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc = 3;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra = 5;
							if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))))))
							{
								if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))))
								{
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState = LEFT;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_NOTSTARTED;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock(last_event_time);
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.right_clock_ControllerUpdateAction.reset_clock(last_event_time);
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S0;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState = S0;
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												 std::cout<<" Safe Action "<<"\n";
												if(pre_check){
												validate_safe_action();
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												 std::cout<<" Safe Action "<<"\n";
												if(pre_check){
												validate_safe_action();
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}
								
								}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))))
								{
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												 std::cout<<" Safe Action "<<"\n";
												if(pre_check){
												validate_safe_action();
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												 std::cout<<" Safe Action "<<"\n";
												if(pre_check){
												validate_safe_action();
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}
								
								}
							
							}
						
						}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))))
						{
							if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))))))
							{
								if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))))
								{
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState = LEFT;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_NOTSTARTED;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock(last_event_time);
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.right_clock_ControllerUpdateAction.reset_clock(last_event_time);
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S0;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState = S0;
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												 std::cout<<" Safe Action "<<"\n";
												if(pre_check){
												validate_safe_action();
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												 std::cout<<" Safe Action "<<"\n";
												if(pre_check){
												validate_safe_action();
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}
								
								}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))))
								{
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												 std::cout<<" Safe Action "<<"\n";
												if(pre_check){
												validate_safe_action();
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												 std::cout<<" Safe Action "<<"\n";
												if(pre_check){
												validate_safe_action();
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}
								
								}
							
							}
						
						}
					
					}
				
				}
				
				if(crashed){ts_Test.i++;stop_test();std::cout<<" ASTD Action "<<"\n";}
				;
			}
		
		}
	
	}
	if(exec == 1)
	{
		// last_event_time = exec_start;
	
	}
	return exec;

}

int    crashed_callback()
{
	int  exec = 0;
	exec_start.reset_clock();
	if((ts_Test.i < 50  && (((((ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && (((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (0 && 0)) || (GUARD_NOTSTARTED == GUARD_STARTED && (0 && 0))) || ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (GUARD_NOTSTARTED == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end())))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (0 && 0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && (0 && 0)))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState) !=shallow_final_StopController.end()))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && (((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (0 && 0)) || (GUARD_NOTSTARTED == GUARD_STARTED && (0 && 0))) || ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (GUARD_NOTSTARTED == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end())))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (0 && 0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && (0 && 0)))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState) !=shallow_final_StopController.end()))))))) || (ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_SECOND && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_NOTSTARTED && ((NONE == NONE && (std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end() || std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), S0) !=shallow_final_choice2StopTest_guard.end())) || (NONE == LEFT && std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end()) || (NONE == RIGHT && std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice2StopTest_guard.autState) !=shallow_final_choice2StopTest_guard.end()))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_STARTED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == NONE && (std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end() || std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), S0) !=shallow_final_choice2StopTest_guard.end())) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == LEFT && std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end()) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == RIGHT && std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice2StopTest_guard.autState) !=shallow_final_choice2StopTest_guard.end())))))) || KLEENE_NOTSTARTED == ts_Test.ts_LoopTest.kleeneState) && (INT_FIRST == INT_FIRST && (last_event_time.expired(6.0E10) == false  && (ControllerLoopCall == ControllerLoopCall && ((NOTCALLED == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)))))) || (NOTCALLED == CALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0))))))))))) || (ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && (last_event_time.expired(6.0E10) == false  && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)))))))))))))
	{
		if(((((ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && (((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (0 && 0)) || (GUARD_NOTSTARTED == GUARD_STARTED && (0 && 0))) || ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (GUARD_NOTSTARTED == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end())))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (0 && 0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && (0 && 0)))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState) !=shallow_final_StopController.end()))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && (((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (0 && 0)) || (GUARD_NOTSTARTED == GUARD_STARTED && (0 && 0))) || ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (GUARD_NOTSTARTED == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end())))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (0 && 0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && (0 && 0)))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState) !=shallow_final_StopController.end()))))))) || (ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_SECOND && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_NOTSTARTED && ((NONE == NONE && (std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end() || std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), S0) !=shallow_final_choice2StopTest_guard.end())) || (NONE == LEFT && std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end()) || (NONE == RIGHT && std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice2StopTest_guard.autState) !=shallow_final_choice2StopTest_guard.end()))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_STARTED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == NONE && (std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end() || std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), S0) !=shallow_final_choice2StopTest_guard.end())) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == LEFT && std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end()) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == RIGHT && std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice2StopTest_guard.autState) !=shallow_final_choice2StopTest_guard.end())))))) || KLEENE_NOTSTARTED == ts_Test.ts_LoopTest.kleeneState) && (INT_FIRST == INT_FIRST && (last_event_time.expired(6.0E10) == false  && (ControllerLoopCall == ControllerLoopCall && ((NOTCALLED == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)))))) || (NOTCALLED == CALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0))))))))))))
		{
			ts_Test.ts_LoopTest.kleeneState = KLEENE_STARTED;
			ts_Test.ts_LoopTest.ts_StopTest.interruptState = INT_FIRST;
			ts_Test.ts_LoopTest.ts_StopTest.clock_timed_interrupt.reset_clock(last_event_time);
			ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState = ControllerLoopCall;
			ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState = NOTCALLED;
			if((ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && (last_event_time.expired(6.0E10) == false  && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)))))))))))
			{
				if((last_event_time.expired(6.0E10) == false  && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0))))))))))
				{
					if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)))))))))
					{
						if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)))))))
						{
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState = CALLED;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState = S1;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action = true;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc = 5;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time = 1;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.isStart = true;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc = 3;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra = 5;
							if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0))))))
							{
								if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))))
								{
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState = RIGHT;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState = GUARD_NOTSTARTED;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState = S0;
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)
										{
											crashed=false;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState = S1;
											exec = 1;
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)
										{
											crashed=false;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState = S1;
											exec = 1;
										
										}
									
									}
								
								}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0))))
								{
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)
										{
											crashed=false;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState = S1;
											exec = 1;
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)
										{
											crashed=false;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState = S1;
											exec = 1;
										
										}
									
									}
								
								}
							
							}
						
						}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)))))))
						{
							if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0))))))
							{
								if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))))
								{
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState = RIGHT;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState = GUARD_NOTSTARTED;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState = S0;
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)
										{
											crashed=false;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState = S1;
											exec = 1;
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)
										{
											crashed=false;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState = S1;
											exec = 1;
										
										}
									
									}
								
								}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0))))
								{
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)
										{
											crashed=false;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState = S1;
											exec = 1;
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)
										{
											crashed=false;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState = S1;
											exec = 1;
										
										}
									
									}
								
								}
							
							}
						
						}
					
					}
				
				}
				
				if(crashed){ts_Test.i++;stop_test();std::cout<<" ASTD Action "<<"\n";}
				;
			}
		
		}else if((ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && (last_event_time.expired(6.0E10) == false  && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)))))))))))
		{
			ts_Test.ts_LoopTest.kleeneState = KLEENE_STARTED;
			if((ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && (last_event_time.expired(6.0E10) == false  && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)))))))))))
			{
				if((last_event_time.expired(6.0E10) == false  && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0))))))))))
				{
					if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)))))))))
					{
						if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)))))))
						{
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState = CALLED;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState = S1;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action = true;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc = 5;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time = 1;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.isStart = true;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc = 3;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra = 5;
							if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0))))))
							{
								if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))))
								{
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState = RIGHT;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState = GUARD_NOTSTARTED;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState = S0;
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)
										{
											crashed=false;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState = S1;
											exec = 1;
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)
										{
											crashed=false;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState = S1;
											exec = 1;
										
										}
									
									}
								
								}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0))))
								{
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)
										{
											crashed=false;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState = S1;
											exec = 1;
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)
										{
											crashed=false;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState = S1;
											exec = 1;
										
										}
									
									}
								
								}
							
							}
						
						}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)))))))
						{
							if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0))))))
							{
								if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))))
								{
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState = RIGHT;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState = GUARD_NOTSTARTED;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState = S0;
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)
										{
											crashed=false;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState = S1;
											exec = 1;
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)
										{
											crashed=false;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState = S1;
											exec = 1;
										
										}
									
									}
								
								}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0))))
								{
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && (crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)
										{
											crashed=false;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState = S1;
											exec = 1;
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState == S0)
										{
											crashed=false;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState = S1;
											exec = 1;
										
										}
									
									}
								
								}
							
							}
						
						}
					
					}
				
				}
				
				if(crashed){ts_Test.i++;stop_test();std::cout<<" ASTD Action "<<"\n";}
				;
			}
		
		}
	
	}
	if(exec == 1)
	{
		// last_event_time = exec_start;
	
	}
	return exec;

}

int    unsafe()
{
	int  exec = 0;
	exec_start.reset_clock();
	if((ts_Test.i < 50  && (((((ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && (((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (0 && 0)) || (GUARD_NOTSTARTED == GUARD_STARTED && (0 && 0))) || ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (GUARD_NOTSTARTED == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end())))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (0 && 0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && (0 && 0)))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState) !=shallow_final_StopController.end()))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && (((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (0 && 0)) || (GUARD_NOTSTARTED == GUARD_STARTED && (0 && 0))) || ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (GUARD_NOTSTARTED == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end())))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (0 && 0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && (0 && 0)))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState) !=shallow_final_StopController.end()))))))) || (ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_SECOND && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_NOTSTARTED && ((NONE == NONE && (std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end() || std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), S0) !=shallow_final_choice2StopTest_guard.end())) || (NONE == LEFT && std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end()) || (NONE == RIGHT && std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice2StopTest_guard.autState) !=shallow_final_choice2StopTest_guard.end()))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_STARTED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == NONE && (std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end() || std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), S0) !=shallow_final_choice2StopTest_guard.end())) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == LEFT && std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end()) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == RIGHT && std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice2StopTest_guard.autState) !=shallow_final_choice2StopTest_guard.end())))))) || KLEENE_NOTSTARTED == ts_Test.ts_LoopTest.kleeneState) && (INT_FIRST == INT_FIRST && (last_event_time.expired(6.0E10) == false  && (ControllerLoopCall == ControllerLoopCall && ((NOTCALLED == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))) || (NOTCALLED == CALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))))))))))) || (ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && (last_event_time.expired(6.0E10) == false  && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))))))))))
	{
		if(((((ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && (((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (0 && 0)) || (GUARD_NOTSTARTED == GUARD_STARTED && (0 && 0))) || ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (GUARD_NOTSTARTED == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end())))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (0 && 0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && (0 && 0)))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState) !=shallow_final_StopController.end()))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && (((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (0 && 0)) || (GUARD_NOTSTARTED == GUARD_STARTED && (0 && 0))) || ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (GUARD_NOTSTARTED == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end())))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (0 && 0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && (0 && 0)))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState) !=shallow_final_StopController.end()))))))) || (ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_SECOND && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_NOTSTARTED && ((NONE == NONE && (std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end() || std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), S0) !=shallow_final_choice2StopTest_guard.end())) || (NONE == LEFT && std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end()) || (NONE == RIGHT && std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice2StopTest_guard.autState) !=shallow_final_choice2StopTest_guard.end()))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_STARTED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == NONE && (std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end() || std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), S0) !=shallow_final_choice2StopTest_guard.end())) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == LEFT && std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end()) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == RIGHT && std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice2StopTest_guard.autState) !=shallow_final_choice2StopTest_guard.end())))))) || KLEENE_NOTSTARTED == ts_Test.ts_LoopTest.kleeneState) && (INT_FIRST == INT_FIRST && (last_event_time.expired(6.0E10) == false  && (ControllerLoopCall == ControllerLoopCall && ((NOTCALLED == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))) || (NOTCALLED == CALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))))))))))))
		{
			ts_Test.ts_LoopTest.kleeneState = KLEENE_STARTED;
			ts_Test.ts_LoopTest.ts_StopTest.interruptState = INT_FIRST;
			ts_Test.ts_LoopTest.ts_StopTest.clock_timed_interrupt.reset_clock(last_event_time);
			ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState = ControllerLoopCall;
			ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState = NOTCALLED;
			if((ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && (last_event_time.expired(6.0E10) == false  && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))))))))
			{
				if((last_event_time.expired(6.0E10) == false  && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))))))))))
				{
					if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))))))
					{
						if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))))
						{
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState = CALLED;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState = S1;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action = true;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc = 5;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time = 1;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.isStart = true;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc = 3;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra = 5;
							if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))))))
							{
								if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))))
								{
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState = LEFT;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_NOTSTARTED;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock(last_event_time);
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.right_clock_ControllerUpdateAction.reset_clock(last_event_time);
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S0;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState = S0;
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												std::cout<<" UnSafe Action "<<"\n";
												if(!pre_check){
												continues_braking_until_safe_distance (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												if(crashed){add_new_action("crashed_callback");
												}else{ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action=true;}
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S2;
												exec = 1;
											
											}
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												std::cout<<" UnSafe Action "<<"\n";
												if(!pre_check){
												continues_braking_until_safe_distance (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												if(crashed){add_new_action("crashed_callback");
												}else{ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action=true;}
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S2;
												exec = 1;
											
											}
										
										}
									
									}
								
								}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))))
								{
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												std::cout<<" UnSafe Action "<<"\n";
												if(!pre_check){
												continues_braking_until_safe_distance (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												if(crashed){add_new_action("crashed_callback");
												}else{ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action=true;}
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S2;
												exec = 1;
											
											}
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												std::cout<<" UnSafe Action "<<"\n";
												if(!pre_check){
												continues_braking_until_safe_distance (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												if(crashed){add_new_action("crashed_callback");
												}else{ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action=true;}
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S2;
												exec = 1;
											
											}
										
										}
									
									}
								
								}
							
							}
						
						}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))))
						{
							if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))))))
							{
								if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))))
								{
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState = LEFT;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_NOTSTARTED;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock(last_event_time);
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.right_clock_ControllerUpdateAction.reset_clock(last_event_time);
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S0;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState = S0;
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												std::cout<<" UnSafe Action "<<"\n";
												if(!pre_check){
												continues_braking_until_safe_distance (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												if(crashed){add_new_action("crashed_callback");
												}else{ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action=true;}
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S2;
												exec = 1;
											
											}
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												std::cout<<" UnSafe Action "<<"\n";
												if(!pre_check){
												continues_braking_until_safe_distance (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												if(crashed){add_new_action("crashed_callback");
												}else{ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action=true;}
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S2;
												exec = 1;
											
											}
										
										}
									
									}
								
								}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))))
								{
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												std::cout<<" UnSafe Action "<<"\n";
												if(!pre_check){
												continues_braking_until_safe_distance (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												if(crashed){add_new_action("crashed_callback");
												}else{ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action=true;}
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S2;
												exec = 1;
											
											}
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												std::cout<<" UnSafe Action "<<"\n";
												if(!pre_check){
												continues_braking_until_safe_distance (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												if(crashed){add_new_action("crashed_callback");
												}else{ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action=true;}
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S2;
												exec = 1;
											
											}
										
										}
									
									}
								
								}
							
							}
						
						}
					
					}
				
				}
				
				if(crashed){ts_Test.i++;stop_test();std::cout<<" ASTD Action "<<"\n";}
				;
			}
		
		}else if((ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && (last_event_time.expired(6.0E10) == false  && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))))))))
		{
			ts_Test.ts_LoopTest.kleeneState = KLEENE_STARTED;
			if((ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && (last_event_time.expired(6.0E10) == false  && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))))))))
			{
				if((last_event_time.expired(6.0E10) == false  && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))))))))))
				{
					if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))))))
					{
						if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))))
						{
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState = CALLED;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState = S1;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action = true;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc = 5;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time = 1;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.isStart = true;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc = 3;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra = 5;
							if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))))))
							{
								if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))))
								{
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState = LEFT;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_NOTSTARTED;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock(last_event_time);
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.right_clock_ControllerUpdateAction.reset_clock(last_event_time);
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S0;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState = S0;
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												std::cout<<" UnSafe Action "<<"\n";
												if(!pre_check){
												continues_braking_until_safe_distance (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												if(crashed){add_new_action("crashed_callback");
												}else{ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action=true;}
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S2;
												exec = 1;
											
											}
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												std::cout<<" UnSafe Action "<<"\n";
												if(!pre_check){
												continues_braking_until_safe_distance (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												if(crashed){add_new_action("crashed_callback");
												}else{ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action=true;}
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S2;
												exec = 1;
											
											}
										
										}
									
									}
								
								}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))))
								{
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												std::cout<<" UnSafe Action "<<"\n";
												if(!pre_check){
												continues_braking_until_safe_distance (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												if(crashed){add_new_action("crashed_callback");
												}else{ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action=true;}
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S2;
												exec = 1;
											
											}
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												std::cout<<" UnSafe Action "<<"\n";
												if(!pre_check){
												continues_braking_until_safe_distance (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												if(crashed){add_new_action("crashed_callback");
												}else{ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action=true;}
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S2;
												exec = 1;
											
											}
										
										}
									
									}
								
								}
							
							}
						
						}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)))))))
						{
							if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))))))
							{
								if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))))
								{
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState = LEFT;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_NOTSTARTED;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock(last_event_time);
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.right_clock_ControllerUpdateAction.reset_clock(last_event_time);
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S0;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState = S0;
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												std::cout<<" UnSafe Action "<<"\n";
												if(!pre_check){
												continues_braking_until_safe_distance (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												if(crashed){add_new_action("crashed_callback");
												}else{ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action=true;}
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S2;
												exec = 1;
											
											}
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												std::cout<<" UnSafe Action "<<"\n";
												if(!pre_check){
												continues_braking_until_safe_distance (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												if(crashed){add_new_action("crashed_callback");
												}else{ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action=true;}
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S2;
												exec = 1;
											
											}
										
										}
									
									}
								
								}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))))
								{
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												std::cout<<" UnSafe Action "<<"\n";
												if(!pre_check){
												continues_braking_until_safe_distance (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												if(crashed){add_new_action("crashed_callback");
												}else{ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action=true;}
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S2;
												exec = 1;
											
											}
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState == S0)
											{
												
												std::cout<<" UnSafe Action "<<"\n";
												if(!pre_check){
												continues_braking_until_safe_distance (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												if(crashed){add_new_action("crashed_callback");
												}else{ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action=true;}
												}
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S2;
												exec = 1;
											
											}
										
										}
									
									}
								
								}
							
							}
						
						}
					
					}
				
				}
				
				if(crashed){ts_Test.i++;stop_test();std::cout<<" ASTD Action "<<"\n";}
				;
			}
		
		}
	
	}
	if(exec == 1)
	{
		// last_event_time = exec_start;
	
	}
	return exec;

}

int    control_safe()
{
	int  exec = 0;
	exec_start.reset_clock();
	if((ts_Test.i < 50  && (((((ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && (((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (0 && 0)) || (GUARD_NOTSTARTED == GUARD_STARTED && (0 && 0))) || ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (GUARD_NOTSTARTED == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end())))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (0 && 0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && (0 && 0)))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState) !=shallow_final_StopController.end()))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && (((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (0 && 0)) || (GUARD_NOTSTARTED == GUARD_STARTED && (0 && 0))) || ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (GUARD_NOTSTARTED == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end())))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (0 && 0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && (0 && 0)))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState) !=shallow_final_StopController.end()))))))) || (ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_SECOND && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_NOTSTARTED && ((NONE == NONE && (std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end() || std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), S0) !=shallow_final_choice2StopTest_guard.end())) || (NONE == LEFT && std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end()) || (NONE == RIGHT && std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice2StopTest_guard.autState) !=shallow_final_choice2StopTest_guard.end()))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_STARTED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == NONE && (std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end() || std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), S0) !=shallow_final_choice2StopTest_guard.end())) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == LEFT && std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end()) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == RIGHT && std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice2StopTest_guard.autState) !=shallow_final_choice2StopTest_guard.end())))))) || KLEENE_NOTSTARTED == ts_Test.ts_LoopTest.kleeneState) && (INT_FIRST == INT_FIRST && (last_event_time.expired(6.0E10) == false  && (ControllerLoopCall == ControllerLoopCall && ((NOTCALLED == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)))))) || (NOTCALLED == CALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0))))))))))) || (ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && (last_event_time.expired(6.0E10) == false  && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)))))))))))))
	{
		if(((((ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && (((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (0 && 0)) || (GUARD_NOTSTARTED == GUARD_STARTED && (0 && 0))) || ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (GUARD_NOTSTARTED == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end())))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (0 && 0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && (0 && 0)))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState) !=shallow_final_StopController.end()))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && (((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (0 && 0)) || (GUARD_NOTSTARTED == GUARD_STARTED && (0 && 0))) || ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (GUARD_NOTSTARTED == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end())))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (0 && 0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && (0 && 0)))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == RIGHT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_NOTSTARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), S0) !=shallow_final_StopController.end()) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.guardState == GUARD_STARTED && std::find(shallow_final_StopController.begin(), shallow_final_StopController.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_WithCrash.ts_StopController.autState) !=shallow_final_StopController.end()))))))) || (ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_SECOND && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_NOTSTARTED && ((NONE == NONE && (std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end() || std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), S0) !=shallow_final_choice2StopTest_guard.end())) || (NONE == LEFT && std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end()) || (NONE == RIGHT && std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice2StopTest_guard.autState) !=shallow_final_choice2StopTest_guard.end()))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.guardState == GUARD_STARTED && ((ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == NONE && (std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end() || std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), S0) !=shallow_final_choice2StopTest_guard.end())) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == LEFT && std::find(shallow_final_StopTestInstance.begin(), shallow_final_StopTestInstance.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice_1choiceStopTest_guard.ts_StopTestInstance.autState) !=shallow_final_StopTestInstance.end()) || (ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.choiceState == RIGHT && std::find(shallow_final_choice2StopTest_guard.begin(), shallow_final_choice2StopTest_guard.end(), ts_Test.ts_LoopTest.ts_StopTest.ts_guardStopTest.ts_choiceStopTest_guard.ts_choice2StopTest_guard.autState) !=shallow_final_choice2StopTest_guard.end())))))) || KLEENE_NOTSTARTED == ts_Test.ts_LoopTest.kleeneState) && (INT_FIRST == INT_FIRST && (last_event_time.expired(6.0E10) == false  && (ControllerLoopCall == ControllerLoopCall && ((NOTCALLED == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)))))) || (NOTCALLED == CALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0))))))))))))
		{
			ts_Test.ts_LoopTest.kleeneState = KLEENE_STARTED;
			ts_Test.ts_LoopTest.ts_StopTest.interruptState = INT_FIRST;
			ts_Test.ts_LoopTest.ts_StopTest.clock_timed_interrupt.reset_clock(last_event_time);
			ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState = ControllerLoopCall;
			ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState = NOTCALLED;
			if((ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && (last_event_time.expired(6.0E10) == false  && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)))))))))))
			{
				if((last_event_time.expired(6.0E10) == false  && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0))))))))))
				{
					if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)))))))))
					{
						if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)))))))
						{
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState = CALLED;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState = S1;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action = true;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc = 5;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time = 1;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.isStart = true;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc = 3;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra = 5;
							if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0))))))
							{
								if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))))
								{
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState = LEFT;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_NOTSTARTED;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock(last_event_time);
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.right_clock_ControllerUpdateAction.reset_clock(last_event_time);
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S0;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState = S0;
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
											{
												
												ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action = control_safety(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc,ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												std::cout<<" Action Validation"<<"\n";
												if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action){add_new_action("safe");
												}else {add_new_action("unsafe");
												}
												
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.right_clock_ControllerUpdateAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
											{
												
												ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action = control_safety(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc,ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												std::cout<<" Action Validation"<<"\n";
												if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action){add_new_action("safe");
												}else {add_new_action("unsafe");
												}
												
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.right_clock_ControllerUpdateAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}
								
								}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0))))
								{
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
											{
												
												ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action = control_safety(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc,ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												std::cout<<" Action Validation"<<"\n";
												if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action){add_new_action("safe");
												}else {add_new_action("unsafe");
												}
												
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.right_clock_ControllerUpdateAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
											{
												
												ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action = control_safety(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc,ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												std::cout<<" Action Validation"<<"\n";
												if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action){add_new_action("safe");
												}else {add_new_action("unsafe");
												}
												
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.right_clock_ControllerUpdateAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}
								
								}
							
							}
						
						}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)))))))
						{
							if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0))))))
							{
								if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))))
								{
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState = LEFT;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_NOTSTARTED;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock(last_event_time);
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.right_clock_ControllerUpdateAction.reset_clock(last_event_time);
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S0;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState = S0;
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
											{
												
												ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action = control_safety(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc,ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												std::cout<<" Action Validation"<<"\n";
												if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action){add_new_action("safe");
												}else {add_new_action("unsafe");
												}
												
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.right_clock_ControllerUpdateAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
											{
												
												ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action = control_safety(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc,ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												std::cout<<" Action Validation"<<"\n";
												if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action){add_new_action("safe");
												}else {add_new_action("unsafe");
												}
												
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.right_clock_ControllerUpdateAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}
								
								}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0))))
								{
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
											{
												
												ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action = control_safety(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc,ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												std::cout<<" Action Validation"<<"\n";
												if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action){add_new_action("safe");
												}else {add_new_action("unsafe");
												}
												
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.right_clock_ControllerUpdateAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
											{
												
												ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action = control_safety(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc,ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												std::cout<<" Action Validation"<<"\n";
												if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action){add_new_action("safe");
												}else {add_new_action("unsafe");
												}
												
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.right_clock_ControllerUpdateAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}
								
								}
							
							}
						
						}
					
					}
				
				}
				
				if(crashed){ts_Test.i++;stop_test();std::cout<<" ASTD Action "<<"\n";}
				;
			}
		
		}else if((ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && (last_event_time.expired(6.0E10) == false  && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)))))))))))
		{
			ts_Test.ts_LoopTest.kleeneState = KLEENE_STARTED;
			if((ts_Test.ts_LoopTest.ts_StopTest.interruptState == INT_FIRST && (last_event_time.expired(6.0E10) == false  && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)))))))))))
			{
				if((last_event_time.expired(6.0E10) == false  && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0))))))))))
				{
					if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState == ControllerLoopCall && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)))))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)))))))))
					{
						if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == NOTCALLED && (S1 == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)))))))
						{
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState = CALLED;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState = S1;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action = true;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc = 5;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time = 1;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.isStart = true;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc = 3;
							ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra = 5;
							if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0))))))
							{
								if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))))
								{
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState = LEFT;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_NOTSTARTED;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock(last_event_time);
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.right_clock_ControllerUpdateAction.reset_clock(last_event_time);
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S0;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState = S0;
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
											{
												
												ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action = control_safety(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc,ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												std::cout<<" Action Validation"<<"\n";
												if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action){add_new_action("safe");
												}else {add_new_action("unsafe");
												}
												
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.right_clock_ControllerUpdateAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
											{
												
												ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action = control_safety(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc,ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												std::cout<<" Action Validation"<<"\n";
												if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action){add_new_action("safe");
												}else {add_new_action("unsafe");
												}
												
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.right_clock_ControllerUpdateAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}
								
								}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0))))
								{
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
											{
												
												ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action = control_safety(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc,ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												std::cout<<" Action Validation"<<"\n";
												if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action){add_new_action("safe");
												}else {add_new_action("unsafe");
												}
												
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.right_clock_ControllerUpdateAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
											{
												
												ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action = control_safety(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc,ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												std::cout<<" Action Validation"<<"\n";
												if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action){add_new_action("safe");
												}else {add_new_action("unsafe");
												}
												
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.right_clock_ControllerUpdateAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}
								
								}
							
							}
						
						}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState == CALLED && (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)))))))
						{
							if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.autState == CheckCrash && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0))))))
							{
								if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == NONE && ((GUARD_NOTSTARTED == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (GUARD_NOTSTARTED == GUARD_STARTED && S0 == S0))))
								{
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState = LEFT;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_NOTSTARTED;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.left_clock_ChooseAction.reset_clock(last_event_time);
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.right_clock_ControllerUpdateAction.reset_clock(last_event_time);
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ChooseAction.autState = S0;
									ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState = S0;
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
											{
												
												ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action = control_safety(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc,ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												std::cout<<" Action Validation"<<"\n";
												if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action){add_new_action("safe");
												}else {add_new_action("unsafe");
												}
												
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.right_clock_ControllerUpdateAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
											{
												
												ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action = control_safety(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc,ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												std::cout<<" Action Validation"<<"\n";
												if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action){add_new_action("safe");
												}else {add_new_action("unsafe");
												}
												
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.right_clock_ControllerUpdateAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}
								
								}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.choiceState == LEFT && ((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)) || (ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0))))
								{
									if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_NOTSTARTED && (! crashed  && S0 == S0)))
									{
										ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState = GUARD_STARTED;
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
											{
												
												ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action = control_safety(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc,ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												std::cout<<" Action Validation"<<"\n";
												if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action){add_new_action("safe");
												}else {add_new_action("unsafe");
												}
												
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.right_clock_ControllerUpdateAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}else if((ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.guardState == GUARD_STARTED && ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0))
									{
										if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
										{
											if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState == S0)
											{
												
												ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action = control_safety(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.response_time, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_max_acc,ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.front_max_bra, ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.rear_bra_acc, pre_check);
												std::cout<<" Action Validation"<<"\n";
												if(ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.valid_action){add_new_action("safe");
												}else {add_new_action("unsafe");
												}
												
												;ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.right_clock_ControllerUpdateAction.reset_clock();ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.ts_SafetyController.ts_CheckCrash.ts_NoCrash.ts_CoreController.ts_ControllerUpdateAction.autState = S1;
												exec = 1;
											
											}
										
										}
									
									}
								
								}
							
							}
						
						}
					
					}
				
				}
				
				if(crashed){ts_Test.i++;stop_test();std::cout<<" ASTD Action "<<"\n";}
				;
			}
		
		}
	
	}
	if(exec == 1)
	{
		// last_event_time = exec_start;
	
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
		
		}else if(_evt.label.compare("crashed_callback") == 0)
		{
			if(!(crashed_callback()))
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
	ts_Test.multi_lane = multi_lane;
	ts_Test.i = 0;
	ts_Test.mode = mode;
	ts_Test.ts_LoopTest.kleeneState = KLEENE_NOTSTARTED;
	ts_Test.ts_LoopTest.ts_StopTest.interruptState = INT_FIRST;
	ts_Test.ts_LoopTest.ts_StopTest.clock_timed_interrupt.reset_clock();
	ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.autState = ControllerLoopCall;
	ts_Test.ts_LoopTest.ts_StopTest.ts_pguardStopTest.ts_LaunchTest.ts_ControllerLoopCall.callState = NOTCALLED;
	pthread_t  producers[2];
	pthread_create(& producers[0], NULL, producers_event_func, (void*) &argc);
	pthread_create(& producers[1], NULL, producers_Step_func, NULL);
	pthread_join(producers[0], NULL);
	pthread_join(producers[1], NULL);
	return 0;

}
