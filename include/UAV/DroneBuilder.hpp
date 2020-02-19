#pragma once
#include "pch.hpp"
#include "Drone.hpp"

namespace UNL::UAV{
class DroneBuilder{
private:
public:
	Drone* buildFromXML(const std::string& xml);
	Drone* buildFromJSON(const std::string& json);
};
};