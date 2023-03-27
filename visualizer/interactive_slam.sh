# for ROS noetic -https://github.com/SMRT-AIST/interactive_slam
sudo apt-get install -y \
    libglm-dev  \
    libglfw3-dev \
    libsuitesparse-dev  \
    libeigen3-dev \
    ros-noetic-geodesy \
    ros-noetic-pcl-ros  \
    ros-noetic-nmea-msgs  

# Install g2o from original source code
cd /tmp/
git clone https://github.com/RainerKuemmerle/g2o.git
cd g2o
mkdir build 
cd build
cmake ../
make
sudo make install

# gave up: too many dependencies
