cmake_minimum_required(VERSION 3.5)
project(lcm_topic)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(talker src/publisher_member_function.cpp)
add_executable(listener1 src/node_a.cpp)
add_executable(listener2 src/node_b.cpp)
add_executable(listener3 src/node_c.cpp)

ament_target_dependencies(talker rclcpp std_msgs)
ament_target_dependencies(listener1 rclcpp std_msgs)
ament_target_dependencies(listener2 rclcpp std_msgs)
ament_target_dependencies(listener3 rclcpp std_msgs)

install(TARGETS
  talker
  listener1
  listener2
  listener3
  DESTINATION lib/${PROJECT_NAME})

ament_package()