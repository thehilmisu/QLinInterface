cmake_minimum_required(VERSION 3.10)
project(QLinInterface VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)

# Find and setup Qt
set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu")

# Debugging path setup
message(STATUS "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")

find_package(Qt5 COMPONENTS Core SerialPort Widgets REQUIRED)

# Source files
set(SOURCES
    src/main.cpp
    src/ldf_parser.cpp
    src/lin_interface.cpp
)

# Headers
set(HEADERS
    include/ldf_parser.h
    include/lin_interface.h
)

# Define the executable
add_executable(QLinInterface ${SOURCES})

# Include directories
target_include_directories(QLinInterface PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Link Qt libraries
target_link_libraries(QLinInterface Qt5::Core Qt5::SerialPort Qt5::Widgets)

# Set output directories
set_target_properties(QLinInterface PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

