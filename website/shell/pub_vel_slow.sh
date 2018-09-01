#!/bin/bash

rosrun dynamic_reconfigure dynparam set /move_base/DWAPlannerROS max_trans_vel 0.10;
rosrun dynamic_reconfigure dynparam set /move_base/DWAPlannerROS max_vel_x 0.10;

rosrun dynamic_reconfigure dynparam set /move_base/DWAPlannerROS path_distance_bias 32.0;
