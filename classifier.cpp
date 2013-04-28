#include "classifier.h"

using namespace cv;
using namespace std;

Classifier::Classifier(const char* name)
{
	image = imread(name);
}

Status Classifier::classify()
{
	// TODO: needs more implementation
	return BAD;
}

void Classifier::loadImage(const char* name)
{
	image = imread(name);
}

void Classifier::showImage() const
{
	namedWindow("test");
	imshow("test", image);
	waitKey(0);
}
