#include "BinaryConversionPCH.h"
#include "HexColor.h"

namespace BinaryConversions
{
	HexColor::HexColor()
	{
		Allocate("00000000");
	}

	HexColor::HexColor(const HexStr* str)
	{
		Allocate(str);
	}

	HexColor::HexColor(const HexColor& other)
	{
		r = other.r;
		g = other.g;
		b = other.b;
		a = other.a;
	}


	HexColor::HexColor(const HexaDecimal& _r, const HexaDecimal& _g, 
		const HexaDecimal& _b, const HexaDecimal& _a)
	{
		r = _r;
		g = _g;
		b = _b;
		a = _a;
	}

	HexColor& HexColor::operator=(const HexColor& hex)
	{
		r = hex.r;
		g = hex.g;
		b = hex.b;
		a = hex.a;
		return *this;
	}

	void HexColor::Allocate(const HexStr* hexstr)
	{
		assert(strlen(hexstr) == 8);

		r = HexaDecimal(hexstr[0], hexstr[1]);
		g = HexaDecimal(hexstr[2], hexstr[3]);
		b = HexaDecimal(hexstr[4], hexstr[5]);
		a = HexaDecimal(hexstr[6], hexstr[7]);
	}

}