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
	Classifier classifier(argv[1]);
	Status status = classifier.classify();
	switch (status) {
	case GOOD:
		cout << "good" << endl;
		break;
	case BAD:
		cout << "bad" << endl;
		break;
	default:
		cout << "unknown" << endl;
		break;
	}
	return 0;
}
