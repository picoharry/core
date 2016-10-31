// CVTutor.Core.CommonLib.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "CVTutor.Core.CommonLib.h"


using namespace std;
using namespace cv;

// This is an example of an exported variable
CVTUTORCORECOMMONLIB_API int nCVTutorCoreCommonLib=0;

// This is an example of an exported function.
CVTUTORCORECOMMONLIB_API int fnCVTutorCoreCommonLib(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see CVTutor.Core.CommonLib.h for the class definition
CCVTutorCoreCommonLib::CCVTutorCoreCommonLib()
{
    return;
}


CVTUTORCORECOMMONLIB_API void cvtutor::core::displayImageForDebugTracing(string windowName, Mat image)
{
	// cout << "Image = " << endl << " " << image << endl << endl;

	imshow(windowName, image);
	waitKey(0);
}

