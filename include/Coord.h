#pragma once

class Coord 
{
public:
	Coord();
	Coord(int x, int y);
	int x() const;
	int y() const;
	void change(int x, int y);
	bool operator==(Coord b);
private:
	//Coord (const Coord &) = delete;
	//Coord &operator= (const Coord &) = delete;
	int _x;
	int _y;
};

bool operator<(const Coord a, const Coord b);
