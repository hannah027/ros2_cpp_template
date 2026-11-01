cmake_minimum_required(VERSION 3.8)
project(ros2_cpp_template)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 默认 C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

# 找依赖
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# include 目录
include_directories(
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# Talker
add_executable(talker_node src/talker_node.cpp)
ament_target_dependencies(talker_node rclcpp std_msgs)

# Listener
add_executable(listener_node src/listener_node.cpp)
ament_target_dependencies(listener_node rclcpp std_msgs)

# 安装
install(TARGETS
  talker_node
  listener_node
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()