#include <opencv2/opencv.hpp>
#include <vector>

enum Status { GOOD, BAD };

class Feature {
public:
	Feature() : bins(16) {}
	virtual ~Feature() {}
	virtual void getFeature(const cv::Mat& image) = 0;
	virtual void showFeature() const;
	void setBins(int b);
protected:
	int bins;
	std::vector<int> feat;
};

class ColorFeature : public Feature {
public:
	~ColorFeature() {}
	void getFeature(const cv::Mat& image);
private:
	void getHistHelper(const cv::Mat& image, int channel);
};

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
