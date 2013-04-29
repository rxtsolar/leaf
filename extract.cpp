#include <iostream>
#include <cstring>
#include "feature.h"

using namespace std;
using namespace cv;

void error()
{
	cerr << "usage: ./extract <image_name> <feature_name>" << endl;
	cerr << "	[feature_name]	[feature]" << endl;
	cerr << "	color		color histogram" << endl;
}

int main(int argc, char* argv[])
{
	if (argc < 3) {
		cerr << "too few arguments" << endl;
		error();
		return -1;
	}

	Mat image = imread(argv[1]);
	Feature* feature;
	if (!strcmp(argv[2], "color")) {
		feature = new ColorFeature();
	} else {
		cerr << "unsupported feature" << endl;
		error();
		return -1;
	}

	feature->getFeature(image);
	feature->printFeature();
	delete feature;

	return 0;
}
