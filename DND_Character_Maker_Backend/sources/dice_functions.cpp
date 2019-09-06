#include "C:\Users\Isaac\source\repos\DND_Character_Maker_Backend\DND_Character_Maker_Backend\headers\dice_functions.h"

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "..\headers\typedefs.h"

u_int roll_dice( DND_DICE dice, u_int add_bonus_to_roll, u_int number_of_rolls )
{
	u_int8 minimum_roll = 1;
	u_int8 maximum_roll	= 2;
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

	if (number_of_rolls > 1)
	{
		for (int i = 0; i != number_of_rolls; ++i)
		{
			srand( (unsigned int)time( NULL ) );
			u_int8 temp = rand() % maximum_roll + minimum_roll;
			if (dice == DND_DICE::PERCENTILE)
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
		if (dice == DND_DICE::PERCENTILE)
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
