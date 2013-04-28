#include "classifier.h"

using namespace cv;

Classifier::Classifier(char* name)
{
	image = imread(name);
}

Status Classifier::classify()
{
	namedWindow("test");
	imshow("test", image);
	waitKey(0);
	return BAD;
}
