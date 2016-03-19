#pragma once

enum class CrossCorner {
	TOP,
	BOTTOM
};

bool operator > (const CrossCorner &, const CrossCorner &) = delete;
bool operator < (const CrossCorner &, const CrossCorner &) = delete;
bool operator <= (const CrossCorner &, const CrossCorner &) = delete;
bool operator >= (const CrossCorner &, const CrossCorner &) = delete;
bool operator == (const CrossCorner &, const CrossCorner &) = delete;
bool operator != (const CrossCorner &, const CrossCorner &) = delete;
CrossCorner operator + (const CrossCorner &, const CrossCorner &) = delete;
CrossCorner operator - (const CrossCorner &, const CrossCorner &) = delete;
CrossCorner operator ++(CrossCorner &) = delete;
CrossCorner operator --(CrossCorner &) = delete;
CrossCorner operator ++(CrossCorner &, int) = delete;
CrossCorner operator --(CrossCorner &, int) = delete;
CrossCorner operator * (const CrossCorner &, const CrossCorner &) = delete;
CrossCorner operator / (const CrossCorner &, const CrossCorner &) = delete;
CrossCorner operator % (const CrossCorner &, const CrossCorner &) = delete;
CrossCorner operator += (const CrossCorner &, const CrossCorner &) = delete;
CrossCorner operator -= (const CrossCorner &, const CrossCorner &) = delete;
CrossCorner operator *= (const CrossCorner &, const CrossCorner &) = delete;
CrossCorner operator /= (const CrossCorner &, const CrossCorner &) = delete;
