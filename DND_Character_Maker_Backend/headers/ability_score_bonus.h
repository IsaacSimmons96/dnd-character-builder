#pragma once
#include "character_enums.h"
#include "typedefs.h"

class ABILITY_SCORE_BONUS
{
public:
	ABILITY_SCORE_BONUS( ABILITY_SCORE_TYPES type, uint16_t bonus_value );
	~ABILITY_SCORE_BONUS();

	uint16_t get_bonus_value()				{ return m_bonus_value; };
	ABILITY_SCORE_TYPES get_bonus_type()	{ return m_type; };

private:
	ABILITY_SCORE_TYPES m_type;
	uint16_t				m_bonus_value;
};
