#pragma once
#include "pch.hpp"

namespace UNL::UAV::PID{
class Error{
	protected:
		float _error;
	public:
		Error(float error) : _error(error){};
		inline Error(){};
		inline float getError() const { return this->_error;};
		inline void setError(const float error) { this->_error = error; };
		~Error() = default;
};
}