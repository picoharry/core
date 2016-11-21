// CVTutor.Core.Mat01.cpp : Defines the entry point for the console application.
//

// Tutorial
// http://docs.opencv.org/3.1.0/d6/d6d/tutorial_mat_the_basic_image_container.html

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

	Mat A, C;                          // creates just the header parts
	A = imread(imageName, IMREAD_COLOR); // here we'll know the method used (allocate matrix)
	if (!A.data) // Check for invalid input
	{
		cout << "Could not open or find the image" << endl;
		system("pause");
		return -1;
	}
	// cout << "A = " << endl << " " << A << endl << endl;
	displayImageForDebugTracing(WINDOW_NAME, A);


	// The copy operators will only copy the headers and the pointer to the large matrix, not the data itself.

	Mat B(A);                                 // Use the copy constructor
	// cout << "B = " << endl << " " << B << endl << endl;
	displayImageForDebugTracing(WINDOW_NAME, B);

	C = A;                                    // Assignment operator
	// cout << "C = " << endl << " " << C << endl << endl;
	displayImageForDebugTracing(WINDOW_NAME, C);

	// To create a region of interest (ROI) in an image you just create a new header with the new boundaries:

	Mat D(A, Rect(10, 10, 100, 100)); // using a rectangle
	// cout << "D = " << endl << " " << D << endl << endl;
	displayImageForDebugTracing(WINDOW_NAME, D);

	Mat E = A(Range::all(), Range(1, 3)); // using row and column boundaries
	// cout << "E = " << endl << " " << E << endl << endl;
	displayImageForDebugTracing(WINDOW_NAME, E);

	// You can copy the matrix itself too

	Mat F = A.clone();
	// cout << "F = " << endl << " " << F << endl << endl;
	displayImageForDebugTracing(WINDOW_NAME, F);

	Mat G;
	A.copyTo(G);
	// cout << "G = " << endl << " " << G << endl << endl;
	displayImageForDebugTracing(WINDOW_NAME, G);

	// system("pause");
	return 0;
}
