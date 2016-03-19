#pragma once
#include <stdexcept>
#include "Resource.h"
#include <cstddef>
#include <vector>
	
class ResourcesHolder {
	std::vector <std::pair<Resource, size_t>>  _resources;
public:
	ResourcesHolder();
	void add(Resource r, size_t n) noexcept;
	void remove(Resource r, size_t n);
	size_t resources(Resource r) const noexcept;
	size_t resources() const noexcept;
};



