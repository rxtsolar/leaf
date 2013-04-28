#include <iostream>
#include <opencv2/opencv.hpp>
#include "svm.h"
#include "classifier.h"
#include "feature.h"

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	if (!argv[1])
		return -1;
	ColorFeature feature;
	Mat image = imread(argv[1]);
	feature.getFeature(image);
	feature.showFeature();
	feature.printFeature();
	return 0;
}
