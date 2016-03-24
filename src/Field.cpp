#include "Field.h"

Field::Field()
    : _is_robber(false), _robber(), _bank(std::unique_ptr<ResourcesHolder> (new ResourcesHolder())), _hex(), _locality(), _road()
{
}

Field::~Field() 
{
}

ResourcesHolder &Field::bank() const noexcept
{
    return *_bank;
}

Hex &Field::put_hex(Coord position)
{
    if(has_hex(position)) {
        throw std::logic_error("Hex at this pos alredy exist!\n");
    }
    Hex *new_hex = new Hex();
    _hex.insert(std::make_pair(position, std::unique_ptr<Hex>(new_hex)));
    return *new_hex;
}

void Field::remove_hex(Coord position)
{
    if(!has_hex(position)) {
        throw std::logic_error("Hex at this position isn't exist!\n");
    }
    _hex.erase(_hex.find(position));
}

Hex &Field::hex(Coord pos) const 
{
    if(!has_hex(pos)) {
        throw std::logic_error("There is no hex!\n");
    }
    return *(_hex.at(pos));
}

Coord Field::coord(Hex & tgt_hex) const
{
    for(auto &it : _hex) {
        if (it.second.get() == &tgt_hex) {
            return it.first;
        }
    }
    throw std::logic_error("This hex isn't in field!\n");
}

bool Field::has_hex(Coord position) const noexcept
{
    if(_hex.find(position) == _hex.end()) {
        return false;
    }
    return true;
}

size_t Field::num_hexes() const noexcept
{
    return _hex.size();
}

Hex &Field::hex(size_t i) const
{
    if (i + 1 > num_hexes()) {
        throw std::out_of_range("This player haven't enought hex!\n");
    }
    size_t j = 0;
    for(auto it = _hex.begin(); it !=_hex.end(); it++) {
        if(i == j) {
            return *(it->second);
        }
        j++;
    }
    throw std::out_of_range("This player haven't enought hex!\n");
}

void Field::link_road(Road &new_road, Coord position, RoadSide side)
{
    if(has_road(position, side)) {
        throw std::logic_error("This position isn't empty!\n");
    }
    if(linked(new_road)) {
        throw std::logic_error("This road already linked!\n");
    }
    _road.insert(std::make_pair(std::make_pair(position,side), &new_road));
}

void Field::unlink_road(Coord position, RoadSide side)
{
    if(!has_road(position, side)) {
        throw std::logic_error("This position is empty!\n");
    }
    _road.erase(_road.find(std::make_pair(position, side)));
}

void Field::unlink_road(Road &road)
{
    for(auto &it : _road) {
        if (it.second == &road) {
            _road.erase(_road.find(it.first));
            return;
        }
    }
    throw std::logic_error("This road isn't exist!\n");
}

bool Field::has_road(Coord position, RoadSide side) const noexcept
{
    if(_road.find(std::make_pair(position, side)) == _road.end()) {
        return false;
    }
    return true;
}

Road &Field::road(Coord position, RoadSide side) const
{
    if (!has_road(position, side)) {
        throw std::logic_error("This road isn't exist!\n");
    }
    return *(_road.find(std::make_pair(position,side))->second);
} 

std::pair<Coord, RoadSide> Field::coord(Road &road) const
{
    for(auto &it : _road) {
        if (it.second == &road) {
            return it.first;
        }
    }
    throw std::logic_error("This road isn't exist!\n");
}


void Field::link_locality(Locality &new_locality, Coord position, CrossCorner side)
{
    if(has_locality(position, side)) {
        throw std::logic_error("This position isn't empty!\n");
    }
    if( linked(new_locality)) {
        throw std::logic_error("This locality already linked!\n");
    }
    _locality.insert(std::make_pair(std::make_pair(position,side), &new_locality));
}

void Field::unlink_locality(Coord position, CrossCorner side)
{
    if(!has_locality(position, side)) {
        throw std::logic_error("This position is empty!\n");
    }
    _locality.erase(_locality.find(std::make_pair(position, side)));
}

void Field::unlink_locality(Locality &locality)
{
    for(auto &it : _locality) {
        if (it.second == &locality) {
            _locality.erase(_locality.find(it.first));
            return;
        }
    }
    throw std::logic_error("This Locality isn't exist!\n");
}

bool Field::has_locality(Coord position, CrossCorner side) const noexcept
{
    if(_locality.find(std::make_pair(position, side)) == _locality.end()) {
        return false;
    }
    return true;
}

Locality &Field::locality(Coord position, CrossCorner side) const
{
    if (!has_locality(position, side)) {
        throw std::logic_error("This Locality isn't exist!\n");
    }
    return *((Locality *)_locality.find(std::make_pair(position,side))->second);
} 

std::pair<Coord, CrossCorner> Field::coord(Locality &locality) const
{
    for(auto &it : _locality) {
        if (it.second == &locality) {
            return it.first;
        }
    }
    throw std::logic_error("This Locality isn't exist!\n");
}

void Field::set_robber(Coord position) noexcept
{
    if(has_robber()) {
        throw std::logic_error("Robber is exist!");
    }
    _is_robber = true;
    _robber = position;
}                                   

void Field::unset_robber()
{
    if(!has_robber()) {
        throw std::logic_error("Robber isn't exist!");
    }
    _is_robber = false;
}
                                            
bool Field::has_robber() const noexcept
{
    return _is_robber;
}                                   

Coord Field::robber() const
{
    if(!has_robber()) {
        throw std::logic_error("Robber isn't exist!");
    }
    return _robber;
}

bool Field::linked(const Infrastructure &infr) const noexcept
{
    for(auto &it : _locality) {
        if((Infrastructure *)it.second == &infr) {
            return true;
        }
    }
    for(auto &it : _road) {
        if((Infrastructure *)it.second == &infr) {
            return true;
        }
    }
    return false;
}

