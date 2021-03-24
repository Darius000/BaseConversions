#include "Color.h"

namespace BinaryConversions
{
	Color::Color(const HexColor& hex)
	{
		r = (int)converter.ToDecimal(hex.r);
		g = (int)converter.ToDecimal(hex.g);
		b = (int)converter.ToDecimal(hex.b);
		a = (int)converter.ToDecimal(hex.a);
	}

	Color::Color()
	{

	}

	Color::Color(int _r, int _g, int _b, int _a)
		:r(_r), g(_g), b(_b), a(_a)
	{
		
	}

	HexColor Color::ToHex(const Color& c)
	{
		HexaDecimal rhex = converter.ToBase(c.r);
		HexaDecimal ghex = converter.ToBase(c.g);
		HexaDecimal bhex = converter.ToBase(c.b);
		HexaDecimal ahex = converter.ToBase(c.a);

		return HexColor(rhex, ghex, bhex, ahex);
	}

	HexaDecimalConverter Color::converter;

}