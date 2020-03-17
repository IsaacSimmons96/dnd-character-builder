#pragma once

#include "typedefs.h"


enum class CASH_TYPE : uint8_t
{
	COPPER,
	SILVER,
	GOLD
};

typedef std::pair< CASH_TYPE, int64_t > money;

class CASH
{
public:
	CASH( const CASH& cash_in );
	CASH( int64_t gold, int64_t silver, int64_t copper );
	CASH( money gold, money silver, money copper );

	CASH operator - ( const CASH &cash_in );
	CASH& operator -= ( const CASH &cash_in );
	CASH operator + ( const CASH &cash_in );
	CASH& operator += ( const CASH &cash_in );
	bool operator == ( const CASH &cash_in );
	bool operator > ( const CASH &cash_in );
	bool operator < ( const CASH &cash_in );

	void print();

private:
	int8_t round_down_nearest_ten( int8_t in );
	money convert_to_cash_type( const money& input, CASH_TYPE type ) const;

	money m_copper	{ CASH_TYPE::COPPER, 0};
	money m_silver	{ CASH_TYPE::SILVER, 0};
	money m_gold	{ CASH_TYPE::GOLD, 0};
	//uint64_t m_copper.second	{ 0 };
	//uint64_t m_silver.second	{ 0 };
	//uint64_t m_gold.second	{ 0 };
	//double m_electrum	{ 0 };
	//double m_platinum	{ 0 };
};


// 1111 = 11 gold, 10 silver, 1 copper

