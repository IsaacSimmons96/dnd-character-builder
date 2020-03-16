#include "..\headers\ability_score_bonus.h"

ABILITY_SCORE_BONUS::ABILITY_SCORE_BONUS( ABILITY_SCORE_TYPES type, uint16_t bonus_value )
{
	m_type = type;
	m_bonus_value = bonus_value;
}

ABILITY_SCORE_BONUS::~ABILITY_SCORE_BONUS()
{
}