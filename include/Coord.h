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
    int _x;
    int _y;
};

bool operator<(const Coord a, const Coord b);
bool operator==(const Coord &a, const Coord &b);
bool operator!=(const Coord &a, const Coord &b);
