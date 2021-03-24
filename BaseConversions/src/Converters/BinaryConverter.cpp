#include "BinaryConversionPCH.h"
#include "BinaryConverter.h"

namespace BinaryConversions
{
	inline Integer GetRemainder(Integer x, Integer base)
	{
		return  x % base;
	}

	Integer BaseConverter::ToBase(Integer decimal, Integer base)
	{
		bool negative = decimal < 0;
		if (negative) decimal *= -1;

		std::string binary;
		while (decimal > 0)
		{
			Integer remainder = GetRemainder(decimal, base);

			decimal = decimal / base;

			char digit = std::to_string(remainder)[0];
			binary.insert(binary.begin(), 1, digit);
		}

		//convert string to integer
		Integer conversion = std::stoll(binary.c_str());

		if (negative) conversion *= -1;

		return conversion;
	}

	Integer BaseConverter::ToDecimal(Integer _decimal, Integer base)
	{
		bool negative = _decimal < 0;
		if (negative) _decimal *= -1;

		std::string str = std::to_string(_decimal);
		Integer decimal = 0;

		int exp = (int)(str.size() - 1);
		for (auto& x : str)
		{
			int digit = (x - '0');
			decimal += digit * (Integer)pow(base, exp--);
		}

		if (negative) decimal *= -1;

		return decimal;
	}


	Integer BinaryConverter::ToBase(Integer decimal)
	{
		return BaseConverter::ToBase(decimal, 2);
	}

	Integer BinaryConverter::ToDecimal(Integer decimal)
	{
		return BaseConverter::ToDecimal(decimal, 2);
	}

}