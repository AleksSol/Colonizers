#pragma once
#include <string>

class Player;

class Infrastructure {
	Player &_player;
	std::string _name;
public:
	Infrastructure(const std::string &name, Player &); 	//– запоминает, что этот объект имеет указанное название и создан указанным игроком; игрок хранится вне объекта класса Infrastructure, название хранится в объекте класса Infrastructure
	Player &player() const noexcept; 					//– получить игрока, которому принадлежит данный объект
	const std::string &name() const noexcept; 			//– название объекта
	virtual bool is_town() const noexcept = 0;			//– является ли Infrastructure поселением; будет переопределяться в каждом из классов-потомков
	virtual bool is_city() const noexcept = 0; 			//– является ли Infrastructure городом; будет переопределяться в каждом из классов-потомков
	virtual bool is_road() const noexcept = 0; 			//– является ли Infrastructure дор`огой; будет переопределяться в каждом из классов-потомков 

};
