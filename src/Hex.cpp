#include "Hex.h"

Hex::Hex() :  _has_resource(false), _has_number(false)
{
}

void Hex::set_number(size_t n)
{
    if(_has_number) {
        throw std::logic_error("This Hex already have number!\n");
    }
    _has_number = true;
    _number = n;
}

void Hex::unset_number() 
{
    if(!_has_number) {
        throw std::logic_error("This Hex haven't number!\n");
    }
    _has_number = false;
}

bool Hex::has_number() const noexcept
{
    return _has_number;
} 

size_t Hex::number()const 
{
    if(!_has_number) {
        throw std::logic_error("This Hex haven't number!\n");
    }
    return _number;
}

void Hex::set_resource(Resource r)
{
    if(_has_resource) {
        throw std::logic_error("This Hex is already produce resource!\n");
    }
    _has_resource = true;
    _resource = r;
} 

void Hex::unset_resource()
{
    if(!_has_resource) {
        throw std::logic_error("This Hex isn't produce resource!\n");
    }
    _has_resource = false;
} 

bool Hex::has_resource() const noexcept 
{
    return _has_resource;
}

Resource Hex::resource() const 
{
    if(!_has_resource) {
        throw std::logic_error("This Hex isn't produce resource!\n");
    }
    return _resource;
}
