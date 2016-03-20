#include "Player.h"

Player::Player(const std::string &name)
	: _name(name), _bank(new ResourcesHolder()), _infrastructures()
{
}
					
Player::~Player()
{
} 											
const std::string &Player::name() const noexcept
{
	return Player::_name;
}		
ResourcesHolder &Player::bank() const noexcept
{
	return *_bank;
} 			
Road &Player::add_road(const std::string &name)
{
	Road *new_road = new Road(name, *this);
	_infrastructures.push_back(std::unique_ptr <Infrastructure> (new_road));
	return *new_road;
} 				
void Player::remove_road(Road &road)
{
	if(&road.player() != this) {
		throw std::logic_error("Player haven't this road!\n");
	}
	for(auto it = _infrastructures.begin(); it != _infrastructures.end(); it++) {
		if(it->get() == &road) {
			_infrastructures.erase(it);
			return;
		}
	}
	throw std::logic_error("Road isn't in players infrastructures!\n");
}							//– удаляет объект дороги, если он был создан этим игроком, иначе генерируется исключение std::logic_error с информативным сообщением
City &Player::add_city(const std::string &name)
{
	City *new_city = new City(name, *this);
	_infrastructures.push_back(std::unique_ptr <Infrastructure> (new_city));
	return *new_city;
} 				
void Player::remove_city(City &city)
{
	if(&city.player() != this) {
		throw std::logic_error("Player haven't this city!\n");
	}
	for(auto it = _infrastructures.begin(); it != _infrastructures.end(); it++) {
		if(it->get() == &city) {
			_infrastructures.erase(it);
			return;
		}
	}
	throw std::logic_error("City isn't in players infrastructures!\n");
}
							
Town &Player::add_town(const std::string &name)
{
	Town *new_town = new Town(name, *this);
	_infrastructures.push_back(std::unique_ptr <Infrastructure> (new_town));
	return *new_town;
}				
void Player::remove_town(Town & town)
{
	if(&town.player() != this) {
		throw std::logic_error("Player haven't this town!\n");
	}
	for(auto it = _infrastructures.begin(); it != _infrastructures.end(); it++) {
		if(it->get() == &town) {
			_infrastructures.erase(it);
			return;
		}
	}
	throw std::logic_error("Town isn't in players infrastructures!\n");
}							//– удаляет объект поселения, если он был создан этим игроком, иначе генерируется исключение std::logic_error с информативным сообщением 
size_t Player::num_infrastructures() const noexcept
{
	return _infrastructures.size();
} 		
Infrastructure &Player::infrastructure(size_t i) const
{
	if (i > (num_infrastructures() - 1) || i < 0) {
		throw std::out_of_range("This player haven't enought infrastructure!\n");
	}
	return *(_infrastructures[i].get());
}

size_t Player::num_roads() const noexcept
{
	size_t size_of_roads = 0;
	for (auto &it : _infrastructures) {
		if (it->is_road()) {
			size_of_roads++;
		}
	}
	return size_of_roads;
} 					//– общее количество созданных дорог у игрока
Road &Player::road(size_t i) const
{
	if (i > (num_roads() - 1) || i < 0) {
		throw std::out_of_range("This player haven't enought roads!\n");
	}
	size_t num_of_road = 0;
	for(auto it = _infrastructures.begin(); it != _infrastructures.end(); it++) {
		if((*it)->is_road()) {
			num_of_road++;
			if(num_of_road == i + 1) {
				return *((Road *)(it->get()));
			}
		}
	}
	throw std::out_of_range("This player haven't enought roads!\n");
}						//– получить дорогу с номером i. i принимает значения от 0 до num_roads()-1. При других значениях i должна возникнуть исключительная ситуация std::out_of_range с непустым информативным сообщением

size_t Player::num_towns() const noexcept
{
	size_t size_of_towns = 0;
	for (auto &it : _infrastructures) {
		if (it->is_town()) {
			size_of_towns++;
		}
	}
	return size_of_towns;
}			//– общее количество созданных поселений у игрока
Town &Player::town(size_t i) const
{
	if (i > (num_towns() - 1) || i < 0) {
		throw std::out_of_range("This player haven't enought towns!\n");
	}
	size_t num_of_town = 0;
	for(auto it = _infrastructures.begin(); it != _infrastructures.end(); it++) {
		if((*it)->is_town()) {
			num_of_town++;
			if(num_of_town == i + 1) {
				return *((Town *)(it->get()));
			}
		}
	}
	throw std::out_of_range("This player haven't enought towns!\n");
}						//– получить поселение с номером i. i принимает значения от 0 до num_towns()-1. При других значениях i должна возникнуть исключительная ситуация std::out_of_range с непустым информативным сообщением
size_t Player::num_cities() const noexcept
{
	size_t size_of_city = 0;
	for (auto &it : _infrastructures) {
		if (it->is_city()) {
			size_of_city++;
		}
	}
	return size_of_city;
} 				//– общее количество созданных городов у игрока
City &Player::city(size_t i) const
{
	if (i > (num_cities() - 1) || i < 0) {
		throw std::out_of_range("This player haven't enought cities!\n");
	}
	size_t num_of_city = 0;
	for(auto it = _infrastructures.begin(); it != _infrastructures.end(); it++) {
		if((*it)->is_city()) {
			num_of_city++;
			if(num_of_city == i + 1) {
				return *((City *)(it->get()));
			}
		}
	}
	throw std::out_of_range("This player haven't enought cities!\n");
} 						//– получить город с номером i. i принимает значения от 0 до num_cities()-1. При других значениях i должна возникнуть исключительная ситуация std::out_of_range с непустым информативным сообщением



