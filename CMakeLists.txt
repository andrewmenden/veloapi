cmake_minimum_required(VERSION 3.10)
project(playground)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SDL2 library
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(include)

# Add ImGui
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/external/imgui)
set(IMGUI_BACKENDS_DIR ${IMGUI_DIR}/backends)
file(GLOB IMGUI_SOURCES
    ${IMGUI_DIR}/*.cpp
    ${IMGUI_BACKENDS_DIR}/imgui_impl_sdl2.cpp
    ${IMGUI_BACKENDS_DIR}/imgui_impl_opengl3.cpp
    src/*.cpp
)

include_directories(${IMGUI_DIR} ${IMGUI_BACKENDS_DIR})

# Set source files
set(SOURCES src/main.cpp ${IMGUI_SOURCES})
add_executable(playground ${SOURCES})

# Link SDL2 library
target_link_libraries(playground ${SDL2_LIBRARIES} "-framework OpenGL")
