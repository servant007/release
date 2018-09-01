#!/bin/bash
rosrun dynamic_reconfigure dynparam set /move_base/global_costmap footprint '[[0.5, -0.5], [0.5, 0.5], [-0.5, 0.5], [-0.5, -0.5]]';
rosrun dynamic_reconfigure dynparam set /move_base/local_costmap footprint '[[0.5, -0.5], [0.5, 0.5], [-0.5, 0.5], [-0.5, -0.5]]';