#!/bin/bash
rosrun dynamic_reconfigure dynparam set /scan_filter/box_left box_frame base_link;
rosrun dynamic_reconfigure dynparam set /scan_filter/box_left min_x 0.35;
rosrun dynamic_reconfigure dynparam set /scan_filter/box_left max_x 0.55;
rosrun dynamic_reconfigure dynparam set /scan_filter/box_left min_y 0.25;
rosrun dynamic_reconfigure dynparam set /scan_filter/box_left max_y 0.65;
rosrun dynamic_reconfigure dynparam set /scan_filter/box_right box_frame base_link;
rosrun dynamic_reconfigure dynparam set /scan_filter/box_right min_x 0.35;
rosrun dynamic_reconfigure dynparam set /scan_filter/box_right max_x 0.55;
rosrun dynamic_reconfigure dynparam set /scan_filter/box_right min_y -0.65;
rosrun dynamic_reconfigure dynparam set /scan_filter/box_right max_y -0.25;