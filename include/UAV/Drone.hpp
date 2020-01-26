#pragma once
namespace UNL::UAV{
class Drone{
private:
	float _longitude;
	float _laditude;
	float _altitude;
	float _velocity;
	float _direction;
public:
	friend class DroneBuilder;
	inline float getLongitude() const { return this->_longitude; }
	inline float getLaditude() const { return this->_laditude; }
	inline float getAltitude() const { return this->_altitude; }
	inline float getVelocity() const { return this->_velocity; }
	inline float getDirection() const { return this->_direction; }
protected:
	inline void setLaditude(float laditude) { this->_laditude;}
	inline void setLongitude(float laditude) { this->_longitude;}
	inline void setAltitude(float laditude) { this->_altitude;}
	inline void setVelocity(float laditude) { this->_velocity;}
	inline void setDirection(float laditude) { this->_direction;}
};
};