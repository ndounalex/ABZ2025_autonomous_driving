# ABZ 2025 Case Study


[![Code Quality Status](https://img.shields.io/badge/code%20quality-B%2B-yellowgreen)](https://img.shields.io/badge/code%20quality-B%2B-yellowgreen)
[![Build](https://img.shields.io/badge/build-passing-green)](https://img.shields.io/badge/build-passing-green)
[![Docs](https://img.shields.io/badge/docs-passing-green)](https://img.shields.io/badge/docs-passing-green)
[![Kubernetes](https://img.shields.io/badge/kubernetes-automated-blue)](https://img.shields.io/badge/kubernetes-automated-blue)

# cASTD and eASTD installation
The installation procedure for eASTD and cASTD can be found in the [here](https://github.com/ndounalex/ASTD-tools).

## Wiki

Go to page [cASTD Wiki](https://depot.gril.usherbrooke.ca/lionel-tidjon/castd/wikis/home)

## Technical documentation

The translation rules and the compilation approach are available [here](https://github.com/DiegoOliveiraUDES/astd-tech-report-27).

## ReadTheDocs

Check our full documentation [online](https://castd.readthedocs.io/).

## Description

our warehouse is mainly made up of the following elements:
- the controller.eastd file, which contains the eastd specification for the case study.
- the controller.json file, which corresponds to the JSON generated by eastd and used by cASTD to generate the C++ code.
- The main.cpp file, which contains all the utility functions needed to establish communication between the controller and the AI
- The controller.cpp file, which is the c++ file representing our controller code obtained after code generation by passing our eastd file to the Castd compiler
- The test.cpp file, which is the c++ file representing the code for our automated tests, obtained after generating the code by passing our eastd file to the Castd compiler, specifying that we only want to generate code for ASTD Test
- the test.exe file, which is the executable file for launching automated tests, but before executing it you must ensure that the AI launch environment is setup. Test statistics are displayed on the console at the end of tests


## Slack channel

Join project discussions [here](https://astd-cse.slack.com/)

## Training and testing of agents

Setup:

```bash
python -m venv env
source env/bin/activate
pip install -r requirements.txt
```

The agent for the Highway Environment can be trained or tested via command line:

```bash
# To train a new model (save under models/highway_env):
python highway_agent.py train


# Loads the trained model and runs and renders episodes over its behaviour:
python highway_agent.py test
```


## Scenarios


In the following, we provide some scenarios for a single-agent controller.
The controlled vehicle (ego vehicle) is marked in red.
Rosa vehicles are vehicles in the same lane for which the safety distance is relevant.
Purple vehicles are vehicles for which the distance will become relevant when switching lanes.
Blue vehicles are vehicles for which the safety distance will not be relevant in the next cycle.


## Scenario 1


| <img src="images/Scenario1_1.png" alt="Scenario 1.1" width="150%">                         | <img src="images/Scenario1_2.png" alt="Scenario 1.2" width="150%"> | <img src="images/Scenario1_3.png" alt="Scenario 1.3" width="150%"> |
|--------------------------------------------------------------------------------------------|--------------------------------------------------------------------|--------------------------------------------------------------------|
| A vehicle approaches another vehicle in the same lane from behind, the distance decreases. | The Ego vehicle brakes.                                            |The Ego vehicle continues braking to maintain the safety distance. |


## Scenario 2


 ![Scenario 2](images/Scenario2_1.png)                                                      | ![Scenario 2](images/Scenario2_2.png)        | ![Scenario 2](images/Scenario2_3.png)                                    
|--------------------------------------------------------------------------------------------|----------------------------------------------|--------------------------------------------------------------------------|
| A vehicle approaches another vehicle in the same lane from behind, the distance decreases. | The Ego vehicle switches to the right lane.  | The Ego vehicle completes switching to the right lane and accelerates.   |


## Scenario 3

 ![Scenario 3](images/Scenario3_1.png)                   | ![Scenario 3](images/Scenario3_2.png)                                              | ![Scenario 3](images/Scenario3_3.png)       
|---------------------------------------------------------|------------------------------------------------------------------------------------|---------------------------------------------|
| There is another vehicle on another lane further right. | The Ego vehicle switches to the right lane, as the safety distance is maintained.  | The Ego  vehicle continues driving forward. |


## Scenario 4

![Scenario 4](images/Scenario4_1.png)                   | ![Scenario 4](images/Scenario4_2.png)                                                       | ![Scenario 4](images/Scenario4_3.png)
|---------------------------------------------------------|---------------------------------------------------------------------------------------------|---------------------------------------------|
| There is another vehicle on another lane further right. | The Ego vehicle cannot switch to the center lane, as the safety distance is not maintained. | The Ego vehicle continues driving forward.  |


## Scenario 5

 ![Scenario 5](images/Scenario5_1.png)         | ![Scenario 5](images/Scenario5_2.png)           | ![Scenario 5](images/Scenario5_3.png)                                                 
|-----------------------------------------------|-------------------------------------------------|---------------------------------------------------------------------------------------|
| The Ego Vehicle drives on the left-most lane. | There is another vehicle on the right-most lane | Both vehicles decide to switch to the center lane, while maintaining safety distances |
