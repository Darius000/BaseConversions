#pragma once

#include "HexaDecimal.h"

namespace BinaryConversions
{
class HexColor
{
public:
	HexColor();
	HexColor(const HexStr* str);
	HexColor(const HexaDecimal& _r, const HexaDecimal& _g, 
		const HexaDecimal& _b, const HexaDecimal& _a);
	HexColor(const HexColor& other);

public:
	HexaDecimal r;
	HexaDecimal g;
	HexaDecimal b;
	HexaDecimal a;

public:
	//operators
	HexColor& operator=(const HexColor& hex);

	friend std::ostream& operator<<(std::ostream& os, const HexColor& hex);

	friend std::istream& operator>>(std::istream& is, HexColor& hex);

private:
	void Allocate(const HexStr* hexstr);
};

inline std::ostream& operator<<(std::ostream& os, const HexColor& hex)
{
	return os << hex.r << hex.g << hex.b << hex.a;
}

inline std::istream& operator>>(std::istream& is, HexColor& hex)
{
	std::string hstr;
	is >> hstr;
	hex.Allocate(hstr.c_str());
	return is;
}
}
