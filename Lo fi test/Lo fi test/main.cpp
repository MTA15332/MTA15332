#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/opencv.hpp>
#include "opencv2\imgproc\imgproc.hpp"
#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <random>
using namespace std;
using namespace cv;


//int resX = GetSystemMetrics(SM_CXSCREEN);
//int resY = GetSystemMetrics(SM_CYSCREEN);
int resX = 800;
int resY = 800;
int filenumber = 1;
random_device rdx;
random_device rdy;
mt19937 randx(rdx());
mt19937 randy(rdy());
uniform_int_distribution<> randomX(1, resX);
uniform_int_distribution<> randomY(1, resY);
Mat img = Mat::zeros(resY, resX, CV_64F);
int pointX = randomX(randx);
int pointY = randomY(randy);
void drawCircle(){
	if (pointX > resX - 50){
		pointX = pointX - 50;
	}
	if (pointY > resY - 50){
		pointY = pointY - 50;
	}
	if (pointX < 50){
		pointX = pointX + 50;
	}
	if (pointY < 50){
		pointY = pointY + 50;
	}
	int radius = 100;
	int cPx = pointX;
	int cPy = pointY;
	for (int i = 1; i <= 3; i++){
		if (i == 3){
			i++;
		}
		circle(img, Point(cPx, cPy), radius / i, Scalar(255, 255, 255), 2, 8, 0);
	}
}
void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
	
	if (event == EVENT_LBUTTONDOWN)
	{
		if (pointX > resX - 50){
			pointX = pointX - 50;
		}
		if (pointY > resY - 50){
			pointY = pointY - 50;
		}
		if (pointX < 50){
			pointX = pointX + 50;
		}
		if (pointY < 50){
			pointY = pointY + 50;
		}
		int distx;
		int disty;
		double dist;
		if ((x - (pointX)) < 0){
			distx = (x - (pointX)) * -1;
		}
		else{
			distx = x - (pointX);
		}
		if ((y - (pointY)) < 0){
			disty = (y - (pointY)) * -1;
		}
		else{
			disty = y - (pointY);
		}
		ostringstream name;
		ostringstream namedist;
		name << "C:/Users/Christian/Desktop/lofitest/lofitestpic" << filenumber << ".png";
		
		dist = sqrt(distx*distx) + sqrt(disty*disty);
		namedist << "Distance from center: " << dist;
		cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
		cout << "Distance from center: " << dist << endl;
		putText(img, namedist.str(), cvPoint(30, 30), FONT_HERSHEY_COMPLEX, 0.8, (255, 255, 255), 1, CV_AA);
		line(img, Point(x, y), Point(pointX, pointY), Scalar(255, 255, 255), 2, 8, 0);
		namedWindow("Distance to center", CV_WINDOW_AUTOSIZE);
		imshow("Distance to center", img);
		
		imwrite(name.str(), img);
		filenumber++;
		img = Mat::zeros(resX, resY, CV_64F);
		pointX = randomX(randx);
		pointY = randomY(randy);
		drawCircle();
		namedWindow("ImageDisplay", CV_WINDOW_AUTOSIZE);
		imshow("ImageDisplay", img);
		
		
	}
}

int main(int argc, char** argv)
{


	//if fail to read the image
	if (img.empty())
	{
		cout << "Error loading the image" << endl;
		return -1;
	}
	
	
	

	//Create a window
	namedWindow("ImageDisplay", CV_WINDOW_AUTOSIZE);

	//set the callback function for any mouse event
	setMouseCallback("ImageDisplay", CallBackFunc, NULL);


	drawCircle();
	
	waitKey(20);

	
	imshow("ImageDisplay", img);
	cout << "The center is X: " << pointX << " Y: " << pointY << endl;

	// Wait until user press some key
	waitKey(0);

	return 0;
}


