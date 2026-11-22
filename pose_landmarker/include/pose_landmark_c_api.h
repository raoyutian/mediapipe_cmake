//
// Created by mzh on 2024/1/4.
// For android platform, we need rewrite the Cpp API as C-API.
//
#pragma once
#ifndef MPP_CMAKE_POSE_LANDMARK_C_H
#define MPP_CMAKE_POSE_LANDMARK_C_H

#if defined(_WIN32)
#define MMP_API __declspec(dllexport)
#else
#define MMP_API __attribute__((visibility("default"))) __attribute__((used))
#endif

extern "C" {

#define MAX_POSE_LANDMARK_NUM 33

// The return value
struct  PoseLandmarkResult {
    int poseNum; // 0 means no pose has been found, 1 means 1 pose has been found.
    int rect[4]; // [x, y, w, h]
    float score;
    float points[MAX_POSE_LANDMARK_NUM * 3]; // x, y, z (z may be depth/scale)
};

// Test Dart result
 
MMP_API int testStruct(PoseLandmarkResult *result);

// Create PoseLandmark Instance
 
MMP_API int initPoseLandmarker();

// Load PoseDetect Model from file

 MMP_API int loadModelPoseDetectFromFile(const char *model_path, int device);

// Load PoseDetect Model

 MMP_API int loadModelPoseDetect(const char *buffer, const long buffer_size, const char *model_suffix, int device);

// Load PoseLandmark Model from buffer

MMP_API int loadModelPoseLandmark(const char *buffer, const long buffer_size, const char *model_suffix, int device);

// Load PoseLandmark Model from file

MMP_API int loadModelPoseLandmarkFromFile(const char *model_path, int device);

// Run function
 
/// run the function of pose landmark.
/// \param data input data buffer
/// \param width image w
/// \param height image h
/// \param stride image stride equal to mat.step
/// \param flip -1 and 1 mean flipping along the x and y axes respectively, and 0 means do not flip
/// \param rotate -1 means do not rotate. 0, 1, and 2 means rotate image 90, 180, and 270 clockwise.
/// \param img_type
/// \param result
/// \return -1 means error, 0 means success.
MMP_API int runPoseLandmark(const char *data, const int width, const int height, const int stride, const int flip, const int rotate,
        const int img_type, PoseLandmarkResult *result);
 
MMP_API int releasePoseLandmark();

//#include "pose_landmark_c.cpp"
}
#endif //MPP_CMAKE_POSE_LANDMARK_C_H
