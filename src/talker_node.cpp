#include "ros2_cpp_template/talker_node.hpp"

namespace ros2_cpp_template
{

TalkerNode::TalkerNode(const rclcpp::NodeOptions & options)
: Node("talker", options)
{
  publisher_ = this->create_publisher<std_msgs::msg::String>("chatter", 10);
  timer_ = this->create_wall_timer(
    std::chrono::milliseconds(500),
    std::bind(&TalkerNode::timer_callback, this));
}

void TalkerNode::timer_callback()
{
  auto msg = std_msgs::msg::String();
  msg.data = "Hello ROS 2 template: " + std::to_string(count_++);
  RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", msg.data.c_str());
  publisher_->publish(msg);
}

}  // namespace ros2_cpp_template

// ================= 这里是缺失的 main 函数 =================
int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<ros2_cpp_template::TalkerNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}