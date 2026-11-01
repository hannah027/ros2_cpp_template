#ifndef ROS2_CPP_TEMPLATE__LISTENER_NODE_HPP_
#define ROS2_CPP_TEMPLATE__LISTENER_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

namespace ros2_cpp_template
{

class ListenerNode : public rclcpp::Node
{
public:
  explicit ListenerNode(const rclcpp::NodeOptions & options = rclcpp::NodeOptions());

private:
  void topic_callback(const std_msgs::msg::String::SharedPtr msg) const;

  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

}  // namespace ros2_cpp_template

#endif  // ROS2_CPP_TEMPLATE__LISTENER_NODE_HPP_