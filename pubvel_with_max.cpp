//this program publishes random velocity commands,using a maximum linear velocity read from a parameter
#include<ros/ros.h>
#include<geometry_msgs/Twist.h>
#include<stdlib.h>

int main(int argc,char **argv){
ros::init(argc,argv,"publish_velocity");
ros::NodeHandle nh;
ros::Publisher pub =nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel",1000);
srand(time(0));

//get the maximum velocity parameter,注意一下这个参数名，会被当作私有名称来解析，所以是加了~号的，私有名称是以他们节点名称作为命名空间的，具体参见5.3章
const std::string PARAM_NAME="~max_vel";
double maxVel;
//ros::param::get(param_name,output_value),注意到第二个参数是应用传递，返回参数的值。
bool ok=ros::param::get(PARAM_NAME,maxVel);
if(!ok){
ROS_FATAL_STREAM("Could not get parameter"<<PARAM_NAME);
exit(1);
}
\
ros::Rate rate(2);

while(ros::ok()){
//create and fill in the message. the other four
//fields, which are ignored by turtlesim ,default to 0.
geometry_msgs::Twist msg;
msg.linear.x=maxVel*double(rand())/double(RAND_MAX);
msg.angular.z=2*double(rand())/double(RAND_MAX)-1;

//publish the message
pub.publish(msg);

//Wait until's time for another iteration
rate.sleep();
}

}


