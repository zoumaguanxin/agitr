//this program spawns a new turtlesim turtle by calling
//the appropriate service.
#include<ros/ros.h>
//这里关键是数据类型，就像在发布消息里面，我们包含的头文件是关于消息类型的<geometry_msgs/Twist.h>.这里就包含的是服务的数据类型头文件
#include<turtlesim/Spawn.h>

int main(int argc,char **argv){
 ros::init(argc,argv,"spwan_turtle");
 ros::NodeHandle nh;

//create a client object for the spawn service,this needs to know the data type of the service and its name
ros::ServiceClient spawnClient=nh.serviceClient<turtlesim::Spawn>("spawn");

//create the request and response objects.

turtlesim::Spawn::Request req;
turtlesim::Spawn::Response resp;

//fill in the request data members
req.x=2;
req.y=3;
req.theta=M_PI/2;
req.name="Leo";

//actully call the service,this won't return until the service is complete.
bool success=spawnClient.call(req,resp);

//check for success and use the response
if(success){
ROS_INFO_STREAM("Spawn a turtle named"<<resp.name);}

else{
 ROS_ERROR_STREAM("failed to spawn");
}
}

