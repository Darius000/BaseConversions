#pragma once

#include "BinaryConverter.h"
#include "Types/HexaDecimal.h"

namespace BinaryConversions
{
	class HexaDecimalConverter;

	

	class HexaDecimalConverter
	{

	public:
		HexaDecimalConverter() = default;

		HexaDecimal ToBase(Integer decimal);
		Integer ToDecimal(HexaDecimal decimal);
	};
}