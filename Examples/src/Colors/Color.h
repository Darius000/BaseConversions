#pragma once

#include <BaseConversions.h>


namespace BinaryConversions
{ 
	struct Color
	{
		Color();
		~Color();
		Color(const Color& c);
		Color(const HexColor& hex);
		Color(int _r, int _g, int _b , int _a);

		Color& operator=(const Color& c);

		int* data = nullptr;

		static HexColor ToHex(const Color& c);
		void ParseFromString(std::string_view s);

		friend std::ostream& operator<<(std::ostream& os, const Color& color);

		friend std::istream& operator>>(std::istream& is, Color& color);

	private:
		static HexaDecimalConverter converter;
	};

	inline std::ostream& operator<<(std::ostream& os, const Color& color)
	{
		return os << "{" << color.data[0] << "," << color.data[1] << 
			"," << color.data[2] << "," << color.data[3] << "}";
	}

	inline std::istream& operator>>(std::istream& is, Color& color)
	{			
		is.ignore();
		std::string s;
		getline(is, s);
		color.ParseFromString(s);
		return is ;
	}
}
