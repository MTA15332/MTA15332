#include "opencv2\core\core.hpp"
#include "opencv2\highgui.hpp"

using namespace std;
using namespace cv;

int main(){
	Mat image;
	image = imread("C:/Users/Dennis/Desktop/test", 1);
		if (image.data&& !image.empty()){ imshow("Hello world!", image); };

	waitKey();
}