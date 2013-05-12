#ifndef __TRAIN_H__
#define __TRAIN_H__

#include <string>
#include <vector>
#include "svm.h"

class Trainer {
public:
	Trainer();
	void loadFeature(char* name);
	void scaleFeature();
	void buildModel();
private:
	svm_parameter param;

	std::string featName;
	int featNr;
	int posNr;
	int negNr;
	/* (posNr + negNr) * featNr feature vector */
	std::vector<std::vector<double> > features;
};


#endif /* __TRAIN_H__ */
