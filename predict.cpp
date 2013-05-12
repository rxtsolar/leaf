#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include "predict.h"

using namespace std;

Predictor::~Predictor()
{
	if (model)
		svm_free_and_destroy_model(&model);
}

void Predictor::loadModel(char* name)
{
	string modelName;
	string paramName;
	ifstream file;
	double tempm;
	double temps;

	featName = string(name);
	modelName = featName + ".model";
	paramName = featName + ".params";

	file.open(paramName.c_str());
	if (!file) {
		cerr << "cannot open parameter file: " << paramName << endl;
		exit(-1);
	}
	file >> featNr;

	means.clear();
	stdev.clear();
	for (int j = 0; j < featNr; j++) {
		file >> tempm >> temps;
		means.push_back(tempm);
		stdev.push_back(temps);
	}

	file.close();

	model = svm_load_model(modelName.c_str());
	if (!model) {
		cerr << "cannot open model file: " << modelName << endl;
		exit(-1);
	}
}

void Predictor::readFeature()
{
	cin >> featNr;
	
	for (int j = 0; j < featNr; j++) {
		double tempd;
		cin >> tempd;
		tempd = (tempd - means[j]) / (stdev[j] + 0.000001);
		feature.push_back(tempd);
	}
}

int Predictor::predict()
{
	svm_node* x;
	double label;

	x = new svm_node[featNr + 1];

	for (int j = 0; j < featNr; j++) {
		x[j].index = j + 1;
		x[j].value = feature[j];
	}

	x[featNr].index = -1;
	x[featNr].value = 0;

	// use svm_predict_values(model, x, &value) if needed
	label = svm_predict(model, x);

	delete[] x;

	return label;
}
