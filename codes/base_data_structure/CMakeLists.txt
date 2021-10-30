# CMakeList.txt: leet_code_cmake 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("base_data_structure")

include_directories( ${PROJECT_SOURCE_DIR}/include)

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/linklist SRC_LINK_LIST)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/tree SRC_TREE)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/sort SRC_SORT)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/senior_sort SRC_SENIOR_SORT)

# 将源代码添加到此项目的可执行文件。
add_executable (base_data_structure ${SRC} ${SRC_LINK_LIST} ${SRC_TREE} ${SRC_SORT} ${SRC_SENIOR_SORT})

# TODO: 如有需要，请添加测试并安装目标。
