set(Target "maintest")
project(Target C CXX)

# 设置语言标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

message("")
message(STATUS "Start building : " ${Target})

# 设置包含路径
include_directories( ${ROOT_DIR}/src/base/include ${ROOT_DIR}/src/net/include ${ROOT_DIR}/src/designpattern/include
        ${ROOT_DIR}/src/yaml/  ${ROOT_DIR}/src/extend )

# 设置依赖动态库、静态库路径
link_directories(
        ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
        ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}
        ${ROOT_DIR}/src/yaml/yaml-cpp
        )

# link_directories(${This}_LINK_DIRS)

aux_source_directory(. SRCS)
aux_source_directory(${ROOT_DIR}/src/utils UTIL_SRCS)
aux_source_directory(${ROOT_DIR}/src/net NET_SRCS)
aux_source_directory(${ROOT_DIR}/src/base BASE_SRCS)
aux_source_directory(${ROOT_DIR}/src/extend EXTEND)



# link_libraries(${ROOT_DIR}/src/yaml/yaml-cpp/libyaml-cpp.a)

add_executable(${Target} ${SRCS} ${UTIL_SRCS} ${NET_SRCS} ${BASE_SRCS} ${EXTEND})

set(STATIC_LIBRARYS)

find_library(jsoncp libyaml-cpp.a  ${ROOT_DIR}/src/yaml)
target_link_libraries(${Target}  ${jsoncp} ${STATIC_LIBRARYS}  -lpthread  )

install(TARGETS ${Target}
        EXPORT ${Target}
        RUNTIME DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG}    #动态库安装路径
        LIBRARY DESTINATION ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG}    #静态库安装路径
        ARCHIVE DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG}    #可执行文件安装路径
        )

message(STATUS "Stop building : " ${Target} "\n")