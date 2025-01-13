cmake_minimum_required(VERSION 3.5)
project(receiver)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找 ROS 2 依赖项
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# 添加头文件路径
include_directories(include)

# 创建可执行文件
add_executable(receiver_node src/receiver.cpp)

# 链接依赖的库
ament_target_dependencies(receiver_node rclcpp std_msgs)

# 安装可执行文件
install(TARGETS receiver_node DESTINATION lib/${PROJECT_NAME})

# 声明该包
ament_package()

