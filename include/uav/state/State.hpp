#pragma once
#include "pch.hpp"
namespace UNL::UAV{
class State{
public:
	State(const std::string& name="base");
	virtual ~State();
	
	virtual void enable() = 0;
	virtual void run() = 0;
	virtual void disable() = 0;
}
};