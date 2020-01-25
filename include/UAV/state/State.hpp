#pragma once
#include "pch.hpp"
namespace UNL::UAV::State{
class State{
private:
	const std::string _name;
public:
	State(const std::string& name="base") : _name(name){}
	inline const std::string getName() const {return this->_name;}
	virtual ~State() {};
	
	/**
	 * Enabled callback
	 * Used when state has been set to the current object
	 */
	virtual void enable() = 0;

	/**
	 * Running Callback
	 * Used for when in a while(true) loop
	 */
	virtual void run() = 0;

	/**
	 * Handle Callback
	 * Used for when a single call situation
	 */
	virtual void handle()=0;

	/**
	 * Disable Callback
	 * Used when state has been switched off of this object
	 */
	virtual void disable() = 0;
};
};