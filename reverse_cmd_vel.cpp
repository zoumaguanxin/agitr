//this program subscribes to turtle1/cmd_vel and
//republished on turtle1/cmd_vel_revgersed,
//with the signs inverted.
#include<ros/ros.h>
#include<geometry_msgs/Twist.h>

ros::Publisher *pubPtr;//声明了ros::Publisher类的对象指针变量

void commandVelocityReceived(const geometry_msgs::Twist& msgIn)
{
   geometry_msgs::Twist msgOut;
   msgOut.linear.x=-msgIn.linear.x;
   msgOut.angular.z=-msgIn.angular.z;
   pubPtr->publish(msgOut);
}

int main(int argc,char ** argv){
ros::init(argc,argv,"reverse_velocity");
ros::NodeHandle nh;

pubPtr= new ros::Publisher(nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel_reversed",1000));//new表示了为某类申请一个动态地址，
//并用具体对象进行了初始化,nh.advertise()返回的多半是ros::Publisher类的一个对象。
//就是它的一个对象，并把对象的地址赋值给pubPtr

ros::Subscriber sub=nh.subscribe("turtle1/cmd_vel",1000,&commandVelocityReceived);//这一句话就包含了节点“reverse_velocity”订阅turtle1/cmd_vel消息，并将其反转，再发布到turtle1/cmd_vel_reversed上

ros::spin();

//delete pubPtr;
}
