#include "ColUtils.h"

namespace ColUtils{

Road *road_by_name(const Player & player, const std::string &name) {
	for (size_t i = 0; i < player.num_roads(); i++) {
		if(player.road(i).name() == name) {
			return &player.road(i);
		}
	}
	return nullptr;
}

Town *town_by_name(const Player & player, const std::string &name) {
	for (size_t i = 0; i < player.num_towns(); i++) {
		if(player.town(i).name() == name) {
			return &player.town(i);
		}
	}
	return nullptr;
}

City *city_by_name(const Player & player, const std::string &name) {
	for (size_t i = 0; i < player.num_cities(); i++) {
		if(player.city(i).name() == name) {
			return &player.city(i);
		}
	}
	return nullptr;
}
}

