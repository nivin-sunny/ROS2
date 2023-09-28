cmake_minimum_required(VERSION 3.8)
project(cpp_pubsub)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

#find_package(std_msgs REQUIRED)                         # CHANGE

find_package(tutorial_interfaces REQUIRED)                         # CHANGE

add_executable(talker src/publisher_member_function.cpp)
ament_target_dependencies(talker rclcpp tutorial_interfaces)         # CHANGE

add_executable(listener src/subscriber_member_function.cpp)
ament_target_dependencies(listener rclcpp tutorial_interfaces)     # CHANGE

add_executable(watchdog src/watchdog.cpp)
ament_target_dependencies(watchdog rclcpp tutorial_interfaces)         # CHANGE


# add_executable(talker src/publisher_member_function.cpp)
# ament_target_dependencies(talker rclcpp std_msgs)         # CHANGE

# add_executable(listener src/subscriber_member_function.cpp)
# ament_target_dependencies(listener rclcpp std_msgs)         # CHANGE

# add_executable(watchdog src/watchdog.cpp)
# ament_target_dependencies(watchdog rclcpp std_msgs)         # CHANGE

install(TARGETS
  talker
  listener
  watchdog
  DESTINATION lib/${PROJECT_NAME})

ament_package()
