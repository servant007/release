#!/bin/bash
rosrun dynamic_reconfigure dynparam set /move_base/global_costmap footprint '[[0.347, -0.26], [0.347, 0.26], [-0.342, 0.26], [-0.342, -0.26]]';
rosrun dynamic_reconfigure dynparam set /move_base/local_costmap footprint '[[0.347, -0.26], [0.347, 0.26], [-0.342, 0.26], [-0.342, -0.26]]';