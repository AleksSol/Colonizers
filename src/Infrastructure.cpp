#include "Infrastructure.h"

Infrastructure::Infrastructure(const std::string &name, Player &player)
	: _player(player),  _name(name) 
{
}

Player &Infrastructure::player() const noexcept
{
	return _player;
}

const std::string &Infrastructure::name() const noexcept
{
	return _name;
}		
