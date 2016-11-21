// CVTutor.Core.Scan01.cpp : Defines the entry point for the console application.
//

// Tutorial
// http://docs.opencv.org/3.1.0/db/da5/tutorial_how_to_scan_images.html

#include "stdafx.h"
#include <opencv2/core/utility.hpp>

using namespace cv;
using namespace std;
using namespace cvtutor::core;


static void help()
{
    cout
        << "\n--------------------------------------------------------------------------" << endl
        << "This program shows how to scan image objects in OpenCV (cv::Mat). As use case"
        << " we take an input image and divide the native color palette (255) with the " << endl
        << "input. Shows C operator[] method, iterators and at function for on-the-fly item address calculation." << endl
        << "--------------------------------------------------------------------------" << endl
        << endl;
}

UMat& ScanImageAndReduceC(UMat& I, const uchar* table);
UMat& ScanImageAndReduceIterator(UMat& I, const uchar* table);
UMat& ScanImageAndReduceRandomAccess(UMat& I, const uchar * table);

static const string WINDOW_NAME = "Display window";

int main(int argc, char** argv)
{
    help();

    //// For debugging.
    //namedWindow(WINDOW_NAME, WINDOW_AUTOSIZE);

    // Default values.
    string imageName("../../sample-data/HappyFish.jpg");
    int divideWith = 10;  // ??
    if (argc > 1)
    {
        imageName = argv[1];
        if (argc > 2) {
            divideWith = stoi(argv[2]);
        }
    }
    if (divideWith == 0)
    {
        cout << "Invalid number entered for dividing. " << endl;
        system("pause");
        return -1;
    }

    UMat I, J;
    I = imread(imageName, IMREAD_GRAYSCALE).getUMat(ACCESS_RW);
    // I = imread(imageName, IMREAD_COLOR).getUMat(ACCESS_RW);
    if (I.empty())
    {
        cerr << "Could not open or find the image" << endl;
        system("pause");
        return -1;
    }

    //imshow(WINDOW_NAME, I);
    //waitKey(0);

    uchar table[256];
    for (int i = 0; i < 256; ++i) {
        table[i] = (uchar)(divideWith * (i / divideWith));
    }

    const int times = 100;
    double t = (double)getTickCount();

    for (int i = 0; i < times; ++i)
    {
        UMat clone_i = I.clone();
        J = ScanImageAndReduceC(clone_i, table);
    }

    t = 1000 * ((double)getTickCount() - t) / getTickFrequency();
    t /= times;

    cout << "Time of reducing with the C operator [] (averaged for "
        << times << " runs): " << t << " milliseconds." << endl;

    t = (double)getTickCount();

    for (int i = 0; i < times; ++i)
    {
        UMat clone_i = I.clone();
        J = ScanImageAndReduceIterator(clone_i, table);
    }

    t = 1000 * ((double)getTickCount() - t) / getTickFrequency();
    t /= times;

    cout << "Time of reducing with the iterator (averaged for "
        << times << " runs): " << t << " milliseconds." << endl;

    //imshow(WINDOW_NAME, J);
    //waitKey(0);


    t = (double)getTickCount();

    for (int i = 0; i < times; ++i)
    {
        UMat clone_i = I.clone();
        ScanImageAndReduceRandomAccess(clone_i, table);
    }

    t = 1000 * ((double)getTickCount() - t) / getTickFrequency();
    t /= times;

    cout << "Time of reducing with the on-the-fly address generation - at function (averaged for "
        << times << " runs): " << t << " milliseconds." << endl;

    //! [table-init]
    Mat lookUpTable(1, 256, CV_8U);
    uchar* p = lookUpTable.ptr();
    for (int i = 0; i < 256; ++i) {
        p[i] = table[i];
    }
    //! [table-init]

    t = (double)getTickCount();

    for (int i = 0; i < times; ++i) {
        //! [table-use]
        LUT(I, lookUpTable, J);
        //! [table-use]
    }

    t = 1000 * ((double)getTickCount() - t) / getTickFrequency();
    t /= times;

    cout << "Time of reducing with the LUT function (averaged for "
        << times << " runs): " << t << " milliseconds." << endl;

    //imshow(WINDOW_NAME, J);
    //waitKey(0);

    system("pause");
    return 0;
}

//! [scan-c]
UMat& ScanImageAndReduceC(UMat& I, const uchar* const table)
{
    // accept only char type matrices
    CV_Assert(I.depth() == CV_8U);

    int channels = I.channels();

    int nRows = I.rows;
    int nCols = I.cols * channels;

    if (I.isContinuous())
    {
        nCols *= nRows;
        nRows = 1;
    }

    int i, j;
    uchar* p;
    Mat M = I.getMat(ACCESS_READ);
    for (i = 0; i < nRows; ++i)
    {
        p = M.ptr<uchar>(i);
        for (j = 0; j < nCols; ++j)
        {
            p[j] = table[p[j]];
        }
    }
    return I;
}
//! [scan-c]

//! [scan-iterator]
UMat& ScanImageAndReduceIterator(UMat& I, const uchar* const table)
{
    // accept only char type matrices
    CV_Assert(I.depth() == CV_8U);

    Mat M = I.getMat(ACCESS_READ);
    const int channels = I.channels();
    switch (channels)
    {
    case 1:
    {
        MatIterator_<uchar> it, end;
        for (it = M.begin<uchar>(), end = M.end<uchar>(); it != end; ++it) {
            *it = table[*it];
        }
        break;
    }
    case 3:
    {
        MatIterator_<Vec3b> it, end;
        for (it = M.begin<Vec3b>(), end = M.end<Vec3b>(); it != end; ++it)
        {
            (*it)[0] = table[(*it)[0]];
            (*it)[1] = table[(*it)[1]];
            (*it)[2] = table[(*it)[2]];
        }
    }
    }

    return I;
}
//! [scan-iterator]

//! [scan-random]
UMat& ScanImageAndReduceRandomAccess(UMat& I, const uchar* const table)
{
    // accept only char type matrices
    CV_Assert(I.depth() == CV_8U);

    Mat M = I.getMat(ACCESS_READ);
    const int channels = I.channels();
    switch (channels)
    {
    case 1:
    {
        for (int i = 0; i < I.rows; ++i)
            for (int j = 0; j < I.cols; ++j) {
                M.at<uchar>(i, j) = table[M.at<uchar>(i, j)];
            }
        break;
    }
    case 3:
    {
        Mat_<Vec3b> _I = M;

        for (int i = 0; i < I.rows; ++i)
            for (int j = 0; j < I.cols; ++j)
            {
                _I(i, j)[0] = table[_I(i, j)[0]];
                _I(i, j)[1] = table[_I(i, j)[1]];
                _I(i, j)[2] = table[_I(i, j)[2]];
            }
        I = _I.getUMat(ACCESS_READ);
        break;
    }
    }

    return I;
}
//! [scan-random]
