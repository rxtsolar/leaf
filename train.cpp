#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include "train.h"

using namespace std;

Trainer::Trainer()
{
	// initialize param
	param.svm_type = C_SVC;
	param.kernel_type = RBF;
	param.degree = 3;
	param.gamma = 0.001;	// will be updated when reading feature file
	param.coef0 = 0;
	param.nu = 0.5;
	param.cache_size = 100;
	param.C = 100;
	param.eps = 1e-3;
	param.p = 0.1;
	param.shrinking = 1;
	param.probability = 0;
	param.nr_weight = 1;

	param.weight_label = (int *)malloc(sizeof(int) * param.nr_weight);
	param.weight = (double *)malloc(sizeof(double) * param.nr_weight);
	param.weight_label[param.nr_weight - 1] = 1;
	param.weight[param.nr_weight - 1] = 1;	// will be updated
}

void Trainer::loadFeature(char* name)
{
	int sampleNr;
	ifstream file(name);
	if (!file) {
		cerr << "cannot open file " << name << endl;
		return;
	}
	featName = string(name);

	file >> posNr >> negNr;
	sampleNr = posNr + negNr;
	features.clear();
	for (int i = 0; i < sampleNr; i++) {
		vector<double> tempv;
		double tempd;
		file >> featNr;
		for (int j = 0; j < featNr; j++) {
			file >> tempd;
			tempv.push_back(tempd);
		}
		features.push_back(tempv);
	}

	file.close();

	param.gamma = 1.0 / featNr;
	param.weight[param.nr_weight - 1] = 1.0 * negNr / posNr;
}

void Trainer::scaleFeature()
{
	string paramName = featName + ".params";
	ofstream file(paramName.c_str());
	int sampleNr = posNr + negNr;
	file << featNr << endl;
	for (int j = 0; j < featNr; j++) {
		double mean = 0;
		double stdev = 0;

		for (int i = 0; i < sampleNr; i++)
			mean += features[i][j];
		mean /= sampleNr;

		for (int i = 0; i < sampleNr; i++)
			stdev += pow((features[i][j] - mean), 2);
		stdev /= sampleNr;
		stdev = sqrt(stdev);

		for (int i = 0; i < sampleNr; i++)
			features[i][j] = (features[i][j] - mean) /
				(stdev + 0.000001);

		file << mean << ' ' << stdev << endl;
	}
	file.close();
}

void Trainer::buildModel()
{
	string modelName = featName + ".model";
	svm_problem prob;
	svm_model* model;
	int sampleNr = posNr + negNr;

	prob.l = sampleNr;
	prob.x = new svm_node*[sampleNr];
	prob.y = new double[sampleNr];
	for (int i = 0; i < sampleNr; i++) {
		prob.x[i] = new svm_node[featNr + 1];
		if (i < posNr)
			prob.y[i] = 1;
		else
			prob.y[i] = -1;
		for (int j = 0; j < featNr; j++) {
			prob.x[i][j].index = j + 1;
			prob.x[i][j].value = features[i][j];
		}
		prob.x[i][featNr].index = -1;
	}

	model = svm_train(&prob, &param);
	if (svm_save_model(modelName.c_str(), model)) {
		cerr << "cannot save model to file " << modelName << endl;
		exit(-1);
	}

	svm_free_and_destroy_model(&model);
	svm_destroy_param(&param);
	for (int i = 0; i < sampleNr; i++)
		delete[] prob.x[i];
	delete[] prob.x;
	delete[] prob.y;
}
