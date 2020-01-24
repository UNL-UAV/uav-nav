#pragma once
#include "pch.hpp"
#include "State.hpp"

namespace UNL::UAV{
class StateSystem{
private:
	std::map<std::string, State*> m_States;
	std::string m_currentState;
public:
	StateSystem();
	~State();

	void addState(State* state);
	void setState(std::string& state);
	const State* getCurrentState() const;
}
};