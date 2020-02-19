#pragma once
#include "pch.hpp"
#include "Error.hpp"

namespace UNL::UAV::PID{
class Controller{
protected:
	float _K = 0;
	const Error* _error;
	float _calculated = 0;
	float _timeElapsed = 0;
	float _lastK = 0;
	const Error* _lastError;
public:
	inline float getK() const {return this->_K;}; 
	void setK(float K);
	void setError(const Error* e);
	inline const Error* getError() const {return this->_error;}
	inline float getLastK() const {return this->_lastK;};
	inline void setTimeElapsed(float time) {this->_timeElapsed = time;};
	inline float getTimeElapsed() const {return this->_timeElapsed;};
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