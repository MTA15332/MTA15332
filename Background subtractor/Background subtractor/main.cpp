#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;


int main() {
	VideoCapture cap(0); //capture the video from web cam

	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the web cam" << endl;
		return -1;
	}


	Mat frame, mask, thresholdImage, output;
	int frameNum = 0;

	Ptr<BackgroundSubtractor> pMOG2 = createBackgroundSubtractorMOG2(20, 16, true);
	while (true) {
		cap >> frame;
		++frameNum;
		pMOG2->apply(frame, mask, 0.001);

		cout << frameNum << endl;
		imshow("mask", mask);
		waitKey(10);
	}
	return 0;
}