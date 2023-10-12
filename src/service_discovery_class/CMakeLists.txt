cmake_minimum_required(VERSION 3.5)
project(service_discovery_class)

find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)
find_package(tutorial_interfaces REQUIRED)

add_executable(server1 src/service_provider1.cpp)
ament_target_dependencies(server1 rclcpp tutorial_interfaces)

add_executable(server2 src/service_provider2.cpp)
ament_target_dependencies(server2 rclcpp tutorial_interfaces)

add_executable(client src/service_consumer_class.cpp)
ament_target_dependencies(client rclcpp tutorial_interfaces)

install(TARGETS
  server1
  server2
  client
  DESTINATION lib/${PROJECT_NAME})

ament_package()
