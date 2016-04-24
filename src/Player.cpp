#include "Player.h"
#include <iostream>

Player::Player(const std::string &name)
    : _name(name), _bank(std::unique_ptr<ResourcesHolder>(new ResourcesHolder())),  _roads(), _cities(), _towns()
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
    _roads.push_back(std::unique_ptr <Road> (new_road));
    return *new_road;
}               
void Player::remove_road(Road &road)
{
    for(auto it = _roads.begin(); it != _roads.end(); it++) {
        if(it->get() == &road) {
            _roads.erase(it);
            return;
        }
    }
    throw std::logic_error("Player haven't this road!");
}                           //– удаляет объект дороги, если он был создан этим игроком, иначе генерируется исключение std::logic_error с информативным сообщением
City &Player::add_city(const std::string &name)
{
    City *new_city = new City(name, *this);
    _cities.push_back(std::unique_ptr <City> (new_city));
    return *new_city;
}               
void Player::remove_city(City &city)
{
    for(auto it = _cities.begin(); it != _cities.end(); it++) {
        if(it->get() == &city) {
            _cities.erase(it);
            return;
        }
    }
     throw std::logic_error("Player haven't this city!");
}
                            
Town &Player::add_town(const std::string &name)
{
    Town *new_town = new Town(name, *this);
    _towns.push_back(std::unique_ptr <Town> (new_town));
    return *new_town;
}               
void Player::remove_town(Town & town)
{
    for(auto it = _towns.begin(); it != _towns.end(); it++) {
        if(it->get() == &town) {
            _towns.erase(it);
            return;
        }
    }
    throw std::logic_error("Player haven't this town!");
}                           //– удаляет объект поселения, если он был создан этим игроком, иначе генерируется исключение std::logic_error с информативным сообщением 
size_t Player::num_infrastructures() const noexcept
{
    return _towns.size() + _roads.size() + _cities.size();
}       
Infrastructure &Player::infrastructure(size_t i) const
{
    if (i + 1> num_infrastructures() ) {
        throw std::out_of_range("This player haven't enought infrastructure!");
    }
	if( i + 1 <= num_cities()) {
		return *(_cities[i].get());
	} else {
		i = i - num_cities();
	}
	if( i + 1 <=	 num_towns()) {
		return *(_towns[i].get());
	} else {
		i = i - num_towns();
	}
	return *(_roads[i].get());
}

size_t Player::num_roads() const noexcept
{
	return _roads.size();
}                   //– общее количество созданных дорог у игрока
Road &Player::road(size_t i) const
{
    if (i + 1 > num_roads()) {
		
        throw std::out_of_range("This player haven't enought roads!");
    }
    return *_roads[i];
}                       //– получить дорогу с номером i. i принимает значения от 0 до num_roads()-1. При других значениях i должна возникнуть исключительная ситуация std::out_of_range с непустым информативным сообщением

size_t Player::num_towns() const noexcept
{
    return _towns.size();
}           //– общее количество созданных поселений у игрока
Town &Player::town(size_t i) const
{
    if (i + 1 > num_towns()) {
        throw std::out_of_range("This player haven't enought towns!");
    }
    return *_towns[i];
}                       //– получить поселение с номером i. i принимает значения от 0 до num_towns()-1. При других значениях i должна возникнуть исключительная ситуация std::out_of_range с непустым информативным сообщением
size_t Player::num_cities() const noexcept
{
	return _cities.size();
}               //– общее количество созданных городов у игрока
City &Player::city(size_t i) const
{
	
    if (i + 1 > num_cities()) {
        throw std::out_of_range("This player haven't enought cities!");
    }
    return *_cities[i];
}                       //– получить город с номером i. i принимает значения от 0 до num_cities()-1. При других значениях i должна возникнуть исключительная ситуация std::out_of_range с непустым информативным сообщением

