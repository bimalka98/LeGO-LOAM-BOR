# Progress of LeGO-LOAM-BOR adoptation

## Made  compatible for ROS1 Noetic + Ubuntu 20.04 Date: 2023 Jan 5

* Execute the below commands in a terminal

```shell

# Mapping
bimalka98@LAP-BIMALKA98:~/ros/catkin_ws$ roslaunch lego_loam_bor createMap.launch rosbag:=/home/bimalka98/ros/rosbags/lego_loam/2017-06-08-15-51-45_2.bag  lidar_topic:=/velodyne_points

# Localization
bimalka98@LAP-BIMALKA98:~/ros/catkin_ws$ roslaunch lego_loam_bor localization.launch rosbag:=/home/bimalka98/ros/rosbags/lego_loam/2017-06-08-15-51-45_2.bag  lidar_topic:=/velodyne_points


```

<p align='left'>
    <img src="./rosbag_play.png" alt="drawing" width="800"/>
</p>

# Checked on Jetson Nano

Rosbag plays with X0.8, X0.9 speeds. Reasonable.

<p align='left'>
    <img src="./lego-loam-on-jetson.png" alt="drawing" width="800"/>
</p>

