//this program subscribles to turtle1/pose and show its
//messages on the screen
#include<ros/ros.h>
#include<turtlesim/Pose.h>
#include<iomanip> //for std::setprecision and std::fixed,setprecision(2）为设置小数点输出的精度，也就是小数点右面的数字的个数为2。std::fixed表示以带小数点的形式表示浮点。

// a callback function . executed each time a new pose 
//message arrives.
void poseMessageReceived(const turtlesim::Pose& msg){
ROS_INFO_STREAM(std::setprecision(2)<<std::fixed<<"position=("<<msg.x<<","<<msg.y<<")"<<"*direction="<<msg.theta);
}

int main(int argc,char **argv){
//initialize the ros system and become a node
ros::init(argc,argv,"subscribe_to_pose");
ros::NodeHandle nh;

//create a subscriber object.
ros::Subscriber sub=nh.subscribe("turtle1/pose",1000,&poseMessageReceived);//也可以不用&符号,因为函数名本身就是地址，这里&poseMessageReceived仅仅是把它赋值给一个函数指针。之所以用了&是为了告诉读者这个函数这里需要输入的是一个函数指针。编译器是会直接根据函数名后是否有括号来决定这是一个函数指针还是一个返回值。

//let ros take over.
ros::spin();
}

