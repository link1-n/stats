#include "MovingAverage.h"

#include <iostream>

int main() {
	SimpleMovingAverage<double> sma(3);

	sma.addData(10.0);
	sma.addData(15.0);
	sma.addData(20.0);
	sma.addData(25.0);
	sma.addData(12.0);
	sma.addData(34.0);
	sma.addData(67.0);
	sma.addData(89.0);
	sma.addData(111.0);
	sma.addData(2.0);
	sma.setMA();
	std::cout << ",sma1," << sma.getMA() << std::endl;

	return 0;
}
