#include "ResourcesHolder.h"

ResourcesHolder:: ResourcesHolder() : _resources()
{
}

void ResourcesHolder:: add(Resource r, size_t n) noexcept
{
	for(auto it = _resources.begin(); it != _resources.end(); it++) {
		if((size_t) it->first == (size_t) r) {
			it->second += n;
			return;
		}
	}
	_resources.push_back(std::make_pair(r, n));
}

void ResourcesHolder:: remove(Resource r, size_t n)
{
	for(auto it = _resources.begin(); it != _resources.end(); it++) {
		if((size_t) it->first == (size_t) r) {
			if(it->second < n) {
				throw std::logic_error("Not enought resources!\n");
			} 
			it->second -= n;
			return;
		}
	}
	if(n != 0) {
		throw std::logic_error("Not enought resources!\n");
	}
}

size_t ResourcesHolder:: resources(Resource r) const noexcept
{
	for(auto it = _resources.begin(); it != _resources.end(); it++) {
		if((size_t) it->first == (size_t) r) {
			return it->second;
		}
	}
	return 0;
}

size_t ResourcesHolder:: resources() const noexcept
{
	size_t res_size = 0;
	for(auto &it: _resources)  {
		res_size += it.second;
	}
	return res_size;
	return 0;
}
