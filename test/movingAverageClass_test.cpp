#include "MovingAverage.h"

#include <iostream>
#include <unordered_map>

class Test {
private:
	double emaVal_ = 0.0;
	double span_ = 3.0;
	std::unordered_map<int, ExponentialMovingAverage> emaMap_;

public:
	Test();
	void foo(double val);
};

Test::Test() {
	emaMap_[0] = ExponentialMovingAverage(span_);
}

void Test::foo(double val) {
	emaMap_[0].addDataAndCalculateMA(val);
	emaVal_ = emaMap_[0].getMA();

	std::cout << "val," << val
		<< ",ema," << emaMap_[0].getMA()
		<< std::endl;
}

int main() {
	Test obj;

	for (double a: {10.0, 15.0, 20.0, 25.0, 12.0, 34.0, 67.0, 89.0, 111.0, 2.0}) {
		obj.foo(a);
	}

	return 0;
}

//10.0, 15.0, 20.0, 25.0, 12.0, 34.0, 67.0, 89.0, 111.0, 2.0
