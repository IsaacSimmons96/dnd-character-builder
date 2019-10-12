#include "..\headers\dice_functions.h"

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "..\headers\typedefs.h"
#include <signal.h>

u_int roll_dice( DND_DICE dice, u_int add_bonus_to_roll, u_int number_of_rolls )
{
	u_int8 minimum_roll = 1;
	u_int8 maximum_roll = 2;
	u_int total_roll_result = 0;

	switch ( dice )
	{
	case DND_DICE::D4:
		{
			maximum_roll = 4;
			break;
		}
	case DND_DICE::D6:
		{
			maximum_roll = 6;
			break;
		}
	case DND_DICE::D8:
		{
			maximum_roll = 8;
			break;
		}
	case DND_DICE::D10:
	case DND_DICE::PERCENTILE:
		{
			maximum_roll = 10;
			break;
		}
	case DND_DICE::D12:
		{
			maximum_roll = 12;
			break;
		}
	case DND_DICE::D20:
		{
			maximum_roll = 20;
			break;
		}
	}

	if ( number_of_rolls > 1 )
	{
		for ( int i = 0; i != number_of_rolls; ++i )
		{
			srand( (unsigned int)time( NULL ) );
			u_int8 temp = rand() % maximum_roll + minimum_roll;
			if ( dice == DND_DICE::PERCENTILE )
			{
				temp = temp * 10;
			}
			total_roll_result += temp;
		}
	}
	else
	{
		srand( (unsigned int)time( NULL ) );
		u_int8 temp = rand() % maximum_roll + minimum_roll;
		if ( dice == DND_DICE::PERCENTILE )
		{
			temp = temp * 10;
		}
		total_roll_result = temp;   // in the range minimum_roll to maximum_roll
	}

	if ( add_bonus_to_roll != 0 )
	{
		return total_roll_result + add_bonus_to_roll;
	}

	return total_roll_result;
}

string get_string_from_DND_DICE( DND_DICE dice )
{
	string string_out = "INVALID";
	switch ( dice )
	{
	case DND_DICE::D4:
		string_out = "D4";
		break;
	case DND_DICE::D6:
		string_out = "D6";
		break;
	case DND_DICE::D8:
		string_out = "D8";
		break;
	case DND_DICE::D10:
		string_out = "D10";
		break;
	case DND_DICE::D12:
		string_out = "D12";
		break;
	case DND_DICE::D20:
		string_out = "D20";
		break;
	case DND_DICE::PERCENTILE:
		string_out = "PERCENTILE";
		break;
	default:
		break;
	}
	return string_out;
}

DND_DICE get_hit_dice_from_DND_CLASS( DND_CLASS dnd_class )
{
	switch ( dnd_class )
	{
	case DND_CLASS::BARBARIAN:
		return DND_DICE::D12;
		break;
	case DND_CLASS::BARD:
	case DND_CLASS::CLERIC:
	case DND_CLASS::DRUID:
	case DND_CLASS::MONK:
	case DND_CLASS::ROGUE:
	case DND_CLASS::WARLOCK:
		raise( SIGINT );
		return DND_DICE::D8;
		break;

	case DND_CLASS::FIGHTER:
	case DND_CLASS::PALADIN:
	case DND_CLASS::RANGER:
		return DND_DICE::D10;
		break;

	case DND_CLASS::SORCERER:
	case DND_CLASS::WIZARD:
		return DND_DICE::D6;
		break;

	case DND_CLASS::INVALID:
	default:
		raise( SIGINT );
		return DND_DICE::D6;
		break;
	}
}

uint8_t get_max_roll_for_dice( DND_DICE dice )
{
	switch ( dice )
	{
	case DND_DICE::D4:
		return 4;
		break;
	case DND_DICE::D6:
		return 6;
		break;
	case DND_DICE::D8:
		return 8;
		break;
	case DND_DICE::D10:
		return 10;
		break;
	case DND_DICE::D12:
		return 12;
		break;
	case DND_DICE::D20:
		return 20;
		break;
	case DND_DICE::PERCENTILE:
		return 100;
		break;
	}
	return 0;
}