set(Target "maintest")
project(Target C CXX)

# 设置语言标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

message("")
message(STATUS "Start building : " ${Target})

# 设置包含路径
include_directories(${ROOT_DIR}/src/utils/include)

# find_package(${This} REQUIRED HINTS "${ROOT_DIR}/cmake")
# include_directories(${${This}_INCLUDE_DIRS})
# link_libraries 此方式链接静态库，注意与target_link_libraries方式的区别

# 设置依赖动态库、静态库路径
link_directories(
        ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
        ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}
        )

# link_directories(${This}_LINK_DIRS)

aux_source_directory(. SRCS)

add_executable(${Target} ${SRCS})

target_link_libraries(${Target} ${ROOT_DIR}/build/Bin/Debug/libutil.a -lpthread )

install(TARGETS ${Target}
        EXPORT ${Target}
        RUNTIME DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG}    #动态库安装路径
        LIBRARY DESTINATION ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG}    #静态库安装路径
        ARCHIVE DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG}    #可执行文件安装路径
        )

message(STATUS "Stop building : " ${Target} "\n")