#include <iostream>
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <math.h>

using namespace std;
using namespace cv;

Mat src = imread("C:/Ceemple/OpenCV4VS/samples/data/starry_night.jpg", 0);
float Bx; // amount of shearing in x-axis
float By; // amount of shearing in y-axis

int backwardmapping(int rows,int cols, float Bx,float By){
	int r1, c1;
	int maxXOffset = cols * Bx; //integer used to calculate how much the output image can be offset in the x axis, this is dependant on the shearing value of Bx
	int maxYOffset = rows * By; //integer used to calculate how much the output image can be offset in the y axis, this is dependant on the shearing value of By

	Mat BMout = Mat::zeros(src.rows + maxYOffset, src.cols + maxXOffset, src.type()); // Creation of the out images matrix

	for (int r = 0; r < BMout.rows; r++) // The Backward mapping loop, here we take the y axis representted by the rows
	{
		for (int c = 0; c < BMout.cols; c++) // Here is the x axis represented by the columns
		{
			r1 = abs(r + c * By - maxYOffset); // Calculation to find the points new position.
			c1 = abs(r * Bx + c - maxXOffset);

			if (r1 >= 0 && r1 < rows && c1 >= 0 && c1 < cols) // If statement to check whether or not the image will be within the boundary
			{
				BMout.at<uchar>(r, c) = src.at<uchar>(r1, c1); // set value of the new point

			}

		}
	}

	//Here we create the windows where in we are going to show our backward sheared image
	namedWindow("Backward Sheared image",CV_WINDOW_NORMAL);
	
	imshow("Backward Sheared image", BMout);
	waitKey(0);
	return(0);
	
}

//most of the code here is very similar to the Backward mapping function

int forwardmapping(int cols,int rows,float Bx,float By){
	int maxXOffset = cols * Bx;
	int maxYOffset = rows * By;

	Mat FMout = Mat::zeros(src.rows + maxYOffset, src.cols + maxXOffset, src.type()); // Creation of the out images matrix

	for (int r = 0; r < src.rows; r++) // The forward mapping loop
	{
		for (int c = 0; c < src.cols; c++)
		{
			int r1, c1;
			r1 = abs(r + c * By - maxYOffset); // Calculation to find the points new position
			c1 = abs(r * Bx + c - maxXOffset);

			if (r1 >= 0 && r1 < rows && c1 >= 0 && c1 < cols) // If statement to check whether or not the image will be within the boundary
			{
				FMout.at<uchar>(r1, c1) = src.at<uchar>(r, c); // set value of the new point

			}

		}
	}


	namedWindow("Forward Sheared image", CV_WINDOW_NORMAL);

	imshow("Forward Sheared image", FMout);
	waitKey(0);
	return(0);
}

int main()
{

	if (src.empty()){ // Here we check if the image is loaded properly. if not then display a message informing the user
		cout << "Error: Loading image" << endl;
	}
	else // Here if the image is loaded we run the program
	{

		cout << "Amount to shear in the x-axis" << endl; // We start with asking the user to give the ratio they want to shear with.
		cin >> Bx;
		cout << endl;
		cout << "Amount to shear in the y-axis" << endl;
		cin >> Bx;
		cout << endl;

		namedWindow("Source image", CV_WINDOW_NORMAL);
		imshow("Source image", src);

		backwardmapping(src.rows, src.cols, Bx, By); // Calling the function for the backwardmapping, inserting the source image rows and columns

		forwardmapping(src.rows, src.cols, Bx, By);

		waitKey(0);

		return 0;
	}


}