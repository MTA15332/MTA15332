#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
using namespace cv;
void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
	if (event == EVENT_LBUTTONDOWN)
	{
		cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
	}
}
int main(int argc, char** argv)
{
	// Read image from file 
	Mat img = imread("C:/Users/Dennis/Desktop/test2.png",CV_LOAD_IMAGE_COLOR);

	//if fail to read the image
	if (img.empty())
	{
		cout << "Error loading the image" << endl;
		return -1;
	}

	//Create a window
	namedWindow("ImageDisplay", CV_WINDOW_NORMAL);

	//set the callback function for any mouse event
	setMouseCallback("ImageDisplay", CallBackFunc, NULL);

	//show the image
	imshow("ImageDisplay", img);

	// Wait until user press some key
	waitKey(0);

	return 0;
}