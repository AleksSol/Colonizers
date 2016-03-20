#pragma once
#include "Infrastructure.h"
#include "Locality.h"
#include "Road.h"
#include "Town.h"
#include "City.h"
#include "ResourcesHolder.h"
#include <stdexcept>
#include <memory>
#include <vector>
#include <string>

class Player 
{
	std::string _name;
	std::unique_ptr<ResourcesHolder> _bank;
	std::vector < std::unique_ptr<Infrastructure> > _infrastructures;
public:
	Player(const std::string &name); 					//– создает игрока с именем name c пустыми наборами ресурсов и объектов инфраструктуры, не привязанных к полю
	~Player(); 											//– удаляет игрока и его объекты инфраструктуры 
	const std::string &name() const noexcept;			//– имя игрока
	ResourcesHolder &bank() const noexcept; 			//– ресурсы игрока
	Road &add_road(const std::string &); 				//– добавляет дорогу с указанным названием, возвращает созданный объект дороги
	void remove_road(Road &); 							//– удаляет объект дороги, если он был создан этим игроком, иначе генерируется исключение std::logic_error с информативным сообщением
	City &add_city(const std::string &); 				//– добавляет город с указанным названием, возвращает созданный объект города
	void remove_city(City &);							//– удаляет объект города, если он был создан этим игроком, иначе генерируется исключение std::logic_error с информативным сообщением
	Town &add_town(const std::string &);				//– добавляет поселение с указанным названием, возвращает созданный объект поселения
	void remove_town(Town &);							//– удаляет объект поселения, если он был создан этим игроком, иначе генерируется исключение std::logic_error с информативным сообщением 
	size_t num_infrastructures() const noexcept; 		//– общее количество созданных объектов инфраструктуры у игрока
	Infrastructure &infrastructure(size_t i) const; 	//– получить объект инфраструктуры с номером i. i принимает значения от 0 до num_infrastructures()-1. При других значениях i должна возникнуть исключительная ситуация std::out_of_range с непустым информативным сообщением
	size_t num_roads() const noexcept; 					//– общее количество созданных дорог у игрока
	Road &road(size_t i) const; 						//– получить дорогу с номером i. i принимает значения от 0 до num_roads()-1. При других значениях i должна возникнуть исключительная ситуация std::out_of_range с непустым информативным сообщением
	size_t num_towns() const noexcept; 					//– общее количество созданных поселений у игрока
	Town &town(size_t i) const; 						//– получить поселение с номером i. i принимает значения от 0 до num_towns()-1. При других значениях i должна возникнуть исключительная ситуация std::out_of_range с непустым информативным сообщением
	size_t num_cities() const noexcept; 				//– общее количество созданных городов у игрока
	City &city(size_t i) const; 						//– получить город с номером i. i принимает значения от 0 до num_cities()-1. При других значениях i должна возникнуть исключительная ситуация std::out_of_range с непустым информативным сообщением
};



