set(Target "util")
message(STATUS "Start build mode :  ${Target}")
# 将指定路径添加到编译器头文件的搜索路径下，include_directories 影响的范围，
# 当前CMakeList 中所有的目标，以及在其调用点之后，添加的所有子目录
include_directories(${ROOT_DIR}/src/utils/include)

# 添加当前文件夹下所有文件为源文件
# aux_source_directory(./logger LOGGERT_SRCS)
aux_source_directory(./ UTIL_SRCS)

set(SRCS ${UTIL_SRCS} )

# 生成动态库
# add_library(${Target} SHARED ${SRCS})
add_library(${Target} STATIC  ${SRCS})

# target_include_directories( ${Target}
#         PUBLIC 
#                 ${ROOT_DIR}/src/utils/include
# )

#使用了C++ 标准库
# target_link_libraries(${Target} PRIVATE stdc++fs)

# 安装生成的静态库
# set(CMAKE_INSTALL_PREFIX ${ROOT_DIR}/install)

install(TARGETS ${Target}
        EXPORT ${Target}
        RUNTIME DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG}    #动态库安装路径
        LIBRARY DESTINATION ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG}    #静态库安装路径
        ARCHIVE DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG}    #可执行文件安装路径
        )

# 安装头文件
# install(DIRECTORY ${ROOT_DIR}/src/utils/include DESTINATION ${CMAKE_INSTALL_PREFIX})

# 将目标文件可导出文件
# install(EXPORT ${Target} DESTINATION ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG}) 

# 生成 ${Target}Config.cmake
# configure_file(${ROOT_DIR}/config/${Target}Config.cmake.in ${ROOT_DIR}/cmake/${Target}Config.cmake)
# install(FILES ${ROOT_DIR}/cmake/${Target}Config.cmake DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake)

message(STATUS "End building  : " ${Target} "\n")