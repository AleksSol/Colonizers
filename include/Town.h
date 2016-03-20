#pragma once
#include "Locality.h"

class Town : public Locality
{
public:
	Town(const std::string &name, Player &player) : Locality(name, player) {}
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


