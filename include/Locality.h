#pragma once
#include "Infrastructure.h"

class Locality : public Infrastructure 
{
public:
	Locality(const std::string &name, Player &player) : Infrastructure(name, player) {}
	virtual bool is_town() const noexcept override
	{
		return false;
	}			
	virtual bool is_city() const noexcept override 
	{
		return false;
	}		
	virtual bool is_road() const noexcept override 
	{
		return false;
	}
};


