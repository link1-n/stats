#include "MovingAverage.h"

#include <iostream>

int main() {
	double emaSpan = 10.0;
	double smaPeriod = 3.0;
	SimpleMovingAverage sma(smaPeriod);
	ExponentialMovingAverage ema(emaSpan);

	sma.addDataAndCalculateMA(10.0);
	sma.addDataAndCalculateMA(15.0);
	sma.addDataAndCalculateMA(20.0);
	sma.addDataAndCalculateMA(25.0);
	sma.addDataAndCalculateMA(12.0);
	sma.addDataAndCalculateMA(34.0);
	sma.addDataAndCalculateMA(67.0);
	sma.addDataAndCalculateMA(89.0);
	sma.addDataAndCalculateMA(111.0);
	sma.addDataAndCalculateMA(2.0);
	std::cout
		<< "sma1," << sma.getMA()
		<< ",period," << smaPeriod
		<< std::endl;

	ema.addDataAndCalculateMA(10.0);
	ema.addDataAndCalculateMA(15.0);
	ema.addDataAndCalculateMA(20.0);
	ema.addDataAndCalculateMA(25.0);
	ema.addDataAndCalculateMA(12.0);
	ema.addDataAndCalculateMA(34.0);
	ema.addDataAndCalculateMA(67.0);
	ema.addDataAndCalculateMA(89.0);
	ema.addDataAndCalculateMA(111.0);
	ema.addDataAndCalculateMA(2.0);
	std::cout
		<< "ema1," << ema.getMA()
		<< ",span," << emaSpan
		<< std::endl;

	return 0;
}

//10.0, 15.0, 20.0, 25.0, 12.0, 34.0, 67.0, 89.0, 111.0, 2.0
