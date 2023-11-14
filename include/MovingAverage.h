#include <vector>

template <typename T>
class MovingAverage {
	public:
		MovingAverage(int period);
		virtual void addData(const T& data) = 0;
		virtual T calculate() const = 0;
		virtual void setMA();
		virtual T getMA();

	protected:
		int period_;
		std::vector<T> dataStore_;
		T currentMA_;
};

template <typename T>
class SimpleMovingAverage: public MovingAverage<T> {
	public:
		/* To bring construtor of base class into scope? */
		SimpleMovingAverage(int period) : MovingAverage<T>(period) {}
		void addData(const T& data) override;
		T calculate() const override;
};

template <typename T>
class ExponentialMovingAverage: public MovingAverage<T> {
	public:
		/* To bring construtor of base class into scope? */
		ExponentialMovingAverage(int period) : MovingAverage<T>(period) {}
		void addData(const T& data) override;
		T calculate() const override;
};
