#include "catch2/catch.hpp"
#include "pch.hpp"
#include "UAV/UAV.hpp"

TEST_CASE("PID"){
	UNL::UAV::PID::PID pid;
	pid.setError(50);

	REQUIRE(pid.output() == 0);

	SECTION("Testing only Bias"){
		UNL::UAV::PID::Bias bias;
		bias.setK(1);

		pid.addController(&bias);

		CHECK(pid.getControllers().size() == 1);
		REQUIRE(pid.output() == 1);
	}

	SECTION("Testing Proportional"){
		UNL::UAV::PID::Proportional prop;
		prop.setK(0.5f);

		pid.addController(&prop);

		pid.update(1);

		CHECK(pid.getControllers().size() == 1);
		REQUIRE(pid.output() == 25);
	}

	SECTION("TEST INTEGRATION"){
		UNL::UAV::PID::Integral integ;
		integ.setK(0.5f);

		pid.addController(&integ);

		pid.update(1);

		CHECK(pid.getControllers().size() == 1);
		REQUIRE(pid.output() == 25);
	}

	SECTION("Testing Second Integration"){
		UNL::UAV::PID::Proportional prop;
		prop.setK(0.5f);

		pid.addController(&prop);

		pid.update(1);

		CHECK(pid.getControllers().size() == 1);
		REQUIRE(pid.output() == 25);

		pid.setError(25);
		prop.setK(0.75f);
		pid.update(0.25f);

		REQUIRE(pid.getControllers()[0]->getK() == 0.75f);
		REQUIRE(pid.getControllers()[0]->getLastK() == 0.50f);
		REQUIRE(pid.getControllers()[0]->getError()->getError() == 25);
		REQUIRE(pid.getControllers()[0]->getTimeElapsed() == 0.25);
		CHECK(pid.getControllers().size() == 1);
		REQUIRE(pid.output() == 5.0625);
	}
}