#include "catch2/catch.hpp"
#include "pch.hpp"
#include "UAV/UAV.hpp"

class RedLight : public UNL::UAV::State::State{
public:
	RedLight() : State("RedLight"){}
	void enable() {}
	void run() {}
	void handle() {}
	void disable() {}
	~RedLight(){}
};

class YellowLight : public UNL::UAV::State::State{
public:
	YellowLight() : State("YellowLight"){}
	void enable() {}
	void run() {}
	void handle() {}
	void disable() {}
	~YellowLight(){}
};

class GreenLight : public UNL::UAV::State::State{
public:
	GreenLight() : State("GreenLight"){}
	void enable() {}
	void run() {}
	void handle() {}
	void disable() {}
	~GreenLight(){}
};

template<typename Base, typename T>
inline bool instanceof(const T*) {
   return std::is_base_of<Base, T>::value;
};

TEST_CASE("Light Test", "[State][Light]"){
	UNL::UAV::State::StateHandler handler;
	RedLight red;
	YellowLight yellow;
	GreenLight green;

	REQUIRE(handler.getState() == nullptr);
	
	SECTION("SETTING TO GREEN"){
		handler.setState(&green);
		REQUIRE(dynamic_cast<GreenLight*>(handler.getState()));
		CHECK(handler.getState()->getName().compare("GreenLight") == 0);
	}

	SECTION("SETTING TO YELLOW"){
		handler.setState(&yellow);
		REQUIRE(dynamic_cast<YellowLight*>(handler.getState()));
		CHECK(handler.getState()->getName().compare("YellowLight") == 0);
	}

	SECTION("SETTING TO RED"){
		handler.setState(&red);
		REQUIRE(dynamic_cast<RedLight*>(handler.getState()));
		CHECK(handler.getState()->getName().compare("RedLight") == 0);
	}
};