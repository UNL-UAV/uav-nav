#include "UAV/PID/Controller.hpp"

namespace UNL::UAV::PID{
void Controller::setK(float K){
	this->_lastK = this->_K;
	this->_K = K;
};
void Controller::setError(const Error* e){
	if(this->_error != nullptr){
		this->_lastError = this->_error;
	}
	this->_error = e;
};
void Proportional::calculate(){
	this->_calculated = this->_error->getError() * this->_K;
};
void Integral::calculate(){
	this->_calculated = this->_K * (this->_lastK + (this->_error->getError() * this->_timeElapsed));
};
void Derivative::calculate(){
	this->_calculated = this->_K * ((this->_error->getError() - this->_lastError->getError())/this->_timeElapsed);
};
void Bias::calculate(){
	this->_calculated = this->_K;
};
};