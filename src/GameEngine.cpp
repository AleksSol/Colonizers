#include "GameEngine.h"
#include <iostream>


GameEngine::GameEngine() 
	: _game(std::unique_ptr<Game>(new Game)),
	_crr_engine(new EngineStartStage),
	_crr_stage(GameStage::PLAYERS_REGISTRATION),
	_crr_player_num(0)
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
	_players.push_back(name);
}

void GameEngine::start_game()
{
	if(_crr_stage != GameStage::PLAYERS_REGISTRATION) {
		throw std::invalid_argument("Game already started!");
	}
	if(!(_game->num_players() == 4 || _game->num_players() == 3)) {
		throw std::invalid_argument("Incorrect _players number.");
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

Player * GameEngine::player_by_name(const std::string &player) const noexcept
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
	if(ColUtils::road_by_name(*crr_pl, name) != nullptr) {
		throw std::invalid_argument("Player have this road");
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
	if(ColUtils::town_by_name(*crr_pl, name) != nullptr) {
		throw std::invalid_argument("Player have this town");
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
	if(ColUtils::city_by_name(*crr_pl, name) != nullptr) {
		throw std::invalid_argument("Player have this city");
	}
	crr_pl->add_city(name);
	
	crr_engine = (EngineStartStage *)_crr_engine;
	if (crr_engine->check_all_infr(*_game)) {
		_crr_stage = GameStage::PUT_INITIAL_INFRASTRUCTURES;
	}
}

bool GameEngine::road_in_field(Coord place, RoadSide side) const noexcept
{
	Field &crr_f = _game->field();
	if (crr_f.has_hex(place)) {
		return true;
	}
	if (side == RoadSide::UP) {
		if(crr_f.has_hex(Coord(place.x(),place.y() + 1))) {
			return true;
		}
	}else if (side == RoadSide::RIGHT) {
		if(crr_f.has_hex(Coord(place.x() + 1,place.y()))) {
			return true;
		}
	} else if (side == RoadSide::DOWN) {
		if(crr_f.has_hex(Coord(place.x() + 1,place.y() - 1))) {
			return true;
		}
	}
	return false;
}

bool GameEngine::loc_in_field(Coord place, CrossCorner side) const noexcept
{
	Field &crr_f = _game->field();
	if (crr_f.has_hex(place)) {
		return true;
	}
	if (side == CrossCorner::TOP) {
		if(crr_f.has_hex(Coord(place.x(),place.y() + 1))) {
			return true;
		}
		if(crr_f.has_hex(Coord(place.x() - 1,place.y() + 1))) {
			return true;
		}
	}else if (side ==CrossCorner::BOTTOM) {
		if(crr_f.has_hex(Coord(place.x(), place.y() - 1))) {
			return true;
		}
		if(crr_f.has_hex(Coord(place.x() + 1,place.y() - 1))) {
			return true;
		}
	} 
	return false;
}

bool GameEngine::loc_can_placed(Coord place, CrossCorner side) const noexcept 
{
	if(_game->field().has_locality(place, side)) {
		return false;
	}
	if(side == CrossCorner::TOP) {
		if(_game->field().has_locality(Coord(place.x(), place.y() + 1), CrossCorner::BOTTOM) ||
		   _game->field().has_locality(Coord(place.x() - 1, place.y() + 1), CrossCorner::BOTTOM) ||
		   _game->field().has_locality(Coord(place.x() - 1, place.y() + 2), CrossCorner::TOP)) {
			   return false;
		 }
	} else if(side == CrossCorner::BOTTOM) {
		if(_game->field().has_locality(Coord(place.x(), place.y() - 1), CrossCorner::TOP) ||
		   _game->field().has_locality(Coord(place.x() + 1, place.y() - 1), CrossCorner::TOP) ||
		   _game->field().has_locality(Coord(place.x() + 1, place.y() - 2), CrossCorner::BOTTOM)) {
			   return false;
		   }
	}
	return true;
}

void GameEngine::put_initial_infrastructure(const std::string &player,
									const std::string &town, 
									Coord town_coord, 
									CrossCorner town_corner, 
									const std::string &road, 
									Coord road_coord, 
									RoadSide road_side)
{
	Player *crr_pl;
	EngineStartStage *crr_engine;
	Road *crr_road;
	Town *crr_town;
	Field &crr_field = _game->field();
	Coord crr_coord;
// CHECK
	if(_crr_stage != GameStage::PUT_INITIAL_INFRASTRUCTURES) {
		throw std::invalid_argument("Incorrect stage!");
	}
	crr_pl = player_by_name(player);
	if (crr_pl == nullptr) {
		throw std::invalid_argument("Player isn't registered");
	}
	crr_road = ColUtils::road_by_name(*crr_pl, road);
	if (crr_road == nullptr) {
		throw std::invalid_argument("Player haven't this road");
	}
	crr_town = ColUtils::town_by_name(*crr_pl, town);
	if (crr_town == nullptr) {
		throw std::invalid_argument("Player haven't this town");
	}
	if (!road_in_field(road_coord, road_side)) {
		throw std::invalid_argument("Road isn't in field");
	}
	if (!loc_in_field(town_coord, town_corner)) {
		throw std::invalid_argument("Town isn't in field");
	}
	if (!loc_can_placed(town_coord, town_corner)) {
		throw std::invalid_argument("Town can't be placed heare");
	}
	if(crr_field.has_road(road_coord, road_side)) {
		throw std::invalid_argument("Road at this place already exist");
	}
	if(crr_field.linked(*crr_road)) {
		throw std::invalid_argument("Road already linked");
	}
	if(crr_field.linked(*crr_town)) {
		throw std::invalid_argument("Town already linked");
	}
	if (town_corner == CrossCorner::TOP) {
		if ((road_coord != Coord(town_coord.x() - 1, town_coord.y() + 1) || road_side != RoadSide::DOWN) &&
		    (road_coord != Coord(town_coord.x() - 1, town_coord.y() + 1) || road_side != RoadSide::RIGHT) &&
		    (road_coord != Coord(town_coord.x(), town_coord.y()) || road_side != RoadSide::UP)) {
			throw std::invalid_argument("Town and road aren't touch");
		}
	} else if (town_corner == CrossCorner::BOTTOM) {
		if ((road_coord != Coord(town_coord.x(), town_coord.y() - 1) || road_side != RoadSide::UP) &&
		    (road_coord != Coord(town_coord.x(), town_coord.y() - 1) || road_side != RoadSide::RIGHT) &&
		    (road_coord != Coord(town_coord.x(), town_coord.y()) || road_side != RoadSide::DOWN)) {
			throw std::invalid_argument("Town and road aren't touch");
		}
	}
	crr_engine = (EngineStartStage *)_crr_engine;
	if(_players[_crr_player_num] != player) {
		throw std::invalid_argument("Another player turn");
	}
// END OF CHECK
	_game->field().link_road(*crr_road, road_coord, road_side);
	_game->field().link_locality(*crr_town, town_coord, town_corner);
	if(!crr_engine->first_line) {
		if (town_corner == CrossCorner::TOP) {
			if(crr_field.has_hex(town_coord) && crr_field.hex(town_coord).has_resource()) {
				crr_pl->bank().add(crr_field.hex(town_coord).resource(), 1);
				_game->field().bank().remove(crr_field.hex(town_coord).resource(), 1);
			}
			crr_coord = Coord(town_coord.x(), town_coord.y() + 1);
			if(crr_field.has_hex(crr_coord) && crr_field.hex(crr_coord).has_resource()) {
				crr_pl->bank().add(crr_field.hex(crr_coord).resource(), 1);
				_game->field().bank().remove(crr_field.hex(crr_coord ).resource(), 1);
			}
			crr_coord = Coord(town_coord.x() - 1, town_coord.y() + 1);
			if(crr_field.has_hex(crr_coord) && crr_field.hex(crr_coord).has_resource()) {
				crr_pl->bank().add(crr_field.hex(crr_coord).resource(), 1);
				_game->field().bank().remove(crr_field.hex(crr_coord ).resource(), 1);
			}
			
		} else if (town_corner == CrossCorner::BOTTOM) {
			if(crr_field.has_hex(town_coord) && crr_field.hex(town_coord).has_resource()) {
				crr_pl->bank().add(crr_field.hex(town_coord).resource(), 1);
				_game->field().bank().remove(crr_field.hex(town_coord).resource(), 1);
			}
			crr_coord = Coord(town_coord.x(), town_coord.y() - 1);
			if(crr_field.has_hex(crr_coord) && crr_field.hex(crr_coord).has_resource()) {
				crr_pl->bank().add(crr_field.hex(crr_coord).resource(), 1);
				_game->field().bank().remove(crr_field.hex(crr_coord ).resource(), 1);
			}
			crr_coord = Coord(town_coord.x() + 1, town_coord.y() - 1);
			if(crr_field.has_hex(crr_coord) && crr_field.hex(crr_coord).has_resource()) {
				crr_pl->bank().add(crr_field.hex(crr_coord).resource(), 1);
				_game->field().bank().remove(crr_field.hex(crr_coord ).resource(), 1);
			}
			
		}
	}
	if(crr_engine->first_line) {
		_crr_player_num++;
		if (_crr_player_num == _players.size()) {
			crr_engine->first_line = false;
			_crr_player_num--;
		}
	} else {
		if (_crr_player_num == 0) {
			_crr_player_num = 0;
			delete _crr_engine;
			_crr_engine = new EngineFirstStage;
			_crr_stage = GameStage::STAGE1_DICE;
		} else {
			_crr_player_num--;
		}
	}
	
}

void GameEngine::make_dice(const std::string &player, size_t dice) 
{
	Field &crr_field = _game->field();
	EngineFirstStage *crr_engine = (EngineFirstStage *)_crr_engine;
	if (_crr_stage != GameStage::STAGE1_DICE) {
		throw std::invalid_argument("Incorrect stage!");
	}
	if (_players[_crr_player_num] != player) {
		throw std::invalid_argument("Another player turn");
	}
	if (dice < 2 || dice > 12) {
		throw std::invalid_argument("Incorrect dice value");
	}
	if (dice == 7) {
		/* Drop res part */
		bool flag = false;
		
		for(size_t i = 0; i < _game->num_players(); i++) {
			if(_game->player(i).bank().resources() >= 7) {
				flag = true;
				crr_engine->_to_transfer[_game->player(i).name()] = _game->player(i).bank().resources() / 2;
			}
		}
		if (flag) {
			_crr_stage = GameStage::STAGE1_DROP_RESOURCES;
		} else {
			_crr_stage = GameStage::STAGE1_MOVE_ROBBER;
		}
	} else {
		/* Local var to save num of taken res */
		Coord crr_coord;
		//Locality * crr_loc;
		std::map<std::string, std::map<Resource, size_t> >  give_res;
		std::set<std::pair<Locality *, Resource>> proc_loc;
		for (size_t i = 0; i < crr_field.num_hexes(); i++) {
			if (crr_field.hex(i).has_number() && crr_field.hex(i).number() == dice) {
				crr_coord = crr_field.coord(crr_field.hex(i));
				if (crr_field.has_locality(crr_coord, CrossCorner::TOP)) {
					proc_loc.insert(std::make_pair(&crr_field.locality(crr_coord, CrossCorner::TOP), crr_field.hex(i).resource()));
				}
				crr_coord = Coord(crr_field.coord(crr_field.hex(i)).x() + 1, crr_field.coord(crr_field.hex(i)).y() - 1);
				if (crr_field.has_locality(crr_coord, CrossCorner::TOP)) {
					proc_loc.insert(std::make_pair(&crr_field.locality(crr_coord, CrossCorner::TOP), crr_field.hex(i).resource()));
				}
				crr_coord = Coord(crr_field.coord(crr_field.hex(i)).x(), crr_field.coord(crr_field.hex(i)).y() - 1);
				if (crr_field.has_locality(crr_coord, CrossCorner::TOP)) {
					proc_loc.insert(std::make_pair(&crr_field.locality(crr_coord, CrossCorner::TOP), crr_field.hex(i).resource()));
				}
				crr_coord = Coord(crr_field.coord(crr_field.hex(i)).x() - 1, crr_field.coord(crr_field.hex(i)).y() + 1);
				if (crr_field.has_locality(crr_coord, CrossCorner::BOTTOM)) {
					proc_loc.insert(std::make_pair(&crr_field.locality(crr_coord, CrossCorner::BOTTOM), crr_field.hex(i).resource()));
				}
				crr_coord = Coord(crr_field.coord(crr_field.hex(i)).x(), crr_field.coord(crr_field.hex(i)).y() + 1);
				if (crr_field.has_locality(crr_coord, CrossCorner::BOTTOM)) {
					proc_loc.insert(std::make_pair(&crr_field.locality(crr_coord, CrossCorner::BOTTOM), crr_field.hex(i).resource()));
				}
				crr_coord = crr_field.coord(crr_field.hex(i));
				if (crr_field.has_locality(crr_coord, CrossCorner::BOTTOM)) {
					proc_loc.insert(std::make_pair(&crr_field.locality(crr_coord, CrossCorner::BOTTOM), crr_field.hex(i).resource()));
				}
			}
		}
		for(auto &it: proc_loc) {
			if (it.first->is_city()) {
				give_res[it.first->player().name()][it.second] += 2;
			} else {
				give_res[it.first->player().name()][it.second] += 1;	
			}
		}
		/* Players take res with right order*/
		size_t av_res;
		size_t res_to_pl; 
		Resource crr_res;
		for (size_t i = 0; i < _players.size(); i++) {
			if (give_res.find(_players[i]) != give_res.end()) {
				for(auto &it: give_res[_players[i]]) {
					crr_res = it.first;
					av_res = crr_field.bank().resources(crr_res);
					res_to_pl = it.second;
					player_by_name(_players[i])->bank().add(crr_res, std::min(av_res, res_to_pl));
					crr_field.bank().remove(crr_res, std::min(av_res, res_to_pl));
				}
			}
		}
		_crr_stage = GameStage::STAGE2;
		delete _crr_engine;
		/* TODO new engine */	
		
}

void drop_resource(const std::string &player, Resource) 
{
}


const Player &GameEngine::current_player() const 
{
	if(_crr_stage == GameStage::PLAYERS_REGISTRATION) {
		throw std::invalid_argument("Incorrect stage!");
	}
	if(_crr_stage == GameStage::FINAL_STAGE) {
		throw std::invalid_argument("Incorrect stage!");
	}
	return *player_by_name(_players[_crr_player_num]);
}
