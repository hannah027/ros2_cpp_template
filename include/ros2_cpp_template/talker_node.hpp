#ifndef ROS2_CPP_TEMPLATE__TALKER_NODE_HPP_
#define ROS2_CPP_TEMPLATE__TALKER_NODE_HPP_

#include <chrono>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

namespace ros2_cpp_template
{

class TalkerNode : public rclcpp::Node
{
public:
  explicit TalkerNode(const rclcpp::NodeOptions & options = rclcpp::NodeOptions());

private:
  void timer_callback();

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  size_t count_{0};
};

}  // namespace ros2_cpp_template

#endif  // ROS2_CPP_TEMPLATE__TALKER_NODE_HPP_