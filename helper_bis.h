#include <chrono>
#include <ctime>
#include <iostream>
#include <sstream>
#include <fstream>
#include <regex>
#include <vector>
#include <map>
#include <getopt.h>

/*
 * @brief Regex expresssion used to parse
 *            event labels and parameters 
 */
#define LABEL_REGEX std::string("([a-z_A-z]+[0-9]*)")
#define PARAMS_REGEX std::string(LABEL_REGEX + "\\((.*)\\)")
/*
 * @brief Safely executes events by catching exceptions
 *     
 */
#define ERROR_1 std::cout << "Event is not recognized" << "\n"
#define ERROR_2 std::cout << "Event is not executable" << "\n"
#define ERROR_5 std::cout << "Empty event label, terminating execution" << "\n"

/*
 * @brief An object used to serialize types and get the appropriated values as of
 *        primitive types or complex types.
 */
class Types {
    
 public:
    
    static std::string get_str(const std::string s) { return s; }
    static int get_int(const std::string s) { return std::stoi(s); }
    static float get_float(const std::string s) { return std::stof(s); }
    static double get_double(const std::string s) { return std::stod(s); }
    static bool get_bool(const std::string s) { 
        if(s == "0" || s == "false"){
            return false;
        }
        return true;
    }
};

/*
 * @brief channel to read events
 */
static std::ifstream channel;
static std::string filename;
std::string automatic_input;


bool multi_lane;
bool pre_check = false;

/*
 * @brief The event data structure containing its label and its parameters
 *
 */
struct Event 
{
    std::string label;
    std::vector<std::string> params;
};

void add_new_action(std::string action) 
    {
        automatic_input = action;
        std::cout<<" Update next event ==  "<< automatic_input<<"\n";
    }


class IO
{
public:
    /*
     * @brief parses event parameters and sets the event object with these params
     * @param The event object to be set
     * @param The event string to be parsed 
     * @param The input regex to be used for parsing
     * @return 
     */
    static void get_event_params(Event& e, const std::string in, const std::regex regex) 
    {
        std::smatch matches;
        if(regex_search(in, matches, regex)) 
        {
            std::stringstream ss(matches.str(2));
	    while(ss.good()) 
	    { 
	        std::string it; 
	        getline(ss, it, ',');
	        e.params.push_back(it); 
	    }
        }
  
        return;   
    }

    /*
     * @brief parses event label and returns its value
     * @param The event string to be parsed
     * @return The event label
     */
    static std::string get_event_label(const std::string in) 
    {
        std::smatch matches;
        if(regex_search(in, matches, std::regex(LABEL_REGEX)))
	    return matches.str(1);

        return ""; 
    }

    /*
     * @brief Reads event from the Input stream
     * @param The cmdline arguments 
     * @return The event object
     */

    static void configInputStream(int argc, char** argv) 
    {
        const char* const short_opts = "i:1:2:h";

        const option long_opts[] = {
            {"multi_lane", required_argument, nullptr, '1'},
            {"pre_check", required_argument, nullptr, '2'},
        };

        while (true)
        {
             const auto opt = getopt_long(argc, argv, short_opts, long_opts, nullptr);
             if (-1 == opt)
                break;

             switch(opt)
             {
                    
             case 'i':
             {
                filename = std::string(optarg); 
                channel = std::ifstream(filename);
                if(!channel)
                    std::cout << "Error opening event file !!!";
                break;
             }
             case '1': 
                 multi_lane = Types::get_bool(optarg); 
                 break;
             case '2': 
                 pre_check = Types::get_bool(optarg); 
                 break;
             
             case 'h':
             { 
                 std::cout << "This program has been compiled by cASTD." << "\n";
                 std::cout << "./my_program [-i <event file>]  [-h]" << "\n";
                 std::cout << "[OPTIONS]     								     " << "\n";
                 std::cout << "   -i <event  file>  Read an event file in Shorthand format." << "\n";
                 std::cout << "                     If an event file is not given, it runs in interactive" << "\n";
                 std::cout << "                     mode from command line" << "\n";
                 std::cout << "   -multi_lane <value> Parameter of the ASTD" << std::endl;
                 std::cout << "   -pre_check <value> Parameter of the ASTD" << std::endl;
                 
                 
                 
                 std::cout << "   -h                Show this help" << "\n";
                 exit(0);
                 break;
             }
             
         }   
     }
 }


    static Event read_event(int argc) 
    {
        Event e;
        std::string input;
        // std::cout<<" Read Event 00000 "<<"\n";
        // std::cout<<" automatic input =  "<< automatic_input<<"\n";
        if(argc > 1) 
        {
            if(!automatic_input.empty()){
                e.label = automatic_input;
                // automatic_input.clear();
                automatic_input = "empty";
            }else{
                if(!filename.empty()) 
                    std::getline(channel, input); 
                else 
                    std::getline(std::cin, input);
                e.label = get_event_label(input);
            }
            // std::cout<<" Event value === "<< e.label<<"\n";
            get_event_params(e, input, std::regex(PARAMS_REGEX));  
        }
        else 
        {
            if(!automatic_input.empty()){
                e.label = automatic_input;
                // automatic_input.clear();
                automatic_input = "empty";
            }else{
                getline(std::cin, input);
            e.label = get_event_label(input);
            }
            get_event_params(e, input, std::regex(PARAMS_REGEX));
        }
     
        return e;
    }
};

/*
* @brief Manages clock variables.
*
*/
class Timer {
private:
        std::time_t time_stamp;

public:
    //constructor definition
    Timer(){
        time_stamp = std::chrono::duration_cast<std::chrono::nanoseconds>((std::chrono::system_clock::now().time_since_epoch())).count();
    }

    bool expired(double duration){
        return (std::chrono::duration_cast<std::chrono::nanoseconds>((std::chrono::system_clock::now().time_since_epoch())).count() >= time_stamp + duration);
    }

    std::time_t getPassedTime(){
        return (std::chrono::duration_cast<std::chrono::nanoseconds>((std::chrono::system_clock::now().time_since_epoch())).count() - time_stamp);
    }

    std::time_t getTimeStamp(){
        return time_stamp;
    }

    void reset_clock(){
        time_stamp = std::chrono::duration_cast<std::chrono::nanoseconds>((std::chrono::system_clock::now().time_since_epoch())).count();
    }

    void reset_clock(Timer ts){
        time_stamp = ts.getTimeStamp();
    }

    void setTimeStamp(){

    }
};

//functions to simulate advance time

std::time_t convertToNano( std::time_t hour, std::time_t min, std::time_t sec, std::time_t millisec, std::time_t microsec, std::time_t nanosec){
    std::time_t currentTime = 0;
    currentTime = (((hour * 60 * 60) + (min * 60) + sec) * 1000000000) + (millisec * 1000000) + (microsec * 1000) + nanosec;
    return currentTime;
}

long int advanceToV1(std::time_t time_stamp, std::time_t step_time, std::string mixedvalues){
    
    std::time_t hour = 0;
    std::time_t min = 0;
    std::time_t sec = 0;
    std::time_t millisec = 0;
    std::time_t microsec = 0;
    std::time_t nanosec = 0;

    const char* data = mixedvalues.c_str();
    char *ep;

    hour = strtol(data, &ep, 10);
    if (!(!ep || *ep != ':')) {
        min = strtol(ep+1, &ep, 10);
        if (!(!ep || *ep != ':')) {
            sec = strtol(ep+1, &ep, 10);
            if (!(!ep || *ep != ':')) {    
                millisec = strtol(ep+1, &ep, 10);
                if (!(!ep || *ep != ':')) {
                    microsec = strtol(ep+1, &ep, 10);
                    if (!(!ep || *ep != ':')) {
                        nanosec = strtol(ep+1, &ep, 10);
                    }
                }
            }
        }
    }
    
    std::time_t calc_time = convertToNano(hour, min, sec, millisec, microsec, nanosec);

    if(time_stamp < calc_time){    
        long int numberOfSteps = calc_time / step_time;
        return numberOfSteps;
    }
    else{
        return -1;
    }
}

long int advanceToV2(std::time_t timer, std::time_t step_time, std::string unit, std::time_t value){

    std::time_t hour = 0;
    std::time_t min = 0;
    std::time_t sec = 0;
    std::time_t millisec = 0;
    std::time_t microsec = 0;
    std::time_t nanosec = 0;

    if(unit == "hour"){
        hour = value;
    }
    else if(unit == "min"){
        min = value;
    }
    else if(unit == "sec"){
        sec = value;
    }
    else if(unit == "millisec"){
        millisec = value;
    }
    else if(unit == "microsec"){
        microsec = value;
    }
    else if(unit == "nanosec"){
        nanosec = value;
    }

    std::time_t calc_time = convertToNano(hour, min, sec, millisec, microsec, nanosec);

    if(timer < calc_time){    
        long int numberOfSteps = calc_time / step_time;
        return numberOfSteps;
    }
    else{
        return -1;
    }
}

long int advanceOfV1(std::time_t step_time, std::string mixedvalues){
    
    std::time_t hour = 0;
    std::time_t min = 0;
    std::time_t sec = 0;
    std::time_t millisec = 0;
    std::time_t microsec = 0;
    std::time_t nanosec = 0;

    const char* data = mixedvalues.c_str();
    char *ep;

    hour = strtol(data, &ep, 10);
    if (!(!ep || *ep != ':')) {
        min = strtol(ep+1, &ep, 10);
        if (!(!ep || *ep != ':')) {
            sec = strtol(ep+1, &ep, 10);
            if (!(!ep || *ep != ':')) {    
                millisec = strtol(ep+1, &ep, 10);
                if (!(!ep || *ep != ':')) {
                    microsec = strtol(ep+1, &ep, 10);
                    if (!(!ep || *ep != ':')) {
                        nanosec = strtol(ep+1, &ep, 10);
                    }
                }
            }
        }
    }
    
    std::time_t calc_time = convertToNano(hour, min, sec, millisec, microsec, nanosec);

    long int numberOfSteps = calc_time / step_time;
    if(numberOfSteps > 0){    
        return numberOfSteps;
    }
    else{
        return -1;
    }

}

long int advanceOfV2(std::time_t step_time, std::string unit, std::time_t value){

    std::time_t hour = 0;
    std::time_t min = 0;
    std::time_t sec = 0;
    std::time_t millisec = 0;
    std::time_t microsec = 0;
    std::time_t nanosec = 0;

    if(unit == "hour"){
        hour = value;
    }
    else if(unit == "min"){
        min = value;
    }
    else if(unit == "sec"){
        sec = value;
    }
    else if(unit == "millisec"){
        millisec = value;
    }
    else if(unit == "microsec"){
        microsec = value;
    }
    else if(unit == "nanosec"){
        nanosec = value;
    }

    std::time_t calc_time = convertToNano(hour, min, sec, millisec, microsec, nanosec);

    long int numberOfSteps = calc_time / step_time;
    if(numberOfSteps > 0){    
        return numberOfSteps;
    }
    else{
        return -1;
    }
}