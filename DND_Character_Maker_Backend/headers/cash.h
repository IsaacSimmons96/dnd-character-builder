#pragma once

#include "typedefs.h"

class CASH
{
public:
	CASH( const CASH& cash_in );
	CASH( uint64_t gold, uint8_t silver, uint8_t copper );

	CASH operator - ( const CASH &cash_in );
	CASH operator + ( const CASH &cash_in );
	bool operator == ( const CASH &cash_in );
	bool operator > ( const CASH &cash_in );
	bool operator < ( const CASH &cash_in );

	void print();

private:
	uint8_t round_down_nearest_ten( uint8_t in );

	uint8_t m_copper	{ 0 };
	uint8_t m_silver	{ 0 };
	uint64_t m_gold		{ 0 };
	//double m_electrum	{ 0 };
	//double m_platinum	{ 0 };
};


// 1111 = 11 gold, 10 silver, 1 copper