#pragma once
#include "pch.hpp"
#include "Error.hpp"

namespace UNL::UAV::PID{
class Controller{
protected:
	float _K;
	const Error* _error;
	float _calculated;
	float _timeElapsed;
	float _lastK;
	const Error* _lastError;
public:
	inline float getK() const {return this->_K;}; 
	void setKp(float K);
	void setError(const Error* e);
	inline void setTimeElapsed(float time) {this->_timeElapsed = time;};
	inline float getTimeElapsed(float time) const {return this->_timeElapsed;};
	virtual void calculate() = 0;
	inline float getCalculated(){return this->_calculated;};
};
class Proportional : public Controller {
	virtual void calculate();
};
class Integral : public Controller {
	virtual void calculate();
};
class Derivative : public Controller {
	virtual void calculate();
};
class Bias : public Controller {
	virtual void calculate();
};
}