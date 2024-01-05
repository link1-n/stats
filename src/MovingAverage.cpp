#include "MovingAverage.h"

MovingAverage::MovingAverage(){
}

double MovingAverage::getMA() const {
	return currentMA_;
}

/* 
 *
 *
 * SMA Start 
 *
 * */
SimpleMovingAverage::SimpleMovingAverage(int period) : PERIOD(period) {
}

SimpleMovingAverage::SimpleMovingAverage(){
}

void SimpleMovingAverage::setPeriod(int inputPeriod){
	this->PERIOD = inputPeriod;
}

void SimpleMovingAverage::addData(const double& data) {
	this->dataStore_.push_back(data);

	if (int(this->dataStore_.size()) > this->PERIOD) {
		this->dataStore_.erase(this->dataStore_.begin());
	}
}

void SimpleMovingAverage::addDataAndCalculateMA(const double& data) {
	addData(data);

	double sum = 0;
	for (const auto &i: this->dataStore_) {
		sum += i;
	}

	this->currentMA_ = (sum / static_cast<double>(this->dataStore_.size()));

#ifdef MA_DEBUG
	std::cout << "sma,data," << data
		<< ",PERIOD," << this->PERIOD
		<< ",sum," << sum
		<< ",currentMA," << this->currentMA_
		<< std::endl;
#endif
}
/* SMA End */

/* 
 *
 *
 * EMA Start 
 *
 * */
ExponentialMovingAverage::ExponentialMovingAverage(double inputSpan) :
	SPAN(inputSpan) {
		ALPHA = 2.0 / (1 + SPAN);
	}
ExponentialMovingAverage::ExponentialMovingAverage() {
}

void ExponentialMovingAverage::setSpan(double inputSpan) {
	this->SPAN = inputSpan;
	ALPHA = 2.0 / (1 + SPAN);
}

void ExponentialMovingAverage::addDataAndCalculateMA(const double& data) {

	/* 
	 * when I use getMA() without explicit class member operator(this->)
	 * the code doesn't compile because in template classes, the compiler
	 * doesn't look in the derived class when performing name look-up
	 * so you have to explicitly specify that you are using a member of the
	 * class. (ChatGPT said so) 
	 *
	 */

	double previousEma = this->getMA();

	this->count_ += 1;

	if (previousEma == 0) {
		this->currentMA_ = data;
	}

	const double alpha = this->ALPHA;
	double currentEma = (data*alpha) + ((previousEma)*(1 - alpha));

	this->currentMA_ = currentEma;

#ifdef MA_DEBUG
	std::cout << "ema,data," << data
		<< ",SPAN," << this->SPAN
		<< ",ALPHA," << this->ALPHA
		<< ",previousEma," << previousEma
		<< ",currentMA," << this->currentMA_
		<< std::endl;
#endif
}
/* EMA End */

