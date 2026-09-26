cmake_minimum_required(VERSION 3.16)

# project(MAKE)
project(multi
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(multi
    main.cpp

    source/Camera.cpp
    source/CommandInvoker.cpp
    source/StartCameraCommand.cpp
    source/StopCameraCommand.cpp
    source/ResetCameraCommand.cpp
    source/CaptureFrameCommand.cpp
    source/SetExposureCommand.cpp
)

target_include_directories(multi
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)