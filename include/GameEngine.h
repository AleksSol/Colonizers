#pragma once
#include "Game.h"
#include "Engine.h"
#include "EngineStartStage.h"
#include "EngineFirstStage.h"
#include "GameStage.h"
#include "ColUtils.h"
#include <memory>
#include <stdexcept>
#include <set>
#include <map>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cstddef>
#include <algorithm>

class GameEngine
{
private:
	enum {
		START_RES_NUM = 19
	};
	std::unique_ptr<Game> _game;
	Engine *_crr_engine;
	GameStage _crr_stage;
	std::vector <std::string> _players;
	size_t _crr_player_num;
	Player *player_by_name(const std::string &player) const noexcept; 						// Проверяют, подключен ли этот игрок
	bool road_in_field(Coord place, RoadSide side) const noexcept;	
	bool loc_in_field(Coord place, CrossCorner side) const noexcept;
	bool loc_can_placed(Coord place, CrossCorner side) const noexcept;
public:
	GameEngine();
	~GameEngine();
	void join_player(const std::string &); 									// Присоединяет игрока с указанным именем.
	void start_game();														// Начинает игру.
	void register_road(const std::string &player, const std::string &name); // Регистрирует дорогу.
	void register_town(const std::string &player, const std::string &name); // Регистрирует поселение.
	void register_city(const std::string &player, const std::string &name); // Регистрирует город.
	void put_initial_infrastructure(const std::string &player,
									const std::string &town, 
									Coord town_coord, 
									CrossCorner town_corner, 
									const std::string &road, 
									Coord road_coord, 
									RoadSide road_side);
	void make_dice(const std::string &player, size_t dice);
	void drop_resource(const std::string &player, Resource);
	const Player &current_player() const;
};
