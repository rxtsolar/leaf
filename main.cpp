#include <iostream>
#include <opencv2/opencv.hpp>
#include "svm.h"
#include "classifier.h"

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	if (!argv[1])
		return -1;
	Feature* feature = new ColorFeature();
	Mat image = imread(argv[1]);
	feature->getFeature(image);
	feature->showFeature();
	delete feature;
	return 0;
}
