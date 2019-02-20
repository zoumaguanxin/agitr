//this is a ROS version of the standard "hello, world"
//program

//this header defines the standard ROS classes
#include<ros/ros.h>

int main (int argc,char **argv){
// initialize the ros system
ros::init(argc,argv,"hello_ros");

 //establish this program as a ros node
 ros::NodeHandle nh;

//send some output as a log message.
 ROS_INFO_STREAM("Hello, _ROS!");
}
