#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

const char* origWindow = "original";

int main(int argc, char* argv[])
{
	//Mat image = imread(argv[1], CV_LOAD_IMAGE_COLOR);
	Mat image = imread(argv[1]);
	namedWindow(origWindow);
	imshow(origWindow, image);
	waitKey(0);
	return 0;
}
