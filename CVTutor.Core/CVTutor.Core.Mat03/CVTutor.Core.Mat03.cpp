// CVTutor.Core.Mat03.cpp : Defines the entry point for the console application.
//

// Reference:
// http://docs.opencv.org/ref/master/d7/d45/classcv_1_1UMat.html

#include "stdafx.h"

using namespace cv;
using namespace std;
using namespace cvtutor::core;


static const string WINDOW_NAME = "Display window";

int main(int argc, char** argv)
{
    string imageName("../../sample-data/HappyFish.jpg"); // by default
    if (argc > 1)
    {
        imageName = argv[1];
    }

    // For debugging.
    namedWindow(WINDOW_NAME, WINDOW_AUTOSIZE);

    UMat A, C;
    A = imread(imageName, -1).getUMat(ACCESS_READ);
    if (A.empty()) 
    {
        cerr << "Could not open or find the image" << endl;
        system("pause");
        return -1;
    }
    displayImageForDebugTracing(WINDOW_NAME, A);

    UMat B(A);                                 // Use the copy constructor
    // cout << "B = " << endl << " " << B << endl << endl;
    displayImageForDebugTracing(WINDOW_NAME, B);

    C = A;                                    // Assignment operator
    // cout << "C = " << endl << " " << C << endl << endl;
    displayImageForDebugTracing(WINDOW_NAME, C);

    UMat G;
    A.copyTo(G);
    // cout << "G = " << endl << " " << G << endl << endl;
    displayImageForDebugTracing(WINDOW_NAME, G);

    // UMat ctor.
    UMat M(2, 2, CV_8UC3, Scalar(0, 0, 255));
    cout << "M = " << endl << " " << M.getMat(ACCESS_READ) << endl << endl;
    system("pause");

    // UMat::create function:
    M.create(4, 4, CV_8UC(2));
    Mat mm;
    M.copyTo(mm);
    cout << "mm = " << endl << " " << mm << endl << endl;
    system("pause");

    // Initialize Mat with random values.
    UMat R = UMat(3, 2, CV_8UC3);
    randu(R, Scalar::all(0), Scalar::all(255));
    cout << "R (default) = " << endl << " " << R.getMat(ACCESS_READ) << endl << endl;
    cout << "R (python)  = " << endl << format(R, Formatter::FMT_PYTHON) << endl << endl;
    cout << "R (csv)     = " << endl << format(R, Formatter::FMT_CSV) << endl << endl;
    cout << "R (numpy)   = " << endl << format(R, Formatter::FMT_NUMPY) << endl << endl;
    cout << "R (c)       = " << endl << format(R, Formatter::FMT_C) << endl << endl;
    system("pause");


    return 0;
}

