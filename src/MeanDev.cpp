#include "MeanDev.h"

MeanDev::MeanDev(int inputPeriod) {
	this->PERIOD = inputPeriod;
}

void MeanDev::addDataToRollingStore(double inputData) {
	this->dataStore_.push_back(inputData);

	if (int(this->dataStore_.size()) > this->PERIOD) {
		this->dataStore_.erase(this->dataStore_.begin());
	}
	return;
}

double MeanDev::calculateMean() {
	double sum = 0.0;
	for (auto &i: this->dataStore_) {
		sum += i;
	}

	double mean = sum / static_cast<double>(this->dataStore_.size());

	return mean;
}

double MeanDev::calculateStd() {
	double sumSquaredDiff = 0.0;
	double currentMean = this->getRollingMean();

	for (auto &i: this->dataStore_) {
		double currDiff = i - currentMean;
		sumSquaredDiff += currDiff * currDiff;
	}

	return sqrt(sumSquaredDiff / static_cast<double>(this->dataStore_.size() - 1));
}

void MeanDev::performCalculations() {
	this->mean_ = this->calculateMean();
	this->std_ = this->calculateStd();

	return;
}

void MeanDev::addDataAndPerformCalculations(double data) {
	this->addDataToRollingStore(data);
	this->performCalculations();
}

double MeanDev::getRollingMean() {
	return this->mean_;
}

double MeanDev::getRollingStd() {
	return this->std_;
}

