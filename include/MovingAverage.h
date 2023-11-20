#include <iostream>
#include <vector>

template <typename T>
class MovingAverage {
	public:
		MovingAverage();
		virtual void addDataAndCalculateMA(const T& data) = 0;
		virtual T getMA() const;

	protected:
		T currentMA_;
};

template <typename T>
class SimpleMovingAverage: public MovingAverage<T> {
	protected:
		int PERIOD;
		std::vector<T> dataStore_;
	public:
		SimpleMovingAverage(int period);
		SimpleMovingAverage();
		
		void addDataAndCalculateMA(const T& data) override;
		void addData(const T& data);
		void setPeriod(int inputPeriod);
};

template <typename T>
class ExponentialMovingAverage: public MovingAverage<T> {
	protected:
		int count_ = 0;
		double SPAN = 1.0;
		double ALPHA = 1.0;
	public:
		ExponentialMovingAverage(double inputSpan);
		ExponentialMovingAverage();

		//void addData(const T& data) override;
		void addDataAndCalculateMA(const T& data) override;
		void setSpan(double inputSpan);
};
