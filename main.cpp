#include <iostream>
#include <opencv2/opencv.hpp>
#include "classifier.h"
#include "feature.h"
#include "train.h"
#include "predict.h"

using namespace std;
using namespace cv;

//int main(int argc, char* argv[])
//{
	//if (!argv[1])
		//return -1;
	//Trainer trainer;
	//trainer.loadFeature(argv[1]);
	//trainer.scaleFeature();
	//trainer.buildModel();
	//return 0;
//}

int main(int argc, char* argv[])
{
	int result;

	if (!argv[1])
		return -1;
	Predictor predictor;
	predictor.loadModel(argv[1]);
	predictor.readFeature();
	result = static_cast<int>(predictor.predict());
	if (result == 1)
		cout << "positive" << endl;
	else if (result == -1)
		cout << "negative" << endl;
	else
		cout << "unknown" << endl;

	return 0;
}
