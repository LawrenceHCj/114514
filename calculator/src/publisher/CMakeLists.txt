cmake_minimum_required(VERSION 3.5)
project(publisher)

# 设置编译语言
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)  # ROS 2 C++ 客户端库
find_package(std_msgs REQUIRED)  # ROS 2 标准消息类型

# 如果有其他依赖，使用 find_package
# find_package(your_dependency REQUIRED)

# 添加源代码目录
include_directories(include)

# 编译可执行文件
add_executable(publisher_node src/publisher.cpp)

# 链接 ROS 2 库和其他依赖项
ament_target_dependencies(publisher_node rclcpp std_msgs)

# 安装可执行文件
install(TARGETS publisher_node
  DESTINATION lib/${PROJECT_NAME}
)

# 这个包的其他安装步骤
ament_package()

