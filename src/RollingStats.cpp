#include "RollingStats.h"

RollingStats::RollingStats() {
}

void RollingStats::addDataToRollingStore(STAT_TYPE type, double inputData) {
	std::vector<double>& dataStore = this->dsMeanStd_;
	int& period = this->PERIOD_MEANSTD;

	if (type == MEANSTD) {
		dataStore = this->dsMeanStd_;
		period = this->PERIOD_MEANSTD;
	}
	else if (type == EMA) {
		dataStore = this->dsEMA_;
		period = this->PERIOD_EMA;
	}
	else {
		return;
	}

	dataStore.push_back(inputData);

	if (int(dataStore.size()) > period) {
		dataStore.erase(dataStore.begin());
	}

	return;
}

double RollingStats::calculateMean() {
	double sum = 0.0;
	for (auto &i: this->dsMeanStd_) {
		sum += i;

#ifdef MA_DEBUG
		std::cout << "val," << i
			<< ",sum," << sum
			<< ",size," << this->dsMeanStd_.size()
		<< std::endl;
#endif
	}

	double mean = sum / static_cast<double>(this->dsMeanStd_.size());

	return mean;
}

double RollingStats::calculateStd() {
	double sumSquaredDiff = 0.0;
	double currentMean = this->getRollingMean();

	for (auto &i: this->dsMeanStd_) {
		double currDiff = i - currentMean;
		sumSquaredDiff += currDiff * currDiff;
	}

	return sqrt(sumSquaredDiff / static_cast<double>(this->dsMeanStd_.size() - 1));
}

double RollingStats::calculateEma() {

	return 0.0;
}

void RollingStats::performAllCalculations() {
	this->mean_ = this->calculateMean();
	this->std_ = this->calculateStd();
	this->ema_ = this->calculateEma();

	return;
}

void RollingStats::performCalculations(STAT_TYPE type) {
	if (type == MEANSTD) {
		this->mean_ = this->calculateMean();
		this->std_ = this->calculateStd();
	}
	else if (type == EMA) {
		this->ema_ = this->calculateEma();
	}
}

void RollingStats::addDataAndPerformCalculations(STAT_TYPE type, double data) {
	this->addDataToRollingStore(type, data);
	this->performCalculations(type);
}

double RollingStats::getRollingMean() {
	return this->mean_;
}

double RollingStats::getRollingStd() {
	return this->std_;
}

double RollingStats::getRollingEma() {
	return this->ema_;
}

void RollingStats::setPeriod(STAT_TYPE type, int inputPeriod) {
	if (type == MEANSTD) {
		this->PERIOD_MEANSTD = inputPeriod;
	}
	else if (type == EMA) {
		this->PERIOD_EMA = inputPeriod;
	}
}

