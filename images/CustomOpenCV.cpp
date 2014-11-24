#include "CustomOpenCV.h"

SobelDerivativeDemo::SobelDerivativeDemo(){
  this->init();
}

SobelDerivativeDemo::SobelDerivativeDemo(string filename)
{
    this->SetFileName(filename);
    this->init();
}

int SobelDerivativeDemo::GetSobelScale(){
    return this->sobel_scale;
}

void SobelDerivativeDemo::SetSobelScale(int scale){
    this->sobel_scale = scale;
}

int SobelDerivativeDemo::GetSobelDelta(){
    return this->sobel_delta;
}

void SobelDerivativeDemo::SetSobleDelta(int delta){
    this->sobel_delta = delta;
}

int SobelDerivativeDemo::GetSobleDDepth(){
    return this->ddepth;
}

void SobelDerivativeDemo::SetSobleDDepth(int ddepth){
    this->ddepth = ddepth;
}

string SobelDerivativeDemo::GetFileName(){
    return this->filename;
}

void SobelDerivativeDemo::SetFileName(string filename){
    this->filename = filename;
    this->window_name.append(this->GetFileName());
}

void SobelDerivativeDemo::SobelDerivatives(){
  int scale = 1;
  int delta = 0;
  string window_name = "Sobel Demo - Simple Edge Detector ";

  src = imread(this->GetFileName());
  if (!src.data){
      this->readDataFailFrom();
  }

  window_name.append(filename);
  GaussianBlur(src, src, Size(3,3), 0, 0, BORDER_DEFAULT);
  /// Convert it to gray
  //cvtColor(src, src_gray, CV_RGB2GRAY);
  //this->convertToGray();
  this->convertToGray(CV_RGB2GRAY);
  /// Create window
  this->createWindow(CV_WINDOW_NORMAL);
  /// Gradient X
  this->sobelGradientX(src_gray,grad_x,BORDER_DEFAULT);
  /// Gradient Y
  this->sobelGradientY(src_gray,grad_x,BORDER_DEFAULT);
  /// Total Gradient (approximate)
  this->gradientApproximation();
  imshow( window_name, grad );
}

void SobelDerivativeDemo::init(){
  this->window_name = "Sobel Demo - Simple Edge Detector ";
  this->sobel_scale = 1;
  this->sobel_delta = 0;
  this->ddepth = CV_16S;
}

void SobelDerivativeDemo::readDataFailFrom(){
    cout << "There is an error reading the data from " << this->GetFileName() << endl;
    exit(-1);
}

void SobelDerivativeDemo::convertToGray(){
    cvtColor(src, src_gray, CV_RGB2GRAY);
}

void SobelDerivativeDemo::convertToGray(int code) {
    cvtColor(src, src_gray, code);
}

void SobelDerivativeDemo::createWindow(int windowSizeFlag) {
    namedWindow(window_name, windowSizeFlag);
}

void SobelDerivativeDemo::sobelGradientX(Mat src_gray, Mat grad_x, int borderType){
    Sobel(src_gray, grad_x, this->ddepth, 1, 0, 3, this->GetSobelScale(), this->GetSobelDelta(), borderType);
    convertScaleAbs( grad_x, this->abs_grad_x );
}

void SobelDerivativeDemo::sobelGradientY(Mat src_gray, Mat grad_y, int borderType){
    Sobel(src_gray, grad_y, this->ddepth, 0, 1, 3, this->GetSobelScale(), this->GetSobelDelta(), borderType);
    convertScaleAbs(grad_y, this->abs_grad_y );
}

void SobelDerivativeDemo::gradientApproximation(double alpha, double beta, double gamma){
    addWeighted(this->abs_grad_x, alpha, this->abs_grad_y, beta, gamma, this->grad);
}
