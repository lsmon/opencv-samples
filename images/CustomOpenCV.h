#ifndef CUSTOMOPENCV_H
#define CUSTOMOPENCV_H

#include "CustomHeader.h"

class SobelDerivativeDemo
{
public:
    /**
     * @brief SobelDerivativeDemo
     */
    SobelDerivativeDemo();
    /**
     * @brief SobelDerivativeDemo
     * @param filename
     */
    SobelDerivativeDemo(string filename);
    /**
     * @brief SobelDerivatives
     * @param filename
     */
    void SobelDerivatives();
    /**
     * @brief SetSobelScale
     * @param scale
     */
    void SetSobelScale(int scale);
    /**
     * @brief SetSobleDelta
     * @param delta
     */
    void SetSobleDelta(int delta);
    /**
     * @brief SetSobleDDepth
     * @param ddepth
     */
    void SetSobleDDepth(int ddepth);
    /**
     * @brief SetFileName
     * @param filename
     */
    void SetFileName(string filename);
    /**
     * @brief GetSobelScale
     * @return
     */
    int GetSobelScale();
    /**
     * @brief GetSobelDelta
     * @return
     */
    int GetSobelDelta();
    /**
     * @brief GetSobleDDepth
     * @return
     */
    int GetSobleDDepth();
    /**
     * @brief GetFileName
     * @return
     */
    string GetFileName();
private:
    void init();
    /**
     * @brief readDataFailFrom
     * @param filename
     */
    void readDataFailFrom();
    /**
     * @brief convertToGray
     * @param src
     * @param src_gray
     * @param code [ie:CV_RGB2GRAY]
     */
    void convertToGray();
    void convertToGray(int code);
    /**
     * @brief CustomOpenCV::createWindow
     * @param windowSizeFlag [ie:CV_WINDOW_NORMAL]
     */
    void createWindow(int windowSizeFlag);
    /**
     * @brief CustomOpenCV::sobelGradientX
     * @param src_gray
     * @param grad_x
     * @param borderType [ie: BORDER_DEFAULT]
     */
    void sobelGradientX(Mat src_gray, Mat grad_x, int borderType);
    /**
     * @brief CustomOpenCV::sobelGradientY
     * @param src_gray
     * @param grad_y
     * @param borderType [ie: BORDER_DEFAULT]
     */
    void sobelGradientY(Mat src_gray, Mat grad_y, int borderType);
    /**
     * @brief CustomOpenCV::gradientApproximation
     * @param alpha [Default=0.5]
     * @param beta [Default=0.5]
     * @param gamma [Default=0]
     * @param dtype [Default=-1]
     */
    void gradientApproximation(double alpha=0.5, double beta=0.5, double gamma=0);

    Mat src;
    Mat src_gray;
    Mat grad;
    Mat grad_x; // OuputArray
    Mat grad_y;
    Mat abs_grad_x;
    Mat abs_grad_y;
    int sobel_scale;
    int sobel_delta;
    int ddepth;
    string window_name;
    string filename;
};

#endif // CUSTOMOPENCV_H
