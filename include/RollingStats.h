#ifndef MEANDEV_H
#define MEANDEV_H

#include <vector>
#include <cmath>

#ifdef MA_DEBUG
#include <iostream>
#endif

class RollingStats {
private:
	std::vector<double> dsMeanStd_, dsEMA_;

	int PERIOD_MEANSTD = 5;
	int PERIOD_EMA = 5;

	double mean_ = 0.0;
	double std_ = 0.0;
	double ema_ = 0.0;

public:
	enum STAT_TYPE {
		MEANSTD,
		EMA
	};

	RollingStats();

	void addDataToRollingStore(STAT_TYPE type, double data);
	void performCalculations(STAT_TYPE type);
	void performAllCalculations();
	void addDataAndPerformCalculations(STAT_TYPE type, double data);
	double calculateMean();
	double calculateStd();
	double calculateEma();

	double getRollingMean();
	double getRollingStd();
	double getRollingEma();

	void setPeriod(STAT_TYPE type, int input);
};

#endif /* MEANDEV_H */
