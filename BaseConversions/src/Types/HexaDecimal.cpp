#include "BinaryConversionPCH.h"
#include "HexaDecimal.h"

namespace BinaryConversions
{
	HexaDecimal::HexaDecimal()
	{
		char hex[1] = {'\0'};
		Allocate(hex);
	}

	HexaDecimal::HexaDecimal(const HexStr* hex)
	{
		Allocate(hex);
	}

	HexaDecimal::HexaDecimal(const HexaDecimal& other)
	{
		Allocate(other.m_hex);		
	}

	HexaDecimal::HexaDecimal(const char a, const char b)
	{
		char hex[3] = {a, b, '\0'};
		Allocate(hex);
	}

	HexaDecimal::~HexaDecimal()
	{
		DeAlloc();
	}

	HexSize HexaDecimal::push_back(HexStr&& c)
	{
		if (g_Size > m_Capacity)
		{
			ReAllocate(m_Capacity + m_Capacity / 2);
		}

		new(&m_hex[g_Size++]) HexStr(c);

		m_hex[g_Size] = '\0';

		return g_Size;
	}

	HexSize HexaDecimal::push_back(const HexStr& c)
	{
		if (g_Size > m_Capacity)
		{
			ReAllocate(m_Capacity + m_Capacity / 2);
		}

		new(&m_hex[g_Size++]) HexStr(c);

		m_hex[g_Size] = '\0';

		return g_Size;
	}

	void HexaDecimal::pop_pack()
	{
		if (g_Size > 0)
		{
			g_Size--;
			m_hex[g_Size] = '\0';
		}
	}

	void HexaDecimal::insert(HexSize pos, HexStr&& c)
	{
		if (g_Size > m_Capacity)
		{
			ReAllocate(m_Capacity + m_Capacity / 2);
		}

		auto newBlock = (HexStr*)::operator new(m_Capacity);

		for (HexSize i = 0; i < g_Size; i++)
			new (&newBlock[i]) HexStr(m_hex[i]);

		for (HexSize i = pos; i < g_Size; i++)
			new (&newBlock[i + 1]) HexStr(m_hex[i]);

		new (&newBlock[pos]) HexStr(c);

		new (&newBlock[g_Size + 1]) HexStr('\0');

		::operator delete(m_hex, m_Capacity * sizeof(HexStr));
		m_hex = newBlock;

		++g_Size;
	}

	bool HexaDecimal::operator!=(const HexaDecimal& hex) const
	{
		return !(*this == hex);
	}

	bool HexaDecimal::operator==(const HexaDecimal& hex) const
	{
		for (unsigned int i = 0; i < g_Size; i++)
		{
			if(m_hex[i] != hex.m_hex[i]) return false;
		}

		return true;
	}

	HexaDecimal& HexaDecimal::operator=(const HexaDecimal& hex) 
	{
		Allocate(hex.m_hex);

		return *this;
	}


	bool HexaDecimal::operator>(const HexaDecimal& hex) const
	{
		for (HexSize i = 0; i < g_Size; i++)
		{
			if (m_hex[i] <= hex.m_hex[i]) return false;
		}

		return true;
	}


	bool HexaDecimal::operator<(const HexaDecimal& hex) const
	{
		for (HexSize i = 0; i < g_Size; i++)
		{
			if (m_hex[i] >= hex.m_hex[i]) return false;
		}

		return true;
	}

	HexStr& HexaDecimal::operator[](HexSize index) const
	{
		assert(index <= 1 || index >= 0);

		return m_hex[index];
	}

	HexStr& HexaDecimal::operator[](HexSize index)
	{
		assert(index <= 1 || index >= 0);

		return m_hex[index];
	}

	void HexaDecimal::Allocate(const HexStr* hexstr)
	{
		size_t len = strlen(hexstr);

		//allocate memory
		m_hex = (HexStr*)::operator new(m_Capacity + 1);

		strcpy_s(m_hex, len + 1, hexstr);

		g_Size = (HexSize)len;

		m_hex[g_Size] = '\0';
	}

	void HexaDecimal::ReAllocate(HexSize newSize)
	{

		//allocate memory
		auto newBlock = (HexStr*)::operator new(newSize + 1);

		if (m_Capacity < g_Size)
		{
			g_Size = m_Capacity;
		}

		for (HexSize i = 0; i < g_Size; i++)
			new (&newBlock[i]) HexStr(std::move(m_hex[i]));

		new (&newBlock[g_Size]) HexStr('\0');

		::operator delete(m_hex, m_Capacity * sizeof(HexStr));
		m_hex = newBlock;
		m_Capacity = newSize;
	}

	void HexaDecimal::DeAlloc()
	{
		::operator delete(m_hex, (g_Size + 1) * sizeof(HexStr));
	}

	bool HexaDecimal::operator>=(const HexaDecimal& hex) const
	{
		for (HexSize i = 0; i < g_Size; i++)
		{
			if (m_hex[i] < hex.m_hex[i]) return false;
		}

		return true;
	}

	bool HexaDecimal::operator<=(const HexaDecimal& hex) const
	{
		for (HexSize i = 0; i < g_Size; i++)
		{
			if (m_hex[i] > hex.m_hex[i]) return false;
		}

		return true;
	}
}
