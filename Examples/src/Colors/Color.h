#pragma once

#include <BaseConversions.h>


namespace BinaryConversions
{ 
	struct Color
	{
		Color();

		Color(const HexColor& hex);
		Color(int _r, int _g, int _b , int _a);

		int r = 0;
		int g = 0;
		int b = 0;
		int a = 255;

		static HexColor ToHex(const Color& c);

		friend std::ostream& operator<<(std::ostream& os, const Color& color);

		friend std::istream& operator>>(std::istream& is, Color& color);

	private:
		static HexaDecimalConverter converter;
	};

	inline std::ostream& operator<<(std::ostream& os, const Color& color)
	{
		return os << "{" << color.r << "," << color.g << "," << color.b << "," << color.a << "}";
	}

	inline std::istream& operator>>(std::istream& is, Color& color)
	{
		return is >> color.r >> color.g >> color.b >> color.a ;
	}
}
