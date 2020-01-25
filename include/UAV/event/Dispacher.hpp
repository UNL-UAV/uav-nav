#pragma once
#include "pch.hpp"

namespace UNL::UAV{
class StateHandler{
private:
	State* _state;
public:
	StateHandler() : _state(nullptr){}
	inline void setState(State* state){ 
		if(this->_state != nullptr)
			this->_state->disable();
		this->_state = state;
		this->_state->enable();
	}
	inline State* getState() const { return this->_state;};
};
};