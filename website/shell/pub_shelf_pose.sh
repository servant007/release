#!/bin/bash
rostopic pub -1 /shelf_pose geometry_msgs/PoseStamped '{ header: { frame_id: "map" }, pose: { position: { x: 1.56838416703, y: 1.94824903294, z: 0 }, orientation: { x: 0, y: 0, z: -0.68074609135, w: 0.729782017429 } } }' 
