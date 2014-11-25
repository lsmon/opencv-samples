#ifndef CUSTOMOPENCV_H
#define CUSTOMOPENCV_H

#include "CustomHeader.h"

class CustomOpenCV
{
public:
    /**
     * @brief CustomOpenCV
     */
    CustomOpenCV();

    /**
     * @brief CustomOpenCV
     * @param filename
     */
    CustomOpenCV(string filename);

    /**
     * @brief ScharSobelDerivatives
     */
    void ScharSobelDerivatives();

    /**
     * @brief SobelScharDerivatives
     */
    void SobelScharDerivatives();

    /**
     * @brief SobelDerivatives
     * @param filename
     */
    void SobelDerivatives();

    /**
     * @brief ScharDerivatives
     */
    void ScharDerivatives();

    /**
     * @brief ShowMat
     */
    void ShowMat();

    /**
     * @brief SetScale
     * @param scale
     */
    void SetScale(int scale);

    /**
     * @brief SetDelta
     * @param delta
     */
    void SetDelta(int delta);

    /**
     * @brief SetDDepth
     * @param ddepth
     */
    void SetDDepth(int ddepth);

    /**
     * @brief SetFileName
     * @param filename
     */
    void SetFileName(string filename);

    /**
     * @brief GetScale
     * @return
     */
    int GetScale();

    /**
     * @brief GetDelta
     * @return
     */
    int GetDelta();

    /**
     * @brief GetDDepth
     * @return
     */
    int GetDDepth();

    /**
     * @brief GetFileName
     * @return
     */
    string GetFileName();

private:
    /**
     * @brief init
     */
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

    /**
     * @brief convertToGray
     * @param code
     */
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

    /**
     * @brief scharGradientX
     * @param src_gray
     * @param grad_x
     * @param borderType [ie: BORDER_DEFAULT]
     */
    void scharGradientX(Mat src_gray, Mat grad_x, int borderType);

    /**
     * @brief scharGradientY
     * @param src_gray
     * @param grad_y
     * @param borderType [ie: BORDER_DEFAULT]
     */
    void scharGradientY(Mat src_gray, Mat grad_y, int borderType);

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
