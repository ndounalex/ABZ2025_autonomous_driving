import warnings
import os
import sys

import gymnasium as gym
import highway_env
import numpy as np
from stable_baselines3 import DQN
from stable_baselines3.common.callbacks import CheckpointCallback


save_base_path = "single_adversarial"

# Configuration (default values in parenthesis)
env = gym.make("highway-fast-v0", render_mode='human')
"""env = RecordVideo(env, video_folder="run",
              episode_trigger=lambda e: True) """
env.configure({
    "lanes_count": 1,  # (4)
    "collision_reward": 1,
    "right_lane_reward": 0.0, # (0.1),
    "reward_speed_range": [0,40],
    "high_speed_reward": 2,
    "action": {
        "type": "DiscreteMetaAction",
        "target_speeds": [0,5,10,15,20,25,30,35,40]}
})
#env.unwrapped.set_record_video_wrapper(env)
# env.configure({
#     "lanes_count": 3,  # (4)
#     "vehicles_count": 40,  # (50)
#     "duration": 40,  # (40) [s]
#
#     # (-1) The reward received when colliding with a vehicle.
#     "collision_reward": -1,
#     # ([20, 30]) [m/s] The reward for high speed is mapped linearly from this range to [0, HighwayEnv.HIGH_SPEED_REWARD].
#     "reward_speed_range": [20, 30],
#     # (0.1) The reward received when driving on the right-most lanes, linearly mapped to
#     "right_lane_reward": 0.2, # (0.1)
#     # zero for other lanes.
#     # (0.4) The reward received when driving at full speed, linearly mapped to zero for
#     "high_speed_reward": 0.5, # (0.4)
#     # lower speeds according to config["reward_speed_range"].
#     # The reward received at each lane change action.
#     "lane_change_reward": 0.1, # (0)
#
#     "simulation_frequency": 15,  # (15) [Hz]
#     "policy_frequency": 1,  # (1) [Hz]
#
#     "normalize_reward": True, # (True)
#     "offroad_terminal": False, # (False)
#
#     # Changes for faster training
#     # cf. https://github.com/Farama-Foundation/HighwayEnv/issues/223
#     "disable_collision_checks": True,
# })

env.reset()


def display_script_help():
    print("Usage: python3 highway_agent.py train [model_id]")
    print("       python3 highway_agent.py test [model_id]")
    print()
    print("model_id: The name of the model to save/load (default: 'new')")

def get_paths():
    global save_base_path
    if len(sys.argv) > 2:
        model_id = sys.argv[2]
    else:
        model_id = 'new'

    save_path = os.path.join(save_base_path, model_id)
    model_path = os.path.join(save_path, "trained_model")

    return save_path, model_path

def generate_first_env():
    state = env.reset()[0]
    return state.tolist()

def generate_action(previous_state = None):
    print(previous_state)
    action = ''
    state = previous_state
    print("Usage: python3 highway_agent.py train [model_id]")
    print(state)
    if state is None:
        state = env.reset()[0]
    else:
        state = np.array(previous_state)
    print(state)
    print("Usage: python3 highway_agent.py train [model_id]")
    action = model.predict(state, deterministic=True)[0]
    #action = env.action_space.sample()
    return action

def validate_action():
    env.render()


def update_state(action, pos):
    next_state, reward, done, truncated, info = env.step(action)
    if pos == 1:
        env.render()
    #action_counter[action] += 1
    #print('\r', action_counter, end='')  # Verify multiple actions are taken

    #print("\rCrashes:", crashes, "/", test_runs, "runs", f"({crashes/test_runs*100:0.1f} %)")
    #env.close()
    return next_state.tolist()


#if __name__ == '__main__':
save_path, model_path = get_paths()
model = DQN.load(model_path)
env.configure({"simulation_frequency": 15})

action_counter = [0]*5  # It seems model only takes one action; check this
crashes = 0
test_runs = 1000
print("============= my main ==========")