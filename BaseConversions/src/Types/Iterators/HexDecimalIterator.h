#pragma once

template<typename T>
class HexaDecimalIterator
{
public:
	using Type = T;
	using Pointer = Type*;
	using Reference = Type&;

public:
	HexaDecimalIterator(Pointer ptr)
	:m_Ptr(ptr){}

	HexaDecimalIterator& operator++()
	{
		m_Ptr++;
		return *this;
	}

	HexaDecimalIterator operator++(int)
	{
		HexaDecimalIterator it = *this;
		++(*this);
		return it;
	}

	HexaDecimalIterator& operator--()
	{
		m_Ptr--;
		return *this;
	}

	HexaDecimalIterator operator--(int)
	{
		HexaDecimalIterator it = *this;
		--(*this);
		return it;
	}

	Reference operator[](int index)
	{
		return *(m_Ptr + index);
	}

	Pointer operator->()
	{
		return m_Ptr;
	}

	Reference operator*()
	{
		return *m_Ptr;
	}

	bool operator==(const HexaDecimalIterator& other)
	{
		return m_Ptr == other.m_Ptr;
	}

	bool operator!=(const HexaDecimalIterator& other)
	{
		return m_Ptr != other.m_Ptr;
	}

private:
	Pointer m_Ptr;
};