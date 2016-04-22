#include <iostream>

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
#include "GameStage.h"
#include "Engine.h"
#include "GameEngine.h"

using namespace std;

void assert(bool t)
{
	if(!t) throw std::logic_error("assertion violation");
}

void assert_no (bool t)
{
	if(t) throw std::logic_error("assertion violation");
}

/*
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

void assert_pl(Player &p, size_t t, size_t c, size_t r)
{
	assert_infr(p, t+r+c);
	assert_roads(p, r);
	assert_cities(p, c);
	assert_towns(p,t);
} 
*/
int main() {
	
	GameEngine M;
	M.join_player("1");
	M.join_player("2");
	M.join_player("3");
	M.start_game();
	
	string A = "a";
	for(int i =0; i < 15; i++) {
		M.register_road("1", A);
		M.register_road("2", A);
		M.register_road("3", A);
		A = A + "a";
	}
	A = "a";
	for(int i =0; i < 5; i++) {
		M.register_town("1", A);
		M.register_town("2", A);
		M.register_town("3", A);
		A = A + "a";
	}
	A = "a";
	for(int i =0; i < 4; i++) {
		M.register_city("1", A);
		M.register_city("2", A);
		M.register_city("3", A);
		A = A + "a";
	}
	M.register_city("1", A);
//Check field
	/*int t[10];
	for(int i =0; i<10; i++) t[i] =0;
	for(size_t it = 0; it < crr_field.num_hexes(); it++) {
		std::cout << crr_field.coord(crr_field.hex(it)).x() << " " << crr_field.coord(crr_field.hex(it)).y() << " "; 
		if(crr_field.hex(it).has_resource()) {
			std::cout << (int)crr_field.hex(it).resource() << " ";
			t[(int)crr_field.hex(it).resource()]++;
		}
		if(crr_field.hex(it).has_number()) {
			std::cout << (int)crr_field.hex(it).number();
		}
		std::cout << std::endl;
	}
	for(int i =0; i<6; i++) std::cout << t[i] <<  std::endl;
	*/
    return 0;
}
