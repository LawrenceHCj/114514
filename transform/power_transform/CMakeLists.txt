cmake_minimum_required(VERSION 3.10)

# 项目名称
project(ImageProcessing)

# 查找 Python 库
find_package(Python COMPONENTS Interpreter Development REQUIRED)

# 设置 Python 脚本的位置
set(PYTHON_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/main.py")

# 复制 Python 脚本到构建目录
add_custom_command(
    OUTPUT ${CMAKE_BINARY_DIR}/main.py
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${PYTHON_SCRIPT} ${CMAKE_BINARY_DIR}/main.py
    DEPENDS ${PYTHON_SCRIPT}
)

# 添加一个自定义目标来运行 Python 脚本
add_custom_target(run_python_script ALL
    COMMAND ${Python_EXECUTABLE} ${CMAKE_BINARY_DIR}/main.py
    DEPENDS ${CMAKE_BINARY_DIR}/main.py
)

# 打印一条消息，提示用户如何运行 Python 脚本
add_custom_target(echo_message ALL
    COMMAND echo "To run the Python script, use the following command: cmake --build . --target run_python_script"
)

