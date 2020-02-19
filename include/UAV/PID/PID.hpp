#pragma once
#include "Error.hpp"
#include "Controller.hpp"
#include "../misc/Updatable.hpp"
namespace UNL::UAV::PID{
class PID : public UNL::UAV::MISC::Updatable {
protected:
	std::vector<Controller*> _controllers;
	Error _error;
public:
	PID();
	inline void setError(float error){this->_error = Error(error);};
	void update(float delta);
	float output();
	void addController(Controller* controller);
	inline std::vector<Controller*> getControllers() const {return this->_controllers;};
};
};