#pragma once
#include "typedefs.h"
#include "character_enums.h"

enum class DND_DICE : char
{
	D4,
	D6,
	D8,
	D10,
	D12,
	D20,
	PERCENTILE
};

u_int roll_dice( DND_DICE dice, u_int add_bonus_to_roll = 0, u_int number_of_rolls = 1 );

string get_string_from_DND_DICE( DND_DICE dice );
DND_DICE get_hit_dice_from_DND_CLASS( DND_CLASS dnd_class );
uint8_t get_max_roll_for_dice( DND_DICE dice );