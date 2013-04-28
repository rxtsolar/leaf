#include "classifier.h"

using namespace cv;
using namespace std;

Classifier::Classifier(char* name)
{
	bins = 16;
	image = imread(name);
}

Status Classifier::classify()
{
	// TODO: needs more implementation
	return BAD;
}

void Classifier::loadImage(char* name)
{
	image = imread(name);
}

void Classifier::showImage()
{
	namedWindow("test");
	imshow("test", image);
	waitKey(0);
}

// default is 16
void Classifier::setBins(int b)
{
	bins = b;
}

void Classifier::getHistHelper(int channel)
{
	MatND histM;
	int histSize[1];
	float hranges[2];
	const float* ranges[1];
	int channels[1];

	histSize[0] = bins;
	hranges[0] = 0.0;
	hranges[1] = 255.0;
	ranges[0] = hranges;
	channels[0] = channel;

	calcHist(&image, 1, channels, Mat(), histM, 1, histSize, ranges);
	for (int i = 0; i < bins; i++)
		hist.push_back(static_cast<int>(histM.at<float>(i)));
}

// This function get histogram for R, G, B channel separately and concatenate
// them together to "hist"
void Classifier::getHist()
{
	hist.clear();
	for (int i = 0; i < 3; i++)
		getHistHelper(i);
}

void Classifier::showHist()
{
	int height = 600;
	int width = 800;
	double maxVal = 0;
	int hpt = static_cast<int>(0.9 * height);
	int size = hist.size();
	int span = width / size;

	for (int i = 0; i < size; i++)
		if (hist[i] > maxVal)
			maxVal = hist[i];
	Mat histImage(height, width, CV_8U, Scalar(255));
	for (int i = 0; i < size; i++) {
		float binVal = hist[i];
		int intensity = static_cast<int>(binVal * hpt / maxVal);
		for (int j = 0; j < span - 1; j++) {
			line(histImage, Point(i * span + j, height),
					Point(i * span + j, height - intensity),
					Scalar::all(0));
		}
	}

	namedWindow("hist");
	imshow("hist", histImage);
	waitKey(0);
}
