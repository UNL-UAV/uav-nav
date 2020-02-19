#include "UAV/DroneBuilder.hpp"
#include "xml2json.hpp"
#include "rapidjson/document.h"
namespace UNL::UAV{
Drone* DroneBuilder::buildFromXML(const std::string& xml){
	return this->buildFromJSON(xml2json(xml.data()));
}
Drone* DroneBuilder::buildFromJSON(const std::string& json){
	rapidjson::Document jsonParser;
	jsonParser.Parse(json.data());

	rapidjson::Value& message = jsonParser["message"]["fields"];
	Drone* d = new Drone();
	for(int i=0; i < message.Size(); i++){
		rapidjson::Value& line = message[i];
		if(line["@name"] == "lat")
			d->setLaditude(line["@text"].GetInt());
		if(line["@name"] == "lon")
			d->setLongitude(line["@text"].GetInt());
		if(line["@name"] == "alt")
			d->setAltitude(line["@text"].GetInt());
		if(line["@name"] == "vel")
			d->setVelocity(line["@text"].GetInt());
	}

	return d;
}
};