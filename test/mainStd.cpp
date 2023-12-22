#include "MeanDev.h"

#include <iostream>

int main() {
	int per = 1000000000;

	MeanDev* md = new MeanDev(per);

	for (auto &i: {10.0, 15.0, 20.0, 25.0, 12.0, 34.0, 67.0, 89.0, 111.0, 2.0}) {
		md->addDataAndPerformCalculations(i);
	}

	std::cout << "mean," << md->getRollingMean() << ",std," << md->getRollingStd() << std::endl;

	return 0;
}

//10.0, 15.0, 20.0, 25.0, 12.0, 34.0, 67.0, 89.0, 111.0, 2.0
