#include "ResourcesHolder.h"

ResourcesHolder:: ResourcesHolder() : _resources()
{
}

void ResourcesHolder:: add(Resource r, size_t n) noexcept
{
    _resources[r]+=n; 
}

void ResourcesHolder:: remove(Resource r, size_t n)
{
    if(_resources[r] < n) {
        throw std::logic_error("Not enought resources!");
    }
    _resources[r] -= n;
}

size_t ResourcesHolder::resources(Resource r) const noexcept
{
    if(_resources.find(r) == _resources.end()) {
        return 0;
    }
    return (const size_t)_resources.at(r);
}

size_t ResourcesHolder:: resources() const noexcept
{
    int res_size = 0;
    for(auto &it : _resources) {
        res_size += it.second;
    }
    return res_size;
}
