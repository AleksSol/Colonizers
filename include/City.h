#pragma once
#include "Locality.h" 

class City : public Locality   
{
    City (const City &) = delete;
    City &operator= (const City &) = delete;
public:
    City(const std::string &name, Player &player) : Locality(name, player) {}
    virtual bool is_town() const noexcept override
    {
        return false; 
    }           
    virtual bool is_city() const noexcept override 
    {
        return true;
    }       
    virtual bool is_road() const noexcept override 
    {
        return false;
    }
};


