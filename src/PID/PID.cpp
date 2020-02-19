#include "UAV/PID/PID.hpp"

namespace UNL::UAV::PID{
void PID::update(float delta){
	for(auto& controller : this->_controllers){
		controller.setError(&(this->_error));
	}

	for(auto& controller : this->_controllers){
		controller.setTimeElapsed(delta);
	}
};
float PID::output(){
	float final = 0;
	for(auto& controller : this->_controllers){
		controller.calculate();
		final += controller.getCalculated();
	}
	return final;
};
};