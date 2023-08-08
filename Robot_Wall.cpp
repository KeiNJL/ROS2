#include "rosbot_control/rosbot_class.h"
#include <ros/ros.h>
#include <string>

using namespace std;

class RosbotMove 
{    
public:
  RosbotMove(string a) { left_or_right = a; };
  string left_or_right;
    
  RosbotClass rosbot;
  void avoid_wall();
};

void RosbotMove::avoid_wall() 
{
  rosbot.move_forward(1);
     
    while (rosbot.get_laser(0) > 1.75) 
    {
        ROS_INFO_STREAM("Distance for a wall: " << rosbot.get_laser(0));
        rosbot.move_forward(1);
    }
    
  if (left_or_right == "left") 
    {    
        rosbot.turn("counterclockwise", 3);
        rosbot.move_forward(3);
        rosbot.turn("clockwise", 3);
    } 
    
    else if (left_or_right == "right") 
    {
      
        rosbot.turn("clockwise", 3);
        rosbot.move_forward(3);
        rosbot.turn("counterclockwise", 3);
    } 
    
    else 
    {
    ROS_INFO_STREAM("Direction not set: left or right");
    }
}

int main(int argc, char **argv) 
{
  ros::init(argc, argv, "Rosbot_move_node");
  RosbotMove rosbot_moves("right");
  rosbot_moves.avoid_wall();
}