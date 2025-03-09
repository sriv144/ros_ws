cmake_minimum_required(VERSION 3.8)
project(my_robot_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_lint_auto REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)  # Add this line to ensure std_msgs is found

# Generate messages
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/HardwareStatus.msg"
  DEPENDENCIES std_msgs  # Add std_msgs as a dependency if needed
)

ament_export_dependencies(rosidl_default_runtime)
ament_package()
