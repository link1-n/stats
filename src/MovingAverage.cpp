#include "MovingAverage.h"

template <typename T>
MovingAverage<T>::MovingAverage(int period) : period_(period) {
}

template <typename T>
T MovingAverage<T>::getMA() {
	return currentMA_;
}

template <typename T>
void MovingAverage<T>::setMA() {
	this->currentMA_ = calculate();
}

template <typename T>
void SimpleMovingAverage<T>::addData(const T& data) {
	this->dataStore_.push_back(data);

	if (this->dataStore_.size() > this->period_) {
		this->dataStore_.erase(this->dataStore_.begin());
	}
}

template <typename T>
T SimpleMovingAverage<T>::calculate() const {
	T sum = 0;
	for (const auto &i: this->dataStore_) {
		sum += i;
	}

	return (sum / static_cast<T>(this->dataStore_.size()));
}

template class SimpleMovingAverage<double>;
