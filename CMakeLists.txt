# 最低CMake版本要求
cmake_minimum_required(VERSION 3.5.1)
 
# 项目名称
project(DATA_STRUCTURE_REVIEW)
 
#添加debug信息，使得生成的可执行文件可以调试
#set(CMAKE_BUILD_TYPE DEBUG)

#使用通配符添加多个源文件
#file(GLOB SRC_LIST "src/*.c")
 
#编译选项
add_compile_options(-std=c++11)
 
# 头文件路径
include_directories("include" "exercises")
aux_source_directory("src" DIR_SRCS)
 
#链接库
#link_libraries(event)
 
# 生成可执行的文件
add_executable(out ${DIR_SRCS})