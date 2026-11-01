#include "ros2_cpp_template/listener_node.hpp"

namespace ros2_cpp_template
{

ListenerNode::ListenerNode(const rclcpp::NodeOptions & options)
: Node("listener", options)
{
  subscription_ = this->create_subscription<std_msgs::msg::String>(
    "chatter", 10,
    std::bind(&ListenerNode::topic_callback, this, std::placeholders::_1));
}

void ListenerNode::topic_callback(const std_msgs::msg::String::SharedPtr msg) const
{
  RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
}

}  // namespace ros2_cpp_template

// ================= 这里是缺失的 main 函数 =================
int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<ros2_cpp_template::ListenerNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}