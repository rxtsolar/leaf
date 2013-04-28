#include "classifier.h"

using namespace cv;
using namespace std;

void ColorFeature::getHistHelper(const Mat& image, int channel)
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
		feat.push_back(static_cast<int>(histM.at<float>(i)));
}

void ColorFeature::getFeature(const Mat& image)
{
	feat.clear();
	for (int i = 0; i < 3; i++)
		getHistHelper(image, i);
}

void Feature::showFeature() const
{
	int height = 600;
	int width = 800;
	double maxVal = 0;
	int hpt = static_cast<int>(0.9 * height);
	int size = feat.size();
	int span = width / size;

	for (int i = 0; i < size; i++)
		if (feat[i] > maxVal)
			maxVal = feat[i];
	Mat featImage(height, width, CV_8U, Scalar(255));
	for (int i = 0; i < size; i++) {
		float binVal = feat[i];
		int intensity = static_cast<int>(binVal * hpt / maxVal);
		for (int j = 0; j < span - 1; j++) {
			line(featImage, Point(i * span + j, height),
					Point(i * span + j, height - intensity),
					Scalar::all(0));
		}
	}

	namedWindow("feat");
	imshow("feat", featImage);
	waitKey(0);
}

void Feature::setBins(int b)
{
	bins = b;
}

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
