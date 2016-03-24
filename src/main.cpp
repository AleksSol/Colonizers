#include "Coord.h"
#include "RoadSide.h"
#include "Resource.h"
#include "ResourcesHolder.h"
#include "Hex.h"
#include "Infrastructure.h"
#include "Locality.h"
#include "Road.h"
#include "Town.h"
#include "City.h"
#include "Player.h"
#include "Field.h"
#include "Game.h"
#include <iostream>
using namespace std;

void assert(bool t)
{
	if(!t) throw std::logic_error("assertion violation");
}
void assert_game(Game &g, size_t n)
{
	assert(g.num_players() == n);
	try {
		g.player(n);
		throw std::logic_error("!");
	}
	catch (std::out_of_range out){}
}
void assert_roads(Player &p, size_t n)
{
	assert(p.num_roads() == n);
	for(size_t  i =0; i< p.num_roads(); i++) {
		p.road(i);
	}
	try {
		p.road(n);
		throw std::logic_error("!");
	}
	catch (std::out_of_range out){}
}
void assert_cities(Player &p, size_t n)
{
	assert(p.num_cities() == n);
	for(size_t  i =0; i< p.num_cities(); i++) {
		p.city(i);
	}
	try {
		p.city(n);
		throw std::logic_error("!");
	}
	catch (std::out_of_range out){}
}
void assert_towns(Player &p, size_t n)
{
	assert(p.num_towns() == n);
	for(size_t i =0; i< p.num_towns(); i++) {
		p.town(i);
	}
	try {
		p.town(n);
		throw std::logic_error("!");
	}
	catch (std::out_of_range out){}
}
void assert_infr(Player &p, size_t n)
{
	assert(p.num_infrastructures() == n);
	for(size_t  i =0; i< p.num_infrastructures(); i++) {
		p.infrastructure(i);
	}
	try {
		p.infrastructure(n);
		throw std::logic_error("!");
	}
	catch (std::out_of_range out){}
}

void assert_pl(Player &p, size_t n, size_t t, size_t c, size_t r)
{
	assert_infr(p, n);
	assert_roads(p, r);
	assert_cities(p, c);
	assert_towns(p,t);
} 

int main() {
	Game my_game;
	assert_game(my_game, 0);	
	my_game.add_player("Pl0");
	assert_game(my_game, 1);
	my_game.add_player("Pl1");
	assert_game(my_game, 2);
	my_game.add_player("Pl3");
	assert_game(my_game, 3);
	
	
	Player &my_player = my_game.player(1);
	//+1 -1
	assert_pl(my_player, 0,0,0,0);
	Road &my_road = my_player.add_road("R1");
	assert_pl(my_player, 1,0,0,1);
	my_player.remove_road(my_road);
	assert_pl(my_player, 0,0,0,0);
	
	// +2 -2
	Road &my_second_road = my_player.add_road("R1");
	my_player.add_road("R1");
	assert_pl(my_player, 2,0,0,2);
	my_player.remove_road(my_second_road);
	assert_pl(my_player, 1,0,0,1);
	my_player.remove_road(my_player.road(0));
	assert_pl(my_player, 0,0,0,0);
	
	//+3
	my_player.add_road("R1");
	my_player.add_road("R1");
	my_player.add_road("R1");
	assert_pl(my_player, 3,0,0,3);
	
	City &my_city = my_player.add_city("C");
	assert_pl(my_player, 4,0,1,3);
	my_player.remove_city(my_city);
	assert_pl(my_player, 3,0,0,3);
	my_player.add_city("C");
	my_player.add_city("C");
	assert_pl(my_player, 5,0,2,3);
	my_player.remove_road(my_player.road(2));
	assert_pl(my_player, 4,0,2,2);
	my_player.remove_road(my_player.road(1));
	assert_pl(my_player, 3,0,2,1);
	my_player.remove_road(my_player.road(0));
	assert_pl(my_player, 2,0,2,0);
	
    return 0;
}
