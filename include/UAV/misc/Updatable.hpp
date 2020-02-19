#pragma once

namespace UNL::UAV::MISC{
class Updatable {
public:
	virtual void update(float delta) = 0;
};
};