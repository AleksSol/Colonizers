#include "Coord.h"

Coord::Coord() 
{
	_x = 0;
	_y = 0;
}
Coord::Coord(int x, int y) 
	: _x(x), _y(y)
{
}

int Coord::x() const
{
	return _x;
}
int Coord::y() const 
{
	return _y;
}
void Coord::change(int x, int y) 
{
	_x = x;
	_y = y;
}

bool Coord::operator==(Coord b)
{
	if(_x == b.x() && _y == b.y()) {
		return true;
	}
	return false;
}
bool operator<(const Coord a, const Coord b)
{
	if(a.x() < b.x()) {
		return true;
	} else if(a.x() == b.x() && a.y() <b.y()) {
		return true;
	}
	return false;
}
