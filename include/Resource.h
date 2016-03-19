#pragma once

enum class Resource 
{
	 GRAIN, 
	 CLAY, 
	 ORE, 
	 WOOL, 
	 WOOD
};

bool operator > (const Resource &, const Resource &) = delete;
bool operator < (const Resource &, const Resource &) = delete;
bool operator <= (const Resource &, const Resource &) = delete;
bool operator >= (const Resource &, const Resource &) = delete;
bool operator == (const Resource &, const Resource &) = delete;
bool operator != (const Resource &, const Resource &) = delete;
Resource operator + (const Resource &, const Resource &) = delete;
Resource operator - (const Resource &, const Resource &) = delete;
Resource operator ++(Resource &) = delete;
Resource operator --(Resource &) = delete;
Resource operator ++(Resource &, int) = delete;
Resource operator --(Resource &, int) = delete;
Resource operator * (const Resource &, const Resource &) = delete;
Resource operator / (const Resource &, const Resource &) = delete;
Resource operator % (const Resource &, const Resource &) = delete;
Resource operator += (const Resource &, const Resource &) = delete;
Resource operator -= (const Resource &, const Resource &) = delete;
Resource operator *= (const Resource &, const Resource &) = delete;
Resource operator /= (const Resource &, const Resource &) = delete;
