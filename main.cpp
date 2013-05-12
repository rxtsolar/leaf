#include <iostream>
#include <opencv2/opencv.hpp>
#include "classifier.h"
#include "feature.h"
#include "train.h"

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	if (!argv[1])
		return -1;
	Trainer trainer;
	trainer.loadFeature(argv[1]);
	trainer.scaleFeature();
	trainer.buildModel();
	return 0;
}
