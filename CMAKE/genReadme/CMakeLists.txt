message("CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message("PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")
message("PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")

add_executable(readme readme.cpp)

# add_custom_command(
#     OUTPUT ${PROTJECT_SOURCE_DIR}/readme.txt
#     COMMAND mv readme.txt ${PROTJECT_SOURCE_DIR}/
# )