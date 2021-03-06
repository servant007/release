#!/bin/bash

rosnode kill $AGV_NAME/amcl $AGV_NAME/map_server;
rosnode kill $AGV_NAME/move_base $AGV_NAME/map_edit_server;
rostopic pub -1 $AGV_NAME/odom_reset std_msgs/Empty;
rostopic pub -1 $AGV_NAME/shell_string std_msgs/String "roslaunch bringup bringup-gmapping.launch;";
#roslaunch bringup bringup-hector_mapping.launch

until [[ -n $_FB ]]
do
    _FB=`rosnode list | grep mapping`;
done
rostopic pub -1 $AGV_NAME/ros_mode std_msgs/String "gmapping";

