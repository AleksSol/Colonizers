#pragma once

enum class RoadSide {
	UP,
	RIGHT,
	DOWN
};

bool operator > (const RoadSide &, const RoadSide &) = delete;
bool operator < (const RoadSide &, const RoadSide &) = delete;
bool operator <= (const RoadSide &, const RoadSide &) = delete;
bool operator >= (const RoadSide &, const RoadSide &) = delete;
bool operator == (const RoadSide &, const RoadSide &) = delete;
bool operator != (const RoadSide &, const RoadSide &) = delete;
RoadSide operator + (const RoadSide &, const RoadSide &) = delete;
RoadSide operator - (const RoadSide &, const RoadSide &) = delete;
RoadSide operator ++(RoadSide &) = delete;
RoadSide operator --(RoadSide &) = delete;
RoadSide operator ++(RoadSide &, int) = delete;
RoadSide operator --(RoadSide &, int) = delete;
RoadSide operator * (const RoadSide &, const RoadSide &) = delete;
RoadSide operator / (const RoadSide &, const RoadSide &) = delete;
RoadSide operator % (const RoadSide &, const RoadSide &) = delete;
RoadSide operator += (const RoadSide &, const RoadSide &) = delete;
RoadSide operator -= (const RoadSide &, const RoadSide &) = delete;
RoadSide operator *= (const RoadSide &, const RoadSide &) = delete;
RoadSide operator /= (const RoadSide &, const RoadSide &) = delete;
