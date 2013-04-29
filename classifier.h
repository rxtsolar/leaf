#ifndef __CLASSIFIER_H__
#define __CLASSIFIER_H__

#include <opencv2/opencv.hpp>
#include <vector>

enum Status { GOOD, BAD };

class Classifier {
public:
	Classifier(const char* name);
	// main function
	Status classify();
	// helper functions
	void loadImage(const char* name);
	void showImage() const;
private:
	cv::Mat image;
};


#endif /* __CLASSIFIER_H__ */
