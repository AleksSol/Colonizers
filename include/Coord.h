#pragma once

class Coord 
{
public:
	Coord();
	Coord(int x, int y);
	int x() const;
	int y() const;
	void change(int x, int y);
	
private:
	Coord (const Coord &) = delete;
	void operator= (const Coord &) = delete;
	int _x;
	int _y;
};
