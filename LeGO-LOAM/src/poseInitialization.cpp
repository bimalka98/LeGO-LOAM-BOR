#include "poseInitialization.h"

PoseInitialization::PoseInitialization(ros::NodeHandle &node) : nh(node) {

	init_pose_file = ros::package::getPath("data_base") + "/robopose/initial.txt";

	init_pose_x = 0;
	init_pose_y = 0;
	init_pose_z = 0;
	init_pose_roll = 0;
	init_pose_pitch = 0;
	init_pose_yaw = 0;

	pubInitialPose = nh.advertise<nav_msgs::Odometry>("/robopose/initial", 5);

	_run_thread = std::thread (&PoseInitialization::runPoseInitialization, this);
}

PoseInitialization::~PoseInitialization(){
	_run_thread.join();
}

void PoseInitialization::readPoseFromFile(){

	try{
		std::ifstream file(init_pose_file);

		if(!(file >> init_pose_x >> init_pose_y >> init_pose_z >> init_pose_roll >> init_pose_pitch >> init_pose_yaw)){
			std::cout << "Can't read init_pose_file" << std::endl;
		}

		// print the data to the screen: on single line, round to 2 decimal places
		std::cout << std::fixed << std::setprecision(2) << "[INFO:INIT-POSE] x: " << init_pose_x << " y: " << init_pose_y << " z: " << init_pose_z << " roll: " << init_pose_roll << " pitch: " << init_pose_pitch << " yaw: " << init_pose_yaw << std::endl;

		
	}
	catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	geometry_msgs::Quaternion geoQuat = tf::createQuaternionMsgFromRollPitchYaw(init_pose_roll, init_pose_pitch, init_pose_yaw);

	initPose.pose.pose.orientation.x = geoQuat.x;
  	initPose.pose.pose.orientation.y = geoQuat.y;
  	initPose.pose.pose.orientation.z = geoQuat.z;
  	initPose.pose.pose.orientation.w = geoQuat.w;
  	initPose.pose.pose.position.x = init_pose_x;
  	initPose.pose.pose.position.y = init_pose_y;
  	initPose.pose.pose.position.z = init_pose_z;
}

void PoseInitialization::publishInitialPose(){

	if(pubInitialPose.getNumSubscribers() != 0){
  		pubInitialPose.publish(initPose);
	}
}

void PoseInitialization::runPoseInitialization(){

	readPoseFromFile();

	while(ros::ok()){
		
		if(!ros::ok())
			break;

		publishInitialPose();
	}	
}

