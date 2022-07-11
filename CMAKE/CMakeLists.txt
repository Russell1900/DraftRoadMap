cmake_minimum_required(VERSION 3.16) # 指定最小版本

project(HelloWorld VERSION 1.0) # 项目名称
message("CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message("PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")
message("PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")

set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 11) # -std=c++11

configure_file("${PROJECT_SOURCE_DIR}/config.h.in" "${PROJECT_SOURCE_DIR}/config.h")

option (SayHi  # 使用cmake -DSayHi=Yes 来修改
"say hi"
ON)

set (VER 123)

if (SayHi)

# include_directories("${PROJECT_SROUCE_DIR}/Hi")

add_subdirectory(Hi) # 添加子文件夹名，cmake会执行子文件夹下面的cmakelists, 会将变量传递过去

set (EXTRA_LIBS ${EXTRA_LIBS} hi)

# list(APPEND EXTRA_LIBS hi)

endif (SayHi)


# aux_source_directory(. DIR_SRCS) # 将./下的所有文件名付给 ${DIR_SRCS}
file(GLOB DIR_SRCS ./*.cpp)
message("${DIR_SRCS}")

add_executable(HelloWorld ${DIR_SRCS} bbb) # 添加可执行文件

# check symbols (introspection)
include(CheckSymbolExists)
set(CMAKE_REQUIRED_LIBRARIES "m") # 设置需求库
check_symbol_exists(exp "math.h" HAVE_EXP) # 检查math.h中是否有exp，结果存入HAVE_EXP, 在config.h.in中，用cmakedefine
check_symbol_exists(log "math.h" HAVE_LOG) # 检查math.h中是否有log，结果存入HAVE_LOG

if (HAVE_LOG)
target_compile_definitions(HelloWorld PRIVATE "HAVE_LOG") # 增加编译选项，target (helloworld) 需要在上文用add_executable / add_library ... 先声明
endif (HAVE_LOG)

target_link_libraries(HelloWorld ${EXTRA_LIBS})

# install rules, install libs and header files
install(TARGETS HelloWorld DESTINATION bin)
install(FILES config.h hello.h DESTINATION include)

# export cmake for lib hi (together with in its cmakelists part)
install(EXPORT hiTargets
FILE hiTargets.cmake
DESTINATION lib/cmake/hi
)

add_subdirectory(genReadme)

# 添加命令，OUTPUT和depends会和其他target的dependence建立依赖链，不一定是文件
add_custom_command(
    OUTPUT bbb
    COMMAND ./genReadme/readme
    DEPENDS readme
)

target_include_directories(HelloWorld PRIVATE hi) # 添加-I
# target_link_libraries(Tutorial PUBLIC MathFunctions) # 添加-l
# target_link_directories() # 添加 -L

# bin installer
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${HelloWorld_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${HelloWorld_VERSION_MINOR}")
include (CPack)

# cpack -G ZIP -C Debug # 安装
# cpack --config CPackSourceConfig.cmake # create source distribution