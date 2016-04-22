#include "GameEngine.h"
#include <iostream>


GameEngine::GameEngine() 
	: _game(std::unique_ptr<Game>(new Game)),
	_crr_engine(new EngineStartStage),
	_crr_stage(GameStage::PLAYERS_REGISTRATION)
{
}

GameEngine::~GameEngine()
{
}

void GameEngine::join_player(const std::string &name)
{
	if(_crr_stage != GameStage::PLAYERS_REGISTRATION) {
		throw std::invalid_argument("Registration is over!");
	}
	size_t size = _game->num_players();
	for(size_t i = 0; i< size; i++) {
		if (_game->player(i).name() == name) {
			throw std::invalid_argument("This name already used.");
		}
	}
	_game->add_player(name);
}

void GameEngine::start_game()
{
	if(_crr_stage != GameStage::PLAYERS_REGISTRATION) {
		throw std::invalid_argument("Game already started!");
	}
	if(!(_game->num_players() == 4 || _game->num_players() == 3)) {
		throw std::invalid_argument("Incorrect players number.");
	}
	Field & crr_field = _game->field();
	
// Add resources
	crr_field.bank().add(Resource::GRAIN, START_RES_NUM);
	crr_field.bank().add(Resource::CLAY, START_RES_NUM);
	crr_field.bank().add(Resource::ORE, START_RES_NUM);
	crr_field.bank().add(Resource::WOOL, START_RES_NUM);
	crr_field.bank().add(Resource::WOOD, START_RES_NUM);
	
// Create 3 circles of Hexes
	for (int i = -2; i <= 2; i++) {
		for (int j = -2; j <= 2; j++) {
			if ((i + j) <= 2 && (i + j) >= -2) {
				crr_field.put_hex(Coord(i,j));
			}
		} 
	}
	
// Put random resources by commercial banner agorithm
	std::map<size_t, Resource> int_to_res= {
		{0, Resource::GRAIN},
		{1, Resource::CLAY},
		{2, Resource::ORE},
		{3, Resource::WOOD},
		{4, Resource::WOOL}
	};
	size_t crr_it;
	size_t crr_res = 0;
	std::vector <size_t> num;
	/* preprocessing */
	std::srand (std::time(0));
	for (size_t i = 0; i <= (crr_field.num_hexes() - 1); i++) {
		num.push_back(i);
	}
	/* processing */
	for(size_t i = num.size() - 1; i >= 1; i--){
		crr_it = std::rand() % (i + 1);
		crr_field.hex(num[crr_it]).set_resource(int_to_res[crr_res]);
		std::swap(num[crr_it], num[i]);
		crr_res = (crr_res + 1) % 5;
	}
	crr_field.set_robber(crr_field.coord(crr_field.hex(num[0])));
	std::swap(num[0], num[num.size() - 1]);
	
//Put random numbers by commercial banner agorithm
	size_t crr_num = 0;
	for(size_t i = num.size() - 2; i > 1; i--){
		crr_it = std::rand() % (i + 1);
		crr_field.hex(num[crr_it]).set_number(crr_num + 3);
		std::swap(num[crr_it], num[i]);
		crr_num = (crr_num + 1) % 9;
		if (crr_num == 4) {
			crr_num++;
		}
	}
	crr_field.hex(num[0]).set_number(2);
	crr_field.hex(num[1]).set_number(12);
// End
	_crr_stage = GameStage::INFRASTRUCTURES_REGISTRATION;
}

Player * GameEngine::player_by_name(const std::string &player)
{
	for (size_t i = 0; i < _game->num_players(); i++)
	{
		if (_game->player(i).name() == player) {
			return &_game->player(i);
		}
	}
	return nullptr;
}

void GameEngine::register_road(const std::string &player, const std::string &name) 
{
	Player *crr_pl;
	EngineStartStage *crr_engine;
	if(_crr_stage != GameStage::INFRASTRUCTURES_REGISTRATION) {
		throw std::invalid_argument("Infrastructures registrations isn't available!");
	}

	crr_pl = player_by_name(player);
	if (crr_pl == nullptr) {
		throw std::invalid_argument("Player isn't registered");
	}
	if (crr_pl->num_roads() >= 15) {
		throw std::invalid_argument("Player already have enought roads");
	}
	for (size_t i = 0; i < crr_pl->num_roads(); i++) {
		if(crr_pl->road(i).name() == name) {
			throw std::invalid_argument("Player have this road");
		}
	}
	crr_pl->add_road(name);
	
	crr_engine = (EngineStartStage *)_crr_engine;
	if (crr_engine->check_all_infr(*_game)) {
		_crr_stage = GameStage::PUT_INITIAL_INFRASTRUCTURES;
	}
}

void GameEngine::register_town(const std::string &player, const std::string &name) 
{
	Player *crr_pl;
	EngineStartStage *crr_engine;
	if(_crr_stage != GameStage::INFRASTRUCTURES_REGISTRATION) {
		throw std::invalid_argument("Infrastructures registrations isn't available!");
	}

	crr_pl = player_by_name(player);
	if (crr_pl == nullptr) {
		throw std::invalid_argument("Player isn't registered");
	}
	if (crr_pl->num_towns() >= 5) {
		throw std::invalid_argument("Player already have enought towns");
	}
	for (size_t i = 0; i < crr_pl->num_towns(); i++) {
		if(crr_pl->town(i).name() == name) {
			throw std::invalid_argument("Player have this town");
		}
	}
	crr_pl->add_town(name);
	
	crr_engine = (EngineStartStage *)_crr_engine;
	if (crr_engine->check_all_infr(*_game)) {
		_crr_stage = GameStage::PUT_INITIAL_INFRASTRUCTURES;
	}
}

void GameEngine::register_city(const std::string &player, const std::string &name) 
{
	Player *crr_pl;
	EngineStartStage *crr_engine;
	if(_crr_stage != GameStage::INFRASTRUCTURES_REGISTRATION) {
		throw std::invalid_argument("Infrastructures registrations isn't available!");
	}

	crr_pl = player_by_name(player);
	if (crr_pl == nullptr) {
		throw std::invalid_argument("Player isn't registered");
	}
	if (crr_pl->num_cities() >= 4) {
		throw std::invalid_argument("Player already have enought cities");
	}
	for (size_t i = 0; i < crr_pl->num_cities(); i++) {
		if(crr_pl->city(i).name() == name) {
			throw std::invalid_argument("Player have this city");
		}
	}
	crr_pl->add_city(name);
	
	crr_engine = (EngineStartStage *)_crr_engine;
	if (crr_engine->check_all_infr(*_game)) {
		_crr_stage = GameStage::PUT_INITIAL_INFRASTRUCTURES;
	}
}

