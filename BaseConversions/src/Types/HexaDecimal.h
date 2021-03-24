#pragma once


#include "Iterators/HexDecimalIterator.h"

namespace BinaryConversions
{
class HexaDecimal
{
public:
		
	using Iterator = HexaDecimalIterator<HexStr>;
		
public:
	HexaDecimal();

	HexaDecimal(const HexStr* hex);

	HexaDecimal(const char a, const char b);

	HexaDecimal(const HexaDecimal& other);

	~HexaDecimal();

	const HexStr* c_str() const { return m_hex; }

	HexSize GetSize() { return g_Size; }

	Iterator begin()
	{
		return Iterator(m_hex);
	}

	Iterator end()
	{
		return Iterator(m_hex + g_Size);
	}

	HexSize push_back(const HexStr& c);

	HexSize push_back(HexStr&& c);

	void pop_pack();

	void insert(HexSize pos, HexStr&& c);

	//operators
	HexaDecimal& operator=(const HexaDecimal& hex) ;

	bool operator==(const HexaDecimal& hex) const;

	bool operator!=(const HexaDecimal& hex) const;

	bool operator> (const HexaDecimal& hex) const;

	bool operator<(const HexaDecimal& hex) const;

	bool operator>= (const HexaDecimal& hex) const;

	bool operator<=(const HexaDecimal& hex) const;

	const HexStr* operator*() const { return m_hex; }

	HexStr& operator[](HexSize index) const;

	HexStr& operator[](HexSize index);

	friend std::ostream& operator<<(std::ostream& os, const HexaDecimal& hex);

	friend std::istream& operator>>(std::istream& is, HexaDecimal& hex);

private:
	void Allocate(const HexStr* hexstr);
	void ReAllocate(HexSize newSize);
	void DeAlloc();

private:
	HexStr* m_hex;
	HexSize g_Size = 0;
	HexSize m_Capacity = 500;
};

inline std::ostream& operator<<(std::ostream& os, const HexaDecimal& hex)
{
	os << hex.m_hex;
	return os;
}

inline std::istream& operator>>(std::istream& is, HexaDecimal& hex)
{
	is >> hex.m_hex;
	return is;
}

}

