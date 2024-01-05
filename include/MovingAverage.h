#include <iostream>
#include <vector>

class MovingAverage {
	public:
		MovingAverage();
		virtual void addDataAndCalculateMA(const double& data) = 0;
		virtual double getMA() const;

	protected:
		double currentMA_;
};

class SimpleMovingAverage: public MovingAverage {
	protected:
		int PERIOD;
		std::vector<double> dataStore_;
	public:
		SimpleMovingAverage(int period);
		SimpleMovingAverage();
		
		void addDataAndCalculateMA(const double& data) override;
		void addData(const double& data);
		void setPeriod(int inputPeriod);
};

class ExponentialMovingAverage: public MovingAverage {
	protected:
		int count_ = 0;
		double SPAN = 1.0;
		double ALPHA = 1.0;
	public:
		ExponentialMovingAverage(double inputSpan);
		ExponentialMovingAverage();

		//void addData(const T& data) override;
		void addDataAndCalculateMA(const double& data) override;
		void setSpan(double inputSpan);
};
