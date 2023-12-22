#include <vector>
#include <cmath>


class MeanDev {
private:
	std::vector<double> dataStore_;
	int PERIOD = 5;

	double mean_ = 0.0;
	double std_ = 0.0;

public:
	MeanDev(int inputPeriod);
	MeanDev();

	void addDataToRollingStore(double data);
	void performCalculations();
	void addDataAndPerformCalculations(double data);
	double calculateMean();
	double calculateStd();

	double getRollingMean();
	double getRollingStd();
};
