// CVTutor.Core.Mat02.cpp : Defines the entry point for the console application.
//

// Tutorial
// http://docs.opencv.org/3.1.0/d6/d6d/tutorial_mat_the_basic_image_container.html

#include "stdafx.h"

using namespace cv;
using namespace std;
using namespace cvtutor::core;


int main(int argc, char** argv)
{
	// Mat ctor.
	Mat M(2, 2, CV_8UC3, Scalar(0, 0, 255));
	cout << "M = " << endl << " " << M << endl << endl;
	system("pause");

	// Use C/C++ arrays and initialize via constructor
	int sz[3] = { 2,2,2 };
	Mat L(3, sz, CV_8UC(1), Scalar::all(0));
	// You can only cout print for 2D Mats.
	// cout << "L = " << endl << " " << L << endl << endl;
	cout << "L = " << endl << endl;
	system("pause");

	// cv::Mat::create function:
	M.create(4, 4, CV_8UC(2));
	cout << "M = " << endl << " " << M << endl << endl;
	system("pause");

	// MATLAB style initializers: cv::Mat::zeros , cv::Mat::ones , cv::Mat::eye
	Mat E = Mat::eye(4, 4, CV_64F);
	cout << "E = " << endl << " " << E << endl << endl;
	Mat O = Mat::ones(2, 2, CV_32F);
	cout << "O = " << endl << " " << O << endl << endl;
	Mat Z = Mat::zeros(3, 3, CV_8UC1);
	cout << "Z = " << endl << " " << Z << endl << endl;
	system("pause");

	// Comma separated initializer
	Mat C = (Mat_<double>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	cout << "C = " << endl << " " << C << endl << endl;
	system("pause");

	// cv::Mat::clone or cv::Mat::copyTo
	Mat RowClone = C.row(1).clone();
	cout << "RowClone = " << endl << " " << RowClone << endl << endl;
	system("pause");

	// Initialize Mat with random values.
	Mat R = Mat(3, 2, CV_8UC3);
	randu(R, Scalar::all(0), Scalar::all(255));
	cout << "R (default) = " << endl << " " << R << endl << endl;
	cout << "R (python)  = " << endl << format(R, Formatter::FMT_PYTHON) << endl << endl;
	cout << "R (csv)     = " << endl << format(R, Formatter::FMT_CSV) << endl << endl;
	cout << "R (numpy)   = " << endl << format(R, Formatter::FMT_NUMPY) << endl << endl;
	cout << "R (c)       = " << endl << format(R, Formatter::FMT_C) << endl << endl;
	system("pause");


	// Output of other common items

	Point2f P(5, 1);
	cout << "Point (2D) = " << P << endl << endl;
	system("pause");

	Point3f P3f(2, 6, 7);
	cout << "Point (3D) = " << P3f << endl << endl;
	system("pause");

	vector<float> v;
	v.push_back((float)CV_PI);   v.push_back(2);    v.push_back(3.01f);
	cout << "Vector of floats via Mat = " << Mat(v) << endl << endl;
	system("pause");

	vector<Point2f> vPoints(20);
	for (size_t i = 0; i < vPoints.size(); ++i)
		vPoints[i] = Point2f((float)(i * 5), (float)(i % 7));
	cout << "A vector of 2D Points = " << vPoints << endl << endl;
	system("pause");

	// system("pause");
	return 0;
}
