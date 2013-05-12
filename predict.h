#ifndef __PREDICT_H__
#define __PREDICT_H__

#include <string>
#include <vector>
#include "svm.h"
#include "feature.h"

struct Predictor {
public:
	~Predictor();
	void loadModel(char* name);
	void readFeature();
	int predict();
private:
	std::string featName;
	int featNr;
	std::vector<double> means;
	std::vector<double> stdev;
	std::vector<double> feature;
	svm_model* model;
};

#endif /* __PREDICT_H__ */
