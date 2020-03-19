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
	CASH();
	CASH( const CASH& cash_in );
	CASH( int64_t gold, int64_t silver, int64_t copper );
	CASH( money gold, money silver, money copper );

	money	get_copper() const { return m_copper; };
	money	get_silver() const { return m_silver; };
	money	get_gold()   const { return m_gold; };

	CASH  operator -  ( const CASH &cash_in );
	CASH  operator -  ( const CASH *cash_in );
	CASH  operator +  ( const CASH &cash_in );
	CASH  operator +  ( const CASH *cash_in );
	CASH& operator -= ( const CASH &cash_in );
	CASH& operator -= ( const CASH *cash_in );
	CASH& operator += ( const CASH &cash_in );
	CASH& operator += ( const CASH *cash_in );

	friend bool operator == ( const CASH &cash_in, const CASH & cash_comparison );
	friend bool operator >  ( const CASH &cash_in, const CASH & cash_comparison );
	friend bool operator >= ( const CASH &cash_in, const CASH & cash_comparison );
	friend bool operator <  ( const CASH &cash_in, const CASH & cash_comparison );
	friend bool operator <= ( const CASH &cash_in, const CASH & cash_comparison );

	void print() const;

private:
	int8_t round_down_nearest_ten( int8_t in );
	money convert_to_cash_type( const money& input, CASH_TYPE type ) const;

	money m_copper	{ CASH_TYPE::COPPER, 0};
	money m_silver	{ CASH_TYPE::SILVER, 0};
	money m_gold	{ CASH_TYPE::GOLD, 0};
};