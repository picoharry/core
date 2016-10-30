// CVTutor.Core.Mat01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace cv;
using namespace std;

// Tutorial
// http://docs.opencv.org/master/d6/d6d/tutorial_mat_the_basic_image_container.html

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		cout << " Usage: requires image arg." << endl;
		return -1;
	}

	Mat A, C;                          // creates just the header parts
	A = imread(argv[1], IMREAD_COLOR); // here we'll know the method used (allocate matrix)
	if (!A.data) // Check for invalid input
	{
		cout << "Could not open or find the image" << endl;
		return -1;
	}
	// cout << "A = " << endl << " " << A << endl << endl;

	namedWindow("Display window", WINDOW_AUTOSIZE);
	imshow("Display window", A);
	waitKey(0);

	Mat B(A);                                 // Use the copy constructor
	// cout << "B = " << endl << " " << B << endl << endl;
	imshow("Display window", B);
	waitKey(0);

	C = A;                                    // Assignment operator
	// cout << "C = " << endl << " " << C << endl << endl;
	imshow("Display window", C);
	waitKey(0);

	Mat D(A, Rect(10, 10, 100, 100)); // using a rectangle
	// cout << "D = " << endl << " " << D << endl << endl;
	imshow("Display window", D);
	waitKey(0);

	Mat E = A(Range::all(), Range(1, 3)); // using row and column boundaries
	// cout << "E = " << endl << " " << E << endl << endl;
	imshow("Display window", E);
	waitKey(0);

	Mat F = A.clone();
	// cout << "F = " << endl << " " << F << endl << endl;
	imshow("Display window", F);
	waitKey(0);

	Mat G;
	A.copyTo(G);
	// cout << "G = " << endl << " " << G << endl << endl;
	imshow("Display window", G);
	waitKey(0);

	// system("pause");
	return 0;
}
