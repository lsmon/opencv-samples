project(sampling)
cmake_minimum_required(VERSION 2.8)

include(../lib.env.cmake/opencv.cmake)
include(../lib.env.cmake/env.cmake)

# version number
set (SAMPLES_VERSION_MAJOR 1)
set (SAMPLES_VERSION_MINOR 0)

if(${CMAKE_SYSTEM_NAME} STREQUAL Darwin)
        set(SOBEL_DERIVATIVES_DEMO_SOURCES
                CustomHeader.h
                Demo.cpp
                CustomOpenCV.cpp
        )
        set(COMMON_LIBRARIES
                libopencv_core.dylib
                libopencv_highgui.dylib
                libopencv_imgproc.dylib
                libopencv_video.dylib
                libopencv_calib3d.dylib
                libopencv_contrib.dylib
                libopencv_features2d.dylib
                libpthread.dylib
        )
        add_executable(${PROJECT_NAME} ${SOBEL_DERIVATIVES_DEMO_SOURCES})
endif(${CMAKE_SYSTEM_NAME} STREQUAL Darwin)

MESSAGE( STATUS "OPENCV_PATH: " ${OPENCV_PATH} )
MESSAGE( STATUS "OPENCV_LIB_PATH: " ${OPENCV_LIB_PATH} )
MESSAGE( STATUS "OPENCV_INC_PATH: " ${OPENCV_INC_PATH} )
MESSAGE( STATUS "SRC_LIST: " ${SRC_LIST} )
message( "Building for " ${CMAKE_SYSTEM_NAME})

target_link_libraries(sampling ${COMMON_LIBRARIES})


