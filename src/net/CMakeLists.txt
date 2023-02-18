set(Target "net")
message(STATUS "Start build mode :  ${Target}")
# 将指定路径添加到编译器头文件的搜索路径下，include_directories 影响的范围，
# 当前CMakeList 中所有的目标，以及在其调用点之后，添加的所有子目录
include_directories(${ROOT_DIR}/src/net/include)

# 添加当前文件夹下所有文件为源文件
# aux_source_directory(./logger LOGGERT_SRCS)
aux_source_directory(./ NET_SRCS)

set(SRCS ${NET_SRCS} )

# 生成动态库
# add_library(${Target} SHARED ${SRCS})
add_library(${Target} STATIC  ${SRCS})

install(TARGETS ${Target}
        EXPORT ${Target}
        RUNTIME DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG}    #动态库安装路径
        LIBRARY DESTINATION ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG}    #静态库安装路径
        ARCHIVE DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG}    #可执行文件安装路径
        )

message(STATUS "End building  : " ${Target} "\n")