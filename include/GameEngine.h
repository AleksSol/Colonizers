#pragma once
#include "Game.h"
#include "Engine.h"
#include "EngineStartStage.h"
#include "GameStage.h"
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
	Player *player_by_name(const std::string &player); 						// Проверяют, подключен ли этот игрок
public:
	GameEngine();
	~GameEngine();
	void join_player(const std::string &); 									// Присоединяет игрока с указанным именем.
	void start_game();														// Начинает игру.
	void register_road(const std::string &player, const std::string &name); // Регистрирует дорогу.
	void register_town(const std::string &player, const std::string &name); // Регистрирует поселение.
	void register_city(const std::string &player, const std::string &name); // Регистрирует город.
};
