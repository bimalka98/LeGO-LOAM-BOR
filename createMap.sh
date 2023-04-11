#!/usr/bin/env bash
# 2022 Bimalka Piyaruwan Thalagala
# #!/bin/sh" -e does not work here: https://askubuntu.com/a/909147

# clear previous map data at ~/ros/map
cd ~/ros
rm -rf map

# get back to ros worksapce
readonly WS=test_ws
cd ~/ros/${WS}

# build the workspace
catkin build -j1

# source the workspace
source devel/setup.bash

# run the launch file
roslaunch lego_loam_bor createMap.launch