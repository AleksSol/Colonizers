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

	M.join_player("player_1");
	M.join_player("player_2");
	M.join_player("player_3");
	M.start_game();	
	
	/*for(size_t it = 0; it < crr_field.num_hexes(); it++) {
		std::cout << crr_field.coord(crr_field.hex(it)).x() << " " << crr_field.coord(crr_field.hex(it)).y() << " "; 
		if(crr_field.hex(it).has_resource()) {
			std::cout << (int)crr_field.hex(it).resource() << " ";
		}
		if(crr_field.hex(it).has_number()) {
			std::cout << (int)crr_field.hex(it).number();
		}
		std::cout << std::endl;
	}*/
	string A = "a";
	for(int i =0; i < 15; i++) {
		M.register_road("player_1", A);
		M.register_road("player_2", A);
		M.register_road("player_3", A);
		A = A + "a";
	}
	A = "a";
	for(int i =0; i < 5; i++) {
		M.register_town("player_1", A);
		M.register_town("player_2", A);
		M.register_town("player_3", A);
		A = A + "a";
	}
	A = "a";
	for(int i =0; i < 4; i++) {
		M.register_city("player_1", A);
		M.register_city("player_2", A);
		M.register_city("player_3", A);
		A = A + "a";
	}
	M.put_initial_infrastructure("player_1", "a", Coord(-1,1), CrossCorner::BOTTOM, "a", Coord(-1,1), RoadSide::DOWN);

	M.put_initial_infrastructure("player_2", "a", Coord(1,1), CrossCorner::BOTTOM, "a", Coord(1,1), RoadSide::DOWN);

	M.put_initial_infrastructure("player_3", "a", Coord(1,0), CrossCorner::BOTTOM, "a", Coord(1,0), RoadSide::DOWN);

	M.put_initial_infrastructure("player_3", "aa", Coord(-1,1), CrossCorner::TOP, "aa", Coord(-1,1), RoadSide::UP);

	M.put_initial_infrastructure("player_2", "aa", Coord(-1,3), CrossCorner::BOTTOM, "aa", Coord(-1,2), RoadSide::RIGHT);

	M.put_initial_infrastructure("player_1", "aa", Coord(0,-1), CrossCorner::BOTTOM, "aa", Coord(0,-2), RoadSide::UP);

	M.make_dice("player_1", 2);
		
		
		
	/*for(size_t it = 0; it < crr_field.num_hexes(); it++) {
		std::cout << crr_field.coord(crr_field.hex(it)).x() << " " << crr_field.coord(crr_field.hex(it)).y() << " "; 
		if(crr_field.hex(it).has_resource()) {
			if(crr_field.hex(it).resource() == Resource::GRAIN) { 
				std::cout << "GRAIN ";
			} else if(crr_field.hex(it).resource() == Resource::CLAY) { 
				std::cout << "CLAY ";
			} else if(crr_field.hex(it).resource() == Resource::ORE) { 
				std::cout << "ORE ";
			} else if(crr_field.hex(it).resource() == Resource::WOOD) { 
				std::cout << "WOOD ";
			} else if(crr_field.hex(it).resource() == Resource::WOOL) { 
				std::cout << "WOOL ";
			}
			
		}
		if(crr_field.hex(it).has_number()) {
			std::cout << (int)crr_field.hex(it).number();
		}
		std::cout << std::endl;
	}
		
		
		ResourcesHolder * h;
		for(size_t i = 0; i < _players.size(); i++) {
			h = & player_by_name(_players[i])->bank();
			std::cout <<_players[i] << " ";
			std::cout << "GRAIN - " << h->resources(Resource::GRAIN) << " ";
			std::cout << "CLAY - " <<h->resources(Resource::CLAY) << " ";
			std::cout << "ORE - " << h->resources(Resource::ORE) << " ";
			std::cout << "WOOD - " << h->resources(Resource::WOOD) << " ";
			std::cout << "WOOL - " << h->resources(Resource::WOOL) << " ";
			std::cout << std:: endl;
		}*/
//Check field
	//int t[10];
	
	//for(int i =0; i<6; i++) std::cout << t[i] <<  std::endl;
	
    return 0;
}
