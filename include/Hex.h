#pragma once
#include "Resource.h"
#include <cstddef>
#include <stdexcept>

class Hex 
{
	bool _has_resource;
	Resource _resource;
	bool _has_number;
	size_t _number;
	Hex (const Hex &) = delete;
	Hex &operator= (const Hex &) = delete;
public:
	Hex();
	void set_number(size_t n); 				//– поставить номерной жетон с номером n, если жетона нет на гексе, иначе сгенерировать исключение std::logic_error с непустым информативным сообщением
	void unset_number(); 					//– убрать номерной жетон, если он был, иначе сгенерировать исключение std::logic_error с непустым информативным сообщением
	bool has_number() const noexcept;  		// – истина тогда и только тогда, когда на этом гексе есть номерной жетон
	size_t number() const; 					//– номер на жетоне на этом гексе, если он есть, иначе генерируется исключение std::logic_error с непустым информативным сообщением
	void set_resource(Resource); 			//– установить, что гекс порождает указанный тип ресурса, если до этого он не порождал, иначе генерировать исключение std::logic_error с непустым информативным сообщением
	void unset_resource(); 					//– установить, что гекс не порождает ресурсы, если до этого он порождал, иначе генерировать исключение std::logic_error с непустым информативным сообщением
	bool has_resource() const noexcept; 	//– истинно тогда и только тогда, когда гекс порождает некоторый тип ресурса
	Resource resource() const; 				//– тип ресурса, получаемого с данного гекса, если гекс порождает ресурс, иначе генерировать исключение std::logic_error с непустым информативным сообщением
};
