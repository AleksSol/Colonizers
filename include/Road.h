#pragma once
#include "Infrastructure.h"

class Road : public Infrastructure 
{
    Road (const Road &) = delete;
    Road &operator= (const Road &) = delete;
public:
    Road(const std::string &name, Player &player) : Infrastructure(name, player) {}
    virtual bool is_town() const noexcept override
    {
        return false;
    }           
    virtual bool is_city() const noexcept override 
    {
        return false;
    }       
    virtual bool is_road() const noexcept override 
    {
        return true;
    }
};


