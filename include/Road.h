#pragma once
#include "Infrastructure.h"

class Road : public Infrastructure 
{
public:
	Road(const std::string &name, Player &player) : Infrastructure(name, player) {}
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
		return true;
	}
};


