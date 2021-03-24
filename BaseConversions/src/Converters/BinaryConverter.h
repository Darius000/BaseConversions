#pragma once

namespace BinaryConversions
{ 
	//Get the remainder from x % base
	Integer GetRemainder(Integer x, Integer base);

	class Converter;

	class Converter
	{
	public:
		Converter() = default;
		explicit Converter(Integer decimal) {} ;
		virtual ~Converter() = default;

		virtual Integer ToBase(Integer decimal, Integer base) = 0;
		virtual Integer ToDecimal(Integer decimal, Integer base) = 0;

		
	};

	class BaseConverter : public Converter
	{
	public:
		BaseConverter() = default;

		Integer ToBase(Integer decimal, Integer base) override;
		Integer ToDecimal(Integer decimal, Integer base) override;
	};


	class BinaryConverter : public BaseConverter
	{
	public:
		BinaryConverter() = default;

		Integer ToBase(Integer decimal);
		Integer ToDecimal(Integer decimal);
	};

}
