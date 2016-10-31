// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the CVTUTORCORECOMMONLIB_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// CVTUTORCORECOMMONLIB_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef CVTUTORCORECOMMONLIB_EXPORTS
#define CVTUTORCORECOMMONLIB_API __declspec(dllexport)
#else
#define CVTUTORCORECOMMONLIB_API __declspec(dllimport)
#endif

// This class is exported from the CVTutor.Core.CommonLib.dll
class CVTUTORCORECOMMONLIB_API CCVTutorCoreCommonLib {
public:
	CCVTutorCoreCommonLib(void);
	// TODO: add your methods here.
};

extern CVTUTORCORECOMMONLIB_API int nCVTutorCoreCommonLib;

CVTUTORCORECOMMONLIB_API int fnCVTutorCoreCommonLib(void);


namespace cvtutor
{
	namespace core
	{
		CVTUTORCORECOMMONLIB_API void displayImageForDebugTracing(std::string windowName, cv::Mat image);

	}
}
