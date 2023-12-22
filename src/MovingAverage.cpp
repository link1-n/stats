#include "MovingAverage.h"

template <typename T>
MovingAverage<T>::MovingAverage(){
}

template <typename T>
T MovingAverage<T>::getMA() const {
	return currentMA_;
}

/* SMA Start */
template <typename T>
SimpleMovingAverage<T>::SimpleMovingAverage(int period) : PERIOD(period) {
}

template <typename T>
SimpleMovingAverage<T>::SimpleMovingAverage(){
}

template <typename T>
void SimpleMovingAverage<T>::setPeriod(int inputPeriod){
	this->PERIOD = inputPeriod;
}

template <typename T>
void SimpleMovingAverage<T>::addData(const T& data) {
	this->dataStore_.push_back(data);

	if (int(this->dataStore_.size()) > this->PERIOD) {
		this->dataStore_.erase(this->dataStore_.begin());
	}
}

template <typename T>
void SimpleMovingAverage<T>::addDataAndCalculateMA(const T& data) {
	addData(data);

	T sum = 0;
	for (const auto &i: this->dataStore_) {
		sum += i;
	}

	this->currentMA_ = (sum / static_cast<T>(this->dataStore_.size()));

#ifdef MA_DEBUG
	std::cout << "sma,data," << data
		<< ",PERIOD," << this->PERIOD
		<< ",sum," << sum
		<< ",currentMA," << this->currentMA_
		<< std::endl;
#endif
}
/* SMA End */

/* EMA Start */
template <typename T>
ExponentialMovingAverage<T>::ExponentialMovingAverage(double inputSpan) :
	SPAN(inputSpan) {
		ALPHA = 2.0 / (1 + SPAN);
	}
template <typename T>
ExponentialMovingAverage<T>::ExponentialMovingAverage() {
}

template <typename T>
void ExponentialMovingAverage<T>::setSpan(double inputSpan) {
	this->SPAN = inputSpan;
	ALPHA = 2.0 / (1 + SPAN);
}

template <typename T>
void ExponentialMovingAverage<T>::addDataAndCalculateMA(const T& data) {

	/* when I use getMA() without explicit class member operator(this->)
	 * the code doesn't compile because in template classes, the compiler
	 * doesn't look in the derived class when performing name look-up
	 * so you have to explicitly specify that you are using a member of the
	 * class. (ChatGPT said so) */

	T previousEma = this->getMA();

	this->count_ += 1;

	if (previousEma == 0) {
		this->currentMA_ = data;
//
//		return;
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

template class SimpleMovingAverage<double>;
template class ExponentialMovingAverage<double>;

