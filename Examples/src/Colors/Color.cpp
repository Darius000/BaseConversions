#include "Color.h"

namespace BinaryConversions
{
	Color::Color(const HexColor& hex)
		:Color()
	{
		data[0] = (int)converter.ToDecimal(hex.r);
		data[1] = (int)converter.ToDecimal(hex.g);
		data[2] = (int)converter.ToDecimal(hex.b);
		data[3] = (int)converter.ToDecimal(hex.a);
	}

	Color::Color()
	{
		data = new int[4];
	}

	Color::Color(int _r, int _g, int _b, int _a)
		:Color()
	{
		data[0] = _r;
		data[1] = _g;
		data[2] = _b;
		data[3] = _a;
	}

	Color::Color(const Color& c)
		:Color()
	{
		for (int i = 0; i < 4; i++)
		{
			data[i] = c.data[i];
		}
	}

	Color& Color::operator=(const Color& c)
	{
		for (int i = 0; i < 4; i++)
		{
			data[i] = c.data[i];
		}

		return *this;
	}

	Color::~Color()
	{
		delete[] data;
	}

	HexColor Color::ToHex(const Color& c)
	{
		HexaDecimal rhex = converter.ToBase(c.data[0]);
		HexaDecimal ghex = converter.ToBase(c.data[1]);
		HexaDecimal bhex = converter.ToBase(c.data[2]);
		HexaDecimal ahex = converter.ToBase(c.data[3]);

		return HexColor(rhex, ghex, bhex, ahex);
	}

	void Color::ParseFromString(std::string_view s)
	{
		std::stringstream ss(s.data());

		bool commaSep = s.find(',') != std::string::npos;
		char delim = commaSep ? ',' : ' ';

		int i = 0;
		while (ss.good() && i < 4)
		{
			std::string num;
			getline(ss, num, delim);
			data[i] = stoi(num);
			i++;
		}
	}

	HexaDecimalConverter Color::converter;

}