#include "CustomOpenCV.h"

CustomOpenCV::CustomOpenCV(){
  this->init();
}

CustomOpenCV::CustomOpenCV(string filename)
{
    this->SetFileName(filename);
    this->init();
}

void CustomOpenCV::SobelScharDerivatives(){
    src = imread(this->GetFileName());
    if (!src.data){
        this->readDataFailFrom();
    }

    GaussianBlur(src, src, Size(3,3), 0, 0, BORDER_DEFAULT);
    /// Convert it to gray
    this->convertToGray(CV_RGB2GRAY);
    /// Create window
    this->createWindow(CV_WINDOW_NORMAL);
    /// Gradient X
    Scharr(src_gray, grad_x, ddepth, 1, 0, this->GetScale(), this->GetDelta(), BORDER_DEFAULT);
    Sobel(src_gray, grad_x, this->ddepth, 1, 0, 3, this->GetScale(), this->GetDelta(), BORDER_DEFAULT);
    convertScaleAbs(grad_x, this->abs_grad_x);

    /// Gradient Y
    Scharr(src_gray, grad_y, ddepth, 0, 1, this->GetScale(), this->GetDelta(), BORDER_DEFAULT);
    Sobel(src_gray, grad_y, this->ddepth, 0, 1, 3, this->GetScale(), this->GetDelta(), BORDER_DEFAULT);
    convertScaleAbs(grad_y, this->abs_grad_y);

    /// Total Gradient (approximate)
    this->gradientApproximation();
    string title = "";
    imshow(title.append(window_name).append(" - sobel + schar - ").append(filename), grad);
}

void CustomOpenCV::ScharSobelDerivatives(){
    src = imread(this->GetFileName());
    if (!src.data){
        this->readDataFailFrom();
    }

    GaussianBlur(src, src, Size(3,3), 0, 0, BORDER_DEFAULT);
    /// Convert it to gray
    this->convertToGray(CV_RGB2GRAY);
    /// Create window
    this->createWindow(CV_WINDOW_NORMAL);
    /// Gradient X
    Scharr(src_gray, grad_x, ddepth, 1, 0, this->GetScale(), this->GetDelta(), BORDER_DEFAULT);
    Sobel(src_gray, grad_x, this->ddepth, 1, 0, 3, this->GetScale(), this->GetDelta(), BORDER_DEFAULT);
    convertScaleAbs(grad_x, this->abs_grad_x);

    /// Gradient Y
    Scharr(src_gray, grad_y, ddepth, 0, 1, this->GetScale(), this->GetDelta(), BORDER_DEFAULT);
    Sobel(src_gray, grad_y, this->ddepth, 0, 1, 3, this->GetScale(), this->GetDelta(), BORDER_DEFAULT);
    convertScaleAbs(grad_y, this->abs_grad_y);

    /// Total Gradient (approximate)
    this->gradientApproximation();
    string title = "";
    imshow(title.append(window_name).append(" - schar + sobel - ").append(filename), grad);
}

void CustomOpenCV::SobelDerivatives(){
    src = imread(this->GetFileName());
    if (!src.data){
        this->readDataFailFrom();
    }

    GaussianBlur(src, src, Size(3,3), 0, 0, BORDER_DEFAULT);
    /// Convert it to gray
    this->convertToGray(CV_RGB2GRAY);
    /// Create window
    this->createWindow(CV_WINDOW_NORMAL);
    /// Gradient X
    this->sobelGradientX(src_gray,grad_x,BORDER_DEFAULT);
    /// Gradient Y
    this->sobelGradientY(src_gray,grad_y,BORDER_DEFAULT);
    /// Total Gradient (approximate)
    this->gradientApproximation();
    string title = "";
    imshow(title.append(window_name).append(" - sobel - ").append(filename), grad);
}

void CustomOpenCV::ScharDerivatives(){
    src = imread(this->GetFileName());
    if (!src.data){
        this->readDataFailFrom();
    }

    GaussianBlur(src, src, Size(3,3), 0, 0, BORDER_DEFAULT);
    /// Convert it to gray
    this->convertToGray(CV_RGB2GRAY);
    /// Create window
    this->createWindow(CV_WINDOW_NORMAL);
    /// Gradient X
    this->scharGradientX(src_gray,grad_x,BORDER_DEFAULT);
    /// Gradient Y
    this->scharGradientY(src_gray,grad_y,BORDER_DEFAULT);
    /// Total Gradient (approximate)
    this->gradientApproximation();
    string title = "";
    imshow(title.append(window_name).append(" - schar - ").append(filename), grad);
}

void CustomOpenCV::ShowMat(){
    cout << "Showing the Mat information" << endl;
    cout << "src (default) = " << endl << src << endl << endl;
    cout << "src_gray (default) = " << endl << src_gray << endl << endl;
    cout << "grad (default) = " << endl << grad << endl << endl;
    cout << "======================================================" << endl;
    cout << "src (python) = " << endl << format(src,"python") << endl << endl;
    cout << "src_gray (python) = " << endl << format(src_gray,"python") << endl << endl;
    cout << "grad (python) = " << endl << format(grad,"python") << endl << endl;
    cout << "======================================================" << endl;
    cout << "src (csv) = " << endl << format(src,"csv") << endl << endl;
    cout << "src_gray (csv) = " << endl << format(src_gray,"csv") << endl << endl;
    cout << "grad (csv) = " << endl << format(grad,"csv") << endl << endl;
    cout << "======================================================" << endl;
    cout << "src (numpy) = " << endl << format(src,"numpy") << endl << endl;
    cout << "src_gray (numpy) = " << endl << format(src_gray,"numpy") << endl << endl;
    cout << "grad (numpy) = " << endl << format(grad,"numpy") << endl << endl;
    cout << "======================================================" << endl;
    cout << "src (C) = " << endl << format(src,"C") << endl << endl;
    cout << "src_gray (C) = " << endl << format(src_gray,"C") << endl << endl;
    cout << "grad (C) = " << endl << format(grad,"C") << endl << endl;
    cout << "======================================================" << endl;
}

void CustomOpenCV::init(){
  this->window_name = "Simple Edge Detector ";
  this->sobel_scale = 1;
  this->sobel_delta = 0;
  this->ddepth = CV_16S;
}

int CustomOpenCV::GetScale(){
    return this->sobel_scale;
}

void CustomOpenCV::SetScale(int scale){
    this->sobel_scale = scale;
}

int CustomOpenCV::GetDelta(){
    return this->sobel_delta;
}

void CustomOpenCV::SetDelta(int delta){
    this->sobel_delta = delta;
}

int CustomOpenCV::GetDDepth(){
    return this->ddepth;
}

void CustomOpenCV::SetDDepth(int ddepth){
    this->ddepth = ddepth;
}

string CustomOpenCV::GetFileName(){
    return this->filename;
}

void CustomOpenCV::SetFileName(string filename){
    this->filename = filename;
}

void CustomOpenCV::convertToGray(){
    cvtColor(src, src_gray, CV_RGB2GRAY);
}

void CustomOpenCV::convertToGray(int code) {
    cvtColor(src, src_gray, code);
}

void CustomOpenCV::createWindow(int windowSizeFlag) {
    namedWindow(window_name, windowSizeFlag);
}

void CustomOpenCV::sobelGradientX(Mat src_gray, Mat grad_x, int borderType){
    Sobel(src_gray, grad_x, this->ddepth, 1, 0, 3, this->GetScale(), this->GetDelta(), borderType);
    convertScaleAbs(grad_x, this->abs_grad_x);
}

void CustomOpenCV::sobelGradientY(Mat src_gray, Mat grad_y, int borderType){
    Sobel(src_gray, grad_y, this->ddepth, 0, 1, 3, this->GetScale(), this->GetDelta(), borderType);
    convertScaleAbs(grad_y, this->abs_grad_y);
}

void CustomOpenCV::gradientApproximation(double alpha, double beta, double gamma){
    addWeighted(this->abs_grad_x, alpha, this->abs_grad_y, beta, gamma, this->grad);
}

void CustomOpenCV::scharGradientX(Mat src_gray, Mat grad_x, int borderType){
    Scharr(src_gray, grad_x, ddepth, 1, 0, this->GetScale(), this->GetDelta(), borderType);
    convertScaleAbs( grad_x, this->abs_grad_x );
}

void CustomOpenCV::scharGradientY(Mat src_gray, Mat grad_y, int borderType){
    Scharr( src_gray, grad_y, ddepth, 0, 1, this->GetScale(), this->GetDelta(), borderType );
    convertScaleAbs(grad_y, this->abs_grad_y);
}

void CustomOpenCV::readDataFailFrom(){
    cout << "There is an error reading the data from " << this->GetFileName() << endl;
    exit(-1);
}
