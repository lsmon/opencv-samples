#include "CustomHeader.h"
#include "CustomOpenCV.h"

int main(int argc, const char** argv)
{
    cout << "Hello World!" << endl;
    cout << "Number of args: " << argc << endl;
    string filename = "../data/baboon.jpg";
    if (argc < 2) {
        cout << "The image file will be set as " << filename << endl;
    } else {
        filename = argv[1];
    }

    SobelDerivativeDemo *demo = new SobelDerivativeDemo(filename);
    demo->SobelDerivatives();
    waitKey();
    return 0;
}
