#include <opencv2/opencv.hpp>

enum Status { GOOD, BAD };

class Classifier {
public:
	Classifier(char* name);
	Status classify();
private:
	cv::Mat image;
};
