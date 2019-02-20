//this program waits for a turtlesim to start up ,and 
//changes its backgroud color
#include<ros/ros.h>
#include<std_srvs/Empty.h>

int main(int argc,char ** argv){

ros::init(argc,argv,"set_bg_color");
ros::NodeHandle nh;

//wait until the clear service is available,which
//indicated that turtlesim has started up, adn has 
//set the backgrond color parameters
ros::service::waitForService("clear");

//set the background color for turtlesim,
//overriding the default blue color.
ros::param::set("background_r",255);
ros::param::set("background_g",255);
ros::param::set("background_b",0);

//Get turtlesim to pick up the new parameter values.
ros::ServiceClient clearClient= nh.serviceClient<std_srvs::Empty>("/clear");
std_srvs::Empty srv;
clearClient.call(srv);
}
