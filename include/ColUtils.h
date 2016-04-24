#include "Player.h"
#include "Road.h"
#include "City.h"
#include "Town.h"

namespace ColUtils{
Road *road_by_name(const Player & player, const std::string &name); 	//Возвращает дорогу или nullptr
Town *town_by_name(const Player & player, const std::string &name);		//Возвращает поселение или nullptr
City *city_by_name(const Player & player, const std::string &name);		//Возвращает город или nullptr
}
