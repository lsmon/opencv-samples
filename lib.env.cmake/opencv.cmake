###############################################################################
# COMPILER OPTIONS
###############################################################################

set(OPENCV_PATH     /usr/local/Cellar/opencv/2.4.9)
set(OPENCV_LIB_PATH ${OPENCV_PATH}/lib)
set(OPENCV_INC_PATH ${OPENCV_PATH}/include)

if(${CMAKE_SYSTEM_NAME} STREQUAL Darwin)
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -m64")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -m64")
else(${CMAKE_SYSTEM_NAME} STREQUAL Linux)
        FIND_PACKAGE(CUDA REQUIRED)
        set(CUDA_TOOLKIT  	/usr/local/cuda)
        set(CUDA_LIBS		${CUDA_TOOLKIT}/lib)
        set(CUDA_INCS		${CUDA_TOOLKIT}/include)
        set(CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS};-O3 -gencode arch=compute_32,code=sm_32)
        set(CUDA_VERBOSE_BUILD ON CACHE BOOL "nvcc verbose" FORCE)
endif(${CMAKE_SYSTEM_NAME} STREQUAL Darwin)

include_directories(
        ${OPENCV_INC_PATH}
        ${OPENCV_INC_PATH}/opencv2/core/include
        ${OPENCV_INC_PATH}/opencv2/highgui/include
        ${OPENCV_INC_PATH}/opencv2/imgproc/include
        ${OPENCV_INC_PATH}/opencv2/video/include
        ${OPENCV_INC_PATH}/opencv2/features2d/include
        ${OPENCV_INC_PATH}/opencv2/core/include
        ${OPENCV_INC_PATH}/opencv2/flann/include
        ${OPENCV_INC_PATH}/opencv2/calib3d/include
        ${OPENCV_INC_PATH}/opencv2/objdetect/include
        ${OPENCV_INC_PATH}/opencv2/legacy/include
)

link_directories(${OPENCV_LIB_PATH}
        /usr/lib/
)