#include "UAV/PID/PID.hpp"

namespace UNL::UAV::PID{
PID::PID(){}
void PID::update(float delta){
	for(auto& controller : this->_controllers){
		controller->setError(&(this->_error));
	}

	for(auto& controller : this->_controllers){
		controller->setTimeElapsed(delta);
	}
};
float PID::output(){
	float final = 0;
	for(auto& controller : this->_controllers){
		controller->calculate();
		final += controller->getCalculated();
	}
	return final;
};

void PID::addController(Controller* controller){
	this->_controllers.push_back(controller);
}
};