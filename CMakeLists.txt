cmake_minimum_required(VERSION 3.18)

project("Move_ur_face")

find_package(glm)
find_package(glad)
find_package(glfw3)

add_library(glm INTERFACE)
target_include_directories(glm INTERFACE ${GLM_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} src/entry.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC "Shaderrs")
target_link_libraries(${PROJECT_NAME} PRIVATE glad::glad glfw glm)
