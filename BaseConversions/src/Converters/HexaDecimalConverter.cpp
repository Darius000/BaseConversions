#include "BinaryConversionPCH.h"
#include "HexaDecimalConverter.h"


namespace BinaryConversions
{ 
	HexaDecimal BinaryConversions::HexaDecimalConverter::ToBase(Integer decimal)
	{
		HexaDecimal hex;
		Integer original = decimal;
		bool negative = decimal < 0;
		if (negative) { decimal *= -1; original *= -1; }

		/*if (decimal == 0)
		{
			hex.insert(0, '0');
			hex.insert(0, '0');

			return hex;
		}*/

		Integer temp = 0;
		
		//if less than 10 overall append a 0 to the front
		if (decimal < 10)
		{
			//offset by 48 to get actual number as a char
			temp = decimal + 48;
			
			hex.insert(0 , (HexStr)temp);
			hex.insert(0, '0');

			return hex;
		}

		int i = 0;
		while (decimal != 0 && i >= 0)
		{
			Integer remainder = GetRemainder(decimal, 16);

			decimal = decimal / 16;

			if (remainder < 10)
			{
				//offset by 48 to get 1-9 as a char
				temp = remainder + 48;
				hex.insert(0, (HexStr)temp);
			}
			else
			{
				//offset by 55 to get actual number as a char makes 10-15 -> A-F
				temp = remainder + 55;
				hex.insert(0, (HexStr)temp);
			}

			
		}

		//store negative values with a -
		if (negative) hex.insert(0, '-');

		return hex;
	}

	Integer BinaryConversions::HexaDecimalConverter::ToDecimal(HexaDecimal hex)
	{
		bool negative = false;
		Integer decimal = 0;
		int exp = (int)(hex.GetSize() - 1);
		for (char x : hex)
		{
			//if hex is negative negate decimal at end and skip this char
			if (x == '-')
			{
				negative = true;
				exp--;
				continue;
			}

			int digit = 0;
			if(islower(x)) x = toupper(x);
			if ((x <= 'F' && x >= 'A'))
			{
				digit = x - 55;			
			}
			else
			{
				digit = (x - 48);
			}

			Integer power = (Integer)pow(16, exp--);
			decimal += digit * power;
		}

		if (negative) decimal *= -1;
		return decimal;
	}
}
