#include "..\headers\cash.h"

#include <iostream>
#include <cmath>


CASH::CASH( const CASH & cash_in )
{
	m_gold.second = cash_in.m_gold.second;
	m_silver.second = cash_in.m_silver.second;
	m_copper.second = cash_in.m_copper.second;
}

CASH::CASH( int64_t gold, int64_t silver, int64_t copper )
{
	m_gold.second = gold;
	m_silver.second = silver;
	m_copper.second = copper;
}

CASH::CASH( money gold, money silver, money copper )
{
	m_gold = gold;
	m_silver = silver;
	m_copper = copper;
}

CASH CASH::operator	- ( const CASH & cash_in )
{
	money new_copper( m_copper );
	money new_silver( m_silver );
	money new_gold( m_gold );

	new_copper.second += convert_to_cash_type( new_gold, CASH_TYPE::COPPER ).second + convert_to_cash_type( new_silver, CASH_TYPE::COPPER ).second;

	int64_t cash_as_copper = cash_in.m_copper.second + convert_to_cash_type( cash_in.m_gold, CASH_TYPE::COPPER ).second + convert_to_cash_type( cash_in.m_silver, CASH_TYPE::COPPER ).second;

	new_copper.second -= cash_as_copper;

	if ( new_copper.second > 0 )
	{
		new_silver = convert_to_cash_type( new_copper, CASH_TYPE::SILVER );
		new_copper.second = (int64_t)fmod( new_copper.second, 10 );

		new_gold = convert_to_cash_type( new_silver, CASH_TYPE::GOLD );
		new_silver.second = (int64_t)fmod( new_silver.second, 10 );
	}
	else
	{
		new_silver.second = 0;
		new_gold.second = 0;
	}
	return CASH( new_gold, new_silver, new_copper );
}

CASH& CASH::operator-=( const CASH & cash_in )
{
	return *this = *this - cash_in;
}


CASH CASH::operator	+ ( const CASH & cash_in )
{
	money new_copper( m_copper );
	money new_silver( m_silver );
	money new_gold( m_gold );

	new_copper.second += convert_to_cash_type( new_gold, CASH_TYPE::COPPER ).second + convert_to_cash_type( new_silver, CASH_TYPE::COPPER ).second;

	int64_t cash_as_copper = cash_in.m_copper.second + convert_to_cash_type( cash_in.m_gold, CASH_TYPE::COPPER ).second + convert_to_cash_type( cash_in.m_silver, CASH_TYPE::COPPER ).second;

	new_copper.second += cash_as_copper;

	if ( new_copper.second > 0 )
	{
		new_silver = convert_to_cash_type( new_copper, CASH_TYPE::SILVER );
		new_copper.second = (int64_t)fmod( new_copper.second, 10 );

		new_gold = convert_to_cash_type( new_silver, CASH_TYPE::GOLD );
		new_silver.second = (int64_t)fmod( new_silver.second, 10 );
	}
	else
	{
		new_silver.second = 0;
		new_gold.second = 0;
	}
	return CASH( new_gold, new_silver, new_copper );
}

CASH& CASH::operator=( const CASH & cash_in )
{
	m_gold.second = cash_in.m_gold.second;
	m_silver.second = cash_in.m_silver.second;
	m_copper.second = cash_in.m_copper.second;
	return *this;
}

CASH& CASH::operator+=( const CASH & cash_in )
{
	return *this = *this + cash_in;
}

bool CASH::operator	== ( const CASH & cash_in )
{
	return m_gold.second == cash_in.m_gold.second && m_silver.second == cash_in.m_silver.second && m_copper.second == cash_in.m_copper.second;
}

bool CASH::operator > ( const CASH & cash_in )
{
	return m_gold.second + m_silver.second + m_copper.second > cash_in.m_gold.second + cash_in.m_silver.second + cash_in.m_copper.second;
}

bool CASH::operator < ( const CASH & cash_in )
{
	return m_gold.second + m_silver.second + m_copper.second < cash_in.m_gold.second + cash_in.m_silver.second + cash_in.m_copper.second;
}

void CASH::print()
{
	std::cout << "CASH PRINT - Gold: " << std::to_string( m_gold.second ) << " - Silver: " << std::to_string( m_silver.second ) << " - Copper: " << std::to_string( m_copper.second ) << std::endl;
}

int8_t CASH::round_down_nearest_ten( int8_t in )
{
	return in - in % 10;
}

money CASH::convert_to_cash_type( const money& input, CASH_TYPE type ) const
{
	money return_money = input;
	switch ( type )
	{
	case CASH_TYPE::COPPER:
		{
			switch ( return_money.first )
			{
			case CASH_TYPE::COPPER:
				break;

			case CASH_TYPE::SILVER:
				{
					return_money.second = return_money.second * 10;
					break;
				}
			case CASH_TYPE::GOLD:
				{
					return_money.second = return_money.second * 100;
					break;
				}
			}

			return_money.first = CASH_TYPE::COPPER;
			break;
		}
	case CASH_TYPE::SILVER:
		{
			switch ( return_money.first )
			{
			case CASH_TYPE::COPPER:
				{
					return_money.second = return_money.second / 10;
					break;
				}
			case CASH_TYPE::SILVER:
				break;
			case CASH_TYPE::GOLD:
				{
					return_money.second = return_money.second * 10;
					break;
				}
			}

			return_money.first = CASH_TYPE::SILVER;
			break;
		}
	case CASH_TYPE::GOLD:
		{
			switch ( return_money.first )
			{
			case CASH_TYPE::COPPER:
				return_money.second = return_money.second / 100;
				break;
			case CASH_TYPE::SILVER:
				return_money.second = return_money.second / 10;
				break;
			case CASH_TYPE::GOLD:
				break;
			}

			return_money.first = CASH_TYPE::GOLD;
			break;
		}
	}
	return return_money;
}


