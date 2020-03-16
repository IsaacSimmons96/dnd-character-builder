#include "..\headers\cash.h"

#include <iostream>

CASH::CASH( const CASH & cash_in )
{
	m_gold = cash_in.m_gold;
	m_silver = cash_in.m_silver;
	m_copper = cash_in.m_copper;
}

CASH::CASH( uint64_t gold, uint8_t silver, uint8_t copper )
{
	m_gold = gold;
	m_silver = silver;
	m_copper = copper;
}

CASH CASH::operator	- ( const CASH & cash_in )
{
	return CASH ( m_copper - cash_in.m_copper, m_silver - cash_in.m_silver, m_gold - cash_in.m_gold );
}

CASH CASH::operator	+ ( const CASH & cash_in )
{
	return CASH ( m_copper + cash_in.m_copper, m_silver + cash_in.m_silver, m_gold + cash_in.m_gold );
}

bool CASH::operator	== ( const CASH & cash_in )
{
	return m_gold == cash_in.m_gold && m_silver == cash_in.m_silver && m_copper == cash_in.m_copper;
}

bool CASH::operator > ( const CASH & cash_in )
{
	return m_gold + m_silver + m_copper > cash_in.m_gold + cash_in.m_silver + cash_in.m_copper;
}

bool CASH::operator < ( const CASH & cash_in )
{
	return m_gold + m_silver + m_copper < cash_in.m_gold + cash_in.m_silver + cash_in.m_copper;
}

void CASH::print()
{
	std::cout << "CASH PRINT - Gold: " << std::to_string( m_gold ) << " - Silver: " << std::to_string( m_silver ) << " - Copper: " << std::to_string( m_copper ) << std::endl;
}

uint8_t CASH::round_down_nearest_ten( uint8_t in )
{
	return in - in % 10;
}


