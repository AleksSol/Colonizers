#pragma once
#include "ResourcesHolder.h"
#include "Hex.h"
#include "Coord.h"
#include "RoadSide.h"
#include "CrossCorner.h"
#include "Locality.h"
#include "Road.h"
#include <map>
#include <vector>
#include <stdexcept>
#include <memory>
class Field 
{
	bool _is_robber;
	Coord _robber;
	std::unique_ptr<ResourcesHolder> _bank;
	std::map <Coord, std::unique_ptr<Hex>> _hex;
	std::map<std::pair<Coord, CrossCorner>, Locality *> _locality;
	std::map<std::pair<Coord, RoadSide>, Road *> _road;
	Field (const Field &) = delete;
	Field &operator= (const Field &) = delete;
public:
	Field();										 					//– создает пустой банк ресурсов, гексов на поле нет
	~Field(); 															//- удаляет банк ресурсов и объекты гексов
	ResourcesHolder &bank() const noexcept; 							//– банк ресурсов поля 
	Hex &put_hex(Coord); 												//– создать объект гекса у себя, поместить его в указанную координату, вернуть сгенерированный гекс; если же в указанной координате уже был гекс, то сгенерировать исключение std::logic_error с непустым информативным сообщением 
	void remove_hex(Coord); 											//– удалить гекс с указанной координаты, если он был на ней, иначе сгенерировать исключение std::logic_error с непустым информативным сообщением
	Hex &hex(Coord) const; 												//– гекс, расположенный на указанной координате, если в этой координате на поле есть гекс, иначе генерируется исключительная ситуация std::logic_error с информативным сообщением
	Coord coord(Hex &) const; 											//– координата указанного гекса, если он помещен на поле, иначе сгенерировать исключение std::logic_error с непустым информативным сообщением
	bool has_hex(Coord) const noexcept; 								//- истина тогда и только тогда, когда на указанной координате находится гекс
	size_t num_hexes() const noexcept; 									//– количество гексов на поле
	Hex &hex(size_t i) const; 											//– получить гекс с номером i. i принимает значения от 0 до num_hexes()-1. При других значениях i должна возникнуть исключительная ситуация std::out_of_range с непустым информативным сообщением. Номер используется исключительно для итерирования по имеющемуся множеству гексов.
	void link_road(Road &, Coord, RoadSide); 							//– поместить указанную дорогу в указанное место (пару Coord и RoadSide), если это место еще не занято, иначе сгенерировать исключение std::logic_error с непустым информативным сообщением
	void unlink_road(Coord, RoadSide); 									//– убрать с указанного места дорогу, если оно было занято, иначе сгенерировать исключение std::logic_error с непустым информативным сообщением
	void unlink_road(Road &); 											//– убрать указанную дорогу, если она была помещена на поле, иначе сгенерировать исключение std::logic_error с непустым информативным сообщением
	bool has_road(Coord, RoadSide) const noexcept;					 	//– истина тогда и только тогда, когда указанное место занято
	Road &road(Coord, RoadSide) const; 									//– дорога, расположенная в указанном месте, если оно занято, иначе генерируется исключение std::logic_error с непустым информативным сообщением
	std::pair<Coord, RoadSide> coord(Road &) const; 					//– место указанной дороги, если она помещена на поле, иначе сгенерировать исключение std::logic_error с непустым информативным сообщением
	void link_locality(Locality &, Coord, CrossCorner); 				//– поместить указанный населенный пункт в указанное место (пару Coord и CrossCorner), если это место еще не занято, иначе сгенерировать исключение std::logic_error с непустым информативным сообщением
	void unlink_locality(Coord, CrossCorner); 							//– убрать с указанного места населенный пункт, если оно было занято, иначе сгенерировать исключение std::logic_error с непустым информативным сообщением
	void unlink_locality(Locality &); 									//– убрать указанный населенный пункт, если он был помещен на поле, иначе сгенерировать исключение std::logic_error с непустым информативным сообщением
	bool has_locality(Coord, CrossCorner) const noexcept; 				//– истина тогда и только тогда, когда указанное место занято
	Locality &locality(Coord, CrossCorner) const; 						//– населенный пункт, расположенный в указанном месте, если оно занято, иначе генерируется исключение std::logic_error с непустым информативным сообщением
	std::pair<Coord, CrossCorner> coord(Locality &) const; 				//– место указанного населенного пункта, если он помещен на поле, иначе сгенерировать исключение std::logic_error с непустым информативным сообщением
	void set_robber(Coord) noexcept; 									//– поставить разбойника на указанное место; если он где-то был, то он перемещается оттуда в указанное место
	void unset_robber(); 												//– убрать разбойника, если он был в поле, иначе сгенерировать исключение std::logic_error с непустым информативным сообщением
	bool has_robber() const noexcept; 									//–	истина тогда и только тогда, когда на поле есть разбойник
	Coord robber() const; 												//– место, где расположен разбойник, если он есть на поле, иначе сгенерировать исключение std::logic_error с непустым информативным сообщением

};





