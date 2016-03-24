#pragma once
#include <stdexcept>
#include "Resource.h"
#include <cstddef>
#include <map>
    
class ResourcesHolder 
{
    std::map <Resource, size_t>  _resources;
    ResourcesHolder (const ResourcesHolder &) = delete;
    ResourcesHolder &operator= (const ResourcesHolder &) = delete;
public:
    ResourcesHolder();
    void add(Resource r, size_t n) noexcept;
    void remove(Resource r, size_t n);
    size_t resources(Resource r) const noexcept;
    size_t resources() const noexcept;
};



