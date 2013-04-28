#include <opencv2/opencv.hpp>
#include <vector>

enum Status { GOOD, BAD };

class Classifier {
public:
	Classifier(char* name);
	// main function
	Status classify();
	// helper functions
	void loadImage(char* name);
	void showImage();
	void setBins(int b);
	// histogram related
	void getHist(); // this is based on the loaded image
	void showHist();
private:
	cv::Mat image;
	std::vector<int> hist;
	int bins;

	void getHistHelper(int channel);
};
