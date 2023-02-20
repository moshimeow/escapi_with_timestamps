/* Extremely Simple Capture API */
#pragma once
#include <mfapi.h>
#include <mfidl.h>
#include <mfreadwrite.h>
#include <mferror.h>

struct SimpleCapParams
{
	/* Target buffer. 
	 * Must be at least mWidth * mHeight * sizeof(int) of size! 
	 */
	int * mTargetBuf;
	/* Buffer width */
	int mWidth;
	/* Buffer height */
	int mHeight;
};

enum CAPTURE_PROPETIES
{
	CAPTURE_BRIGHTNESS,
	CAPTURE_CONTRAST,
	CAPTURE_HUE,
	CAPTURE_SATURATION,
	CAPTURE_SHARPNESS,
	CAPTURE_GAMMA,
	CAPTURE_COLORENABLE,
	CAPTURE_WHITEBALANCE,
	CAPTURE_BACKLIGHTCOMPENSATION,
	CAPTURE_GAIN,
	CAPTURE_PAN,
	CAPTURE_TILT,
	CAPTURE_ROLL,
	CAPTURE_ZOOM,
	CAPTURE_EXPOSURE,
	CAPTURE_IRIS,
	CAPTURE_FOCUS,
	CAPTURE_PROP_MAX
};


/* Sets up the ESCAPI DLL and the function pointers below. Call this first! */
/* Returns number of capture devices found (same as countCaptureDevices, below) */
int setupESCAPI();
struct SimpleCapParams gParams[];
int gDoCapture[];
int gOptions[];

HRESULT InitDevice(int device);
void CleanupDevice(int device);
int CountCaptureDevices();
void GetCaptureDeviceName(int deviceno, char * namebuffer, int bufferlength);
void CheckForFail(int device);
int GetErrorCode(int device);
int GetErrorLine(int device);
float GetProperty(int device, int prop);
int GetPropertyAuto(int device, int prop);
int SetProperty(int device, int prop, float value, int autoval);
void initCOM();


int initCapture(unsigned int deviceno, struct SimpleCapParams *aParams);
void deinitCapture(unsigned int deviceno);
void  doCapture(unsigned int deviceno);
int  isCaptureDone(unsigned int deviceno);



/* Gets value (0..1) of a camera property (see CAPTURE_PROPERTIES, above) */
typedef float (*getCapturePropertyValueProc)(unsigned int deviceno, int prop);
/* Gets whether the property is set to automatic (see CAPTURE_PROPERTIES, above) */
typedef int(*getCapturePropertyAutoProc)(unsigned int deviceno, int prop);
/* Set camera property to a value (0..1) and whether it should be set to auto. */
typedef int (*setCapturePropertyProc)(unsigned int deviceno, int prop, float value, int autoval);

/*
	All error situations in ESCAPI are considered catastrophic. If such should
	occur, the following functions can be used to check which line reported the
	error, and what the HRESULT of the error was. These may help figure out
	what the problem is.
*/

/* Return line number of error, or 0 if no catastrophic error has occurred. */
typedef int (*getCaptureErrorLineProc)(unsigned int deviceno);
/* Return HRESULT of the catastrophic error, or 0 if none. */
typedef int (*getCaptureErrorCodeProc)(unsigned int deviceno);

/* initCaptureWithOptions allows additional options to be given. Otherwise it's identical with initCapture
*/
typedef int (*initCaptureWithOptionsProc)(unsigned int deviceno, struct SimpleCapParams *aParams, unsigned int aOptions);

// Options accepted by above:
// Return raw data instead of converted rgb. Using this option assumes you know what you're doing.
#define CAPTURE_OPTION_RAWDATA 0
// Mask to check for valid options - all options OR:ed together.
#define CAPTURE_OPTIONS_MASK (CAPTURE_OPTION_RAWDATA) 
