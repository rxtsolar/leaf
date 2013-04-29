#ifndef __FEATURE_H__
#define __FEATURE_H__

#include <opencv2/opencv.hpp>
#include <vector>

class Feature {
public:
	virtual ~Feature() {}
	virtual void getFeature(const cv::Mat& image) = 0;
	virtual void showFeature() const;
	virtual void printFeature() const;
	void setBins(int b);
protected:
	std::vector<int> feat;
};

class ColorFeature : public Feature {
public:
	ColorFeature() : bins(16) {}
	~ColorFeature() {}
	void getFeature(const cv::Mat& image);
	void setBins(int b);
private:
	int bins;
	void getHistHelper(const cv::Mat& image, int channel);
};


#endif /* __FEATURE_H__ */
