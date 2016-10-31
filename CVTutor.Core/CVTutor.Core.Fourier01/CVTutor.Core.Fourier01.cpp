// CVTutor.Core.Fourier01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace cv;
using namespace std;
using namespace cvtutor::core;


// Tutorial
// http://docs.opencv.org/3.1.0/d8/d01/tutorial_discrete_fourier_transform.html


static const string WINDOW_NAME = "Display window";

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		cout << " Usage: requires image arg." << endl;
		system("pause");
		return -1;
	}

	// For debugging.
	namedWindow(WINDOW_NAME, WINDOW_AUTOSIZE);


	// tbd:
	// ....




	// system("pause");
	return 0;
}
