#include "..\headers\spell_utilities.h"
#include "..\headers\spell_enums.h"

SPELL_CASTING_TIME SPELL_UTILITIES::get_casting_time_from_string( string string_in )
{
	if ( string_in == "Action" || string_in == "action" || string_in == "1 action" )
	{
		return SPELL_CASTING_TIME::ACTION;
	}
	else if ( string_in == "Bonus" || string_in == "bonus" )
	{
		return SPELL_CASTING_TIME::BONUS_ACTION;
	}
	else if ( string_in == "one minute" || string_in == "One Minute" )
	{
		return SPELL_CASTING_TIME::ONE_MINUTE;
	}
	else if ( string_in == "Reaction" || string_in == "reaction" )
	{
		return SPELL_CASTING_TIME::REACTION;
	}
	else if ( string_in == "ten minutes" || string_in == "Ten Minutes" )
	{
		return SPELL_CASTING_TIME::TEN_MINUTES;
	}
	else
	{
		return SPELL_CASTING_TIME::INVALID;
	}
}

SPELL_DURATION_TIME SPELL_UTILITIES::get_duration_time_from_string( string string_in )
{
	if ( string_in == "one minute" || string_in == "One Minute" || string_in == "1 min" )
	{
		return SPELL_DURATION_TIME::ONE_MINUTE;
	}
	else if ( string_in == "One Hour" || string_in == "one hour" || string_in == "1 hour" )
	{
		return SPELL_DURATION_TIME::ONE_HOUR;
	}
	else if ( string_in == "ten minutes" || string_in == "Ten Minutes" || string_in == "10 mins" )
	{
		return SPELL_DURATION_TIME::TEN_MINUTES;
	}
	else
	{
		return SPELL_DURATION_TIME::INVALID;
	}
}



SPELL_COMPONENT SPELL_UTILITIES::get_spell_component_from_string( string string_in )
{

	if ( string_in == "V" || string_in == "v" )
	{
		return SPELL_COMPONENT::VERBAL;
	}
	else if ( string_in == "M" || string_in == "m" )
	{
		return SPELL_COMPONENT::MATERIAL;
	}
	else if ( string_in == "S" || string_in == "s" )
	{
		return SPELL_COMPONENT::SOMATIC;
	}
	else if ( string_in == "V M" || string_in == "v m" )
	{
		return SPELL_COMPONENT::VERBAL_MATERIAL;
	}
	else if ( string_in == "V S" || string_in == "v s" )
	{
		return SPELL_COMPONENT::VERBAL_SOMATIC;
	}
	else if ( string_in == "V S M" || string_in == "v s m" )
	{
		return SPELL_COMPONENT::VERBAL_SOMATIC_MATERIAL;
	}
	else if ( string_in == "S M" || string_in == "s m" )
	{
		return SPELL_COMPONENT::SOMATIC_MATERIAL;
	}
	else
	{
		return SPELL_COMPONENT::INVALID;
	}
}

SPELL_DURATION SPELL_UTILITIES::get_duration_from_string( string string_in )
{
	if ( string_in == "Concentration" || string_in == "concentration" )
	{
		return SPELL_DURATION::CONCENTRATION;
	}
	else if ( string_in == "Concentration_Up_To" || string_in == "concentration_up_to" || string_in == "con_up_to" )
	{
		return SPELL_DURATION::CONCENTRATION_UP_TO_TIME;
	}
	else if ( string_in == "Days" || string_in == "days" )
	{
		return SPELL_DURATION::DAYS;
	}
	else if ( string_in == "Instantaneous" || string_in == "instantaneous" || string_in == "instant" || string_in == "Instant" )
	{
		return SPELL_DURATION::INSTANT;
	}
	else if ( string_in == "Time" || string_in == "time" )
	{
		return SPELL_DURATION::TIME;
	}
	else if ( string_in == "Dispelled" || string_in == "dispelled" )
	{
		return SPELL_DURATION::UNTIL_DISPELLED;
	}
	else
	{
		return SPELL_DURATION::INVALID;
	}
}

SCHOOL_OF_MAGIC SPELL_UTILITIES::get_school_of_magic_from_string( string string_in )
{
	if ( string_in == "Abjuration" || string_in == "abjuration" )
	{
		return SCHOOL_OF_MAGIC::ABJURATION;
	}
	if ( string_in == "Conjuration" || string_in == "conjuration" )
	{
		return SCHOOL_OF_MAGIC::CONJURATION;
	}
	if ( string_in == "Divination" || string_in == "divination" )
	{
		return SCHOOL_OF_MAGIC::DIVINATION;
	}
	if ( string_in == "Enchantment" || string_in == "enchantment" )
	{
		return SCHOOL_OF_MAGIC::ENCHANTMENT;
	}
	if ( string_in == "Evocation" || string_in == "evocation" )
	{
		return SCHOOL_OF_MAGIC::EVOCATION;
	}
	if ( string_in == "Illusion" || string_in == "illusion" )
	{
		return SCHOOL_OF_MAGIC::ILLUSION;
	}
	if ( string_in == "Necromancy" || string_in == "necromancy" )
	{
		return SCHOOL_OF_MAGIC::NECROMANCY;
	}
	if ( string_in == "Transmutation" || string_in == "transmutation" )
	{
		return SCHOOL_OF_MAGIC::TRANSMUTATION;
	}
	else
	{
		return SCHOOL_OF_MAGIC::INVALID;
	}
}

string SPELL_UTILITIES::get_string_from_SCHOOL_OF_MAGIC( SCHOOL_OF_MAGIC school_in )
{
	string return_string;
	switch ( school_in )
	{
	case SCHOOL_OF_MAGIC::ABJURATION:
		return_string = "Abjuration";
		break;
	case SCHOOL_OF_MAGIC::CONJURATION:
		return_string = "Conjuration";
		break;
	case SCHOOL_OF_MAGIC::DIVINATION:
		return_string = "Divination";
		break;
	case SCHOOL_OF_MAGIC::ENCHANTMENT:
		return_string = "Enchantment";
		break;
	case SCHOOL_OF_MAGIC::EVOCATION:
		return_string = "Evocation";
		break;
	case SCHOOL_OF_MAGIC::ILLUSION:
		return_string = "Illusion";
		break;
	case SCHOOL_OF_MAGIC::NECROMANCY:
		return_string = "Necromancy";
		break;
	case SCHOOL_OF_MAGIC::TRANSMUTATION:
		return_string = "Transmutation";
		break;
	default:
		return_string = "INVALID";
		break;
	}
	return return_string;
}

string SPELL_UTILITIES::get_string_from_SPELL_CASTING_TIME( SPELL_CASTING_TIME casting_in )
{
	string return_string;
	switch ( casting_in )
	{
	case SPELL_CASTING_TIME::ONE_MINUTE:
		return_string = "1 Minute";
		break;
	case SPELL_CASTING_TIME::TEN_MINUTES:
		return_string = "10 Minutes";
		break;
	case SPELL_CASTING_TIME::REACTION:
		return_string = "Reaction";
		break;
	case SPELL_CASTING_TIME::ACTION:
		return_string = "Action";
		break;
	case SPELL_CASTING_TIME::BONUS_ACTION:
		return_string = "Bonus Action";
		break;
	default:
		return_string = "INVALID";
		break;
	}
	return return_string;
}

string SPELL_UTILITIES::get_string_from_SPELL_COMPONENT( SPELL_COMPONENT comp_in )
{
	string return_string;
	switch ( comp_in )
	{
	case SPELL_COMPONENT::VERBAL:
		return_string = "V";
		break;
	case SPELL_COMPONENT::VERBAL_SOMATIC:
		return_string = "V, S";
		break;
	case SPELL_COMPONENT::VERBAL_MATERIAL:
		return_string = "V, M";
		break;
	case SPELL_COMPONENT::VERBAL_SOMATIC_MATERIAL:
		return_string = "V, S, M";
		break;
	case SPELL_COMPONENT::SOMATIC:
		return_string = "S";
		break;
	case SPELL_COMPONENT::SOMATIC_MATERIAL:
		return_string = "S, M";
		break;
	case SPELL_COMPONENT::MATERIAL:
		return_string = "M";
		break;
	default:
		return_string = "INVALID";
		break;
	}
	return return_string;
}

string SPELL_UTILITIES::get_string_from_SPELL_DURATION( SPELL_DURATION duration_in )
{
	string return_string;
	switch ( duration_in )
	{
	case SPELL_DURATION::INSTANT:
		return_string = "Instantaneous";
		break;
	case SPELL_DURATION::CONCENTRATION:
		return_string = "Concentration";
		break;
	case SPELL_DURATION::CONCENTRATION_UP_TO_TIME:
		return_string = "Concentration, up to ";
		break;
	case SPELL_DURATION::UNTIL_DISPELLED:
		return_string = "Until Dispelled";
		break;
	case SPELL_DURATION::TIME:
	case SPELL_DURATION::DAYS:
		return_string = "";
		break;
	default:
		return_string = "INVALID";
		break;
	}
	return return_string;
}

string SPELL_UTILITIES::get_string_from_SPELL_DURATION_TIME( SPELL_DURATION_TIME time_in )
{
	string return_string;
	switch ( time_in )
	{
	case SPELL_DURATION_TIME::ONE_MINUTE:
		return_string = "1 Minute";
		break;
	case SPELL_DURATION_TIME::TEN_MINUTES:
		return_string = "10 Minutes";
		break;
	case SPELL_DURATION_TIME::ONE_HOUR:
		return_string = "1 Hour";
		break;
	default:
		return_string = "";
		break;
	}
	return return_string;
}
