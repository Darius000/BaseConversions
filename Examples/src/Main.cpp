// BinaryCOnversion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <BaseConversions.h>
#include "Colors/Color.h"

void HandleBinary();
void HandleHex();
void HandleOtherBase();
void HandleHexColor();

int main()
{
    bool running = true;

    while(running)
    { 
        std::cout << "0 Exit, 1. Binary, 2. Hex, 3. Other Base, 4. Color" << std::endl;

        int n = -1;
        std::cin >> n;

        if (n == 0)
        {
            running = false;
        }
        else if (n == 1)
        {
           HandleBinary();
        }
		else if (n == 2)
		{
			HandleHex();
		}
		else if( n== 3)
		{
			HandleOtherBase();
		}
		else if(n == 4)
		{
			HandleHexColor();
		}
    }

    return 0;
}

void HandleBinary()
{
	int j;
	std::cout << "1. To Decimal, 2. To Base" << std::endl;
	std::cin >> j;

	BinaryConversions::BinaryConverter converter;
	if (j == 1)
	{
		std::cout << "Input Binary" << std::endl;
		BinaryConversions::Integer binary;
		std::cin >> binary;
		std::cout << converter.ToDecimal(binary) << std::endl;
	}
	else if (j == 2)
	{
		std::cout << "Input decimal" << std::endl;
		BinaryConversions::Integer decimal;
		std::cin >> decimal;
		std::cout << converter.ToBase(decimal) << std::endl;
	}
}

void HandleHex()
{
	int j;
	std::cout << "1. To Decimal, 2. To Base" << std::endl;
	std::cin >> j;

	BinaryConversions::HexaDecimalConverter converter;
	if (j == 1)
	{
		std::cout << "Input Hex" << std::endl;
		BinaryConversions::HexaDecimal hex;
		std::cin >> hex;
		std::cout << converter.ToDecimal(hex) << std::endl;
	}
	else if (j == 2)
	{
		std::cout << "Input decimal" << std::endl;
		BinaryConversions::Integer decimal;
		std::cin >> decimal;
		std::cout << converter.ToBase(decimal) << std::endl;
	}
}

void HandleOtherBase()
{
	int j;
	std::cout << "1. To Decimal, 2. To Base" << std::endl;
	std::cin >> j;

	BinaryConversions::BaseConverter converter;
	BinaryConversions::Integer decimal, base;
	if (j == 1)
	{
		std::cout << "Input Number and Base" << std::endl;
		std::cin >> decimal;
		std::cin >> base;
		std::cout << converter.ToDecimal(decimal, base) << std::endl;
	}
	else if (j == 2)
	{
		std::cout << "Input Number and Base" << std::endl;
		std::cin >> decimal;
		std::cin >> base;
		std::cout << converter.ToBase(decimal, base) << std::endl;
	}
}

void HandleHexColor()
{
	int j;
	std::cout << "1. To Color, 2. To Hex Color" << std::endl;
	std::cin >> j;

	if (j == 1)
	{
		std::cout << "Input HexColor" << std::endl;
		
		BinaryConversions::HexColor hex;
		std::cin >> hex;
		BinaryConversions::Color color(hex);
		std::cout << color << std::endl;
	}
	else if (j == 2)
	{
		std::cout << "Input Color" << std::endl;
		BinaryConversions::Color color;
		std::cin >> color;
		std::cout << BinaryConversions::Color::ToHex(color) << std::endl;
	}
}