#include "..\headers\dnd_character_utilities.h"
#include "..\headers\generic_utilities.h"

std::string DND_CHARACTER_UTILITIES::get_string_from_DND_CLASS( DND_CLASS dnd_class )
{
	std::string string_out;

	switch ( dnd_class )
	{
	case DND_CLASS::BARBARIAN:
		string_out = "BARBARIAN";
		break;
	case DND_CLASS::BARD:
		string_out = "BARD";
		break;
	case DND_CLASS::CLERIC:
		string_out = "CLERIC";
		break;
	case DND_CLASS::DRUID:
		string_out = "DRUID";
		break;
	case DND_CLASS::FIGHTER:
		string_out = "FIGHTER";
		break;
	case DND_CLASS::MONK:
		string_out = "MONK";
		break;
	case DND_CLASS::PALADIN:
		string_out = "PALADIN";
		break;
	case DND_CLASS::RANGER:
		string_out = "RANGER";
		break;
	case DND_CLASS::ROGUE:
		string_out = "ROGUE";
		break;
	case DND_CLASS::SORCERER:
		string_out = "SORCERER";
		break;
	case DND_CLASS::WARLOCK:
		string_out = "WARLOCK";
		break;
	case DND_CLASS::WIZARD:
		string_out = "WIZARD";
		break;
	case DND_CLASS::INVALID:
		string_out = "INVALID";
		break;
	}
	return string_out;
}

std::string DND_CHARACTER_UTILITIES::get_string_from_DND_BACKGROUND( DND_BACKGROUND dnd_background )
{
	std::string string_out;

	switch ( dnd_background )
	{
	case DND_BACKGROUND::PLACEHOLDER:
		string_out = "PLACEHOLDER";
		break;
	case DND_BACKGROUND::INVALID:
		string_out = "INVALID";
		break;
	}
	return string_out;
}

std::string DND_CHARACTER_UTILITIES::get_string_from_DND_RACE( DND_RACE dnd_race )
{
	std::string string_out;

	switch ( dnd_race )
	{
	case DND_RACE::HUMAN:
		string_out = "human";
		break;
	case DND_RACE::HILL_DWARF:
		string_out = "hill dwarf";
		break;
	case DND_RACE::DWARF:
		string_out = "dwarf";
		break;
	case DND_RACE::MOUNTAIN_DWARF:
		string_out = "mountain dwarf";
		break;
	case DND_RACE::HIGH_ELF:
		string_out = "high elf";
		break;
	case DND_RACE::WOOD_ELF:
		string_out = "wood elf";
		break;
	case DND_RACE::DROW_ELF:
		string_out = "drow elf";
		break;
	case DND_RACE::HALFLING:
		string_out = "halfling";
		break;
	case DND_RACE::DRAGONBORN:
		string_out = "dragonborn";
		break;
	case DND_RACE::GNOME:
		string_out = "gnome";
		break;
	case DND_RACE::HALF_ELF:
		string_out = "half elf";
		break;
	case DND_RACE::HALF_ORC:
		string_out = "half orc";
		break;
	case DND_RACE::TIEFLING:
		string_out = "tiefling";
		break;
	case DND_RACE::INVALID:
		string_out = "INVALID";
		break;
	}
	return string_out;
}

std::string DND_CHARACTER_UTILITIES::get_string_from_DND_ALIGNMENT( DND_ALIGNMENT dnd_alignment )
{
	std::string string_out;

	switch ( dnd_alignment )
	{
	case DND_ALIGNMENT::LAWFUL_GOOD:
		string_out = "LAWFUL_GOOD";
		break;
	case DND_ALIGNMENT::NEUTRAL_GOOD:
		string_out = "NEUTRAL_GOOD";
		break;
	case DND_ALIGNMENT::CHAOTIC_GOOD:
		string_out = "CHAOTIC_GOOD";
		break;
	case DND_ALIGNMENT::LAWFUL_NEUTRAL:
		string_out = "LAWFUL_NEUTRAL";
		break;
	case DND_ALIGNMENT::NEUTRAL:
		string_out = "NEUTRAL";
		break;
	case DND_ALIGNMENT::CHAOTIC_NEUTRAL:
		string_out = "CHAOTIC_NEUTRAL";
		break;
	case DND_ALIGNMENT::LAWFUL_EVIL:
		string_out = "LAWFUL_EVIL";
		break;
	case DND_ALIGNMENT::NEUTRAL_EVIL:
		string_out = "NEUTRAL_EVIL";
		break;
	case DND_ALIGNMENT::CHAOTIC_EVIL:
		string_out = "CHAOTIC_EVIL";
		break;
	case DND_ALIGNMENT::INVALID:
		string_out = "INVALID";
		break;
	}
	return string_out;
}

std::string DND_CHARACTER_UTILITIES::get_string_from_DND_LANGUAGE( DND_LANGUAGE dnd_lang )
{
	std::string string_out;

	switch ( dnd_lang )
	{
	case DND_LANGUAGE::COMMON:
		string_out = "Common";
		break;
	case DND_LANGUAGE::DWARVISH:
		string_out = "Dwarvish";
		break;
	case DND_LANGUAGE::ELVISH:
		string_out = "Elvish";
		break;
	case DND_LANGUAGE::GIANT:
		string_out = "Giant";
		break;
	case DND_LANGUAGE::GNOMISH:
		string_out = "Gnomish";
		break;
	case DND_LANGUAGE::GOBLIN:
		string_out = "Goblin";
		break;
	case DND_LANGUAGE::HALFLING:
		string_out = "Halfling";
		break;
	case DND_LANGUAGE::ORC:
		string_out = "Orc";
		break;
	case DND_LANGUAGE::ABYSSAL:
		string_out = "Abyssal";
		break;
	case DND_LANGUAGE::CELESTIAL:
		string_out = "Celestial";
		break;
	case DND_LANGUAGE::DEEP_SPEECH:
		string_out = "Deep speech";
		break;
	case DND_LANGUAGE::DRACONIC:
		string_out = "Draconic";
		break;
	case DND_LANGUAGE::INFERNAL:
		string_out = "Infernal";
		break;
	case DND_LANGUAGE::PRIMORDIAL:
		string_out = "Primordial";
		break;
	case DND_LANGUAGE::SYLVAN:
		string_out = "Sylvan";
		break;
	case DND_LANGUAGE::UNDERCOMMON:
		string_out = "Undercommon";
		break;
	case DND_LANGUAGE::INVALID:
		string_out = "Invalid";
		break;
	}
	return string_out;
}

string DND_CHARACTER_UTILITIES::get_string_from_DND_SIZE( DND_SIZE dnd_size )
{
	std::string string_out;

	switch ( dnd_size )
	{
	case DND_SIZE::SMALL:
		string_out = "Small";
		break;
	case DND_SIZE::MEDIUM:
		string_out = "Medium";
		break;
	case DND_SIZE::LARGE:
		string_out = "Large";
		break;
	case DND_SIZE::INVALID:
		string_out = "INVALID";
		break;
	}

	return string_out;
}

string DND_CHARACTER_UTILITIES::get_string_from_DND_TOOL( DND_TOOL dnd_tool )
{
	std::string string_out;

	switch ( dnd_tool )
	{
	case DND_TOOL::BREWERS_SUPPLIES:
		string_out = "Brewer's Supplies";
		break;
	case DND_TOOL::MASONS_TOOLS:
		string_out = "Mason's Tools";
		break;
	case DND_TOOL::SMITHS_TOOLS:
		string_out = "Smith's Tools";
		break;
	case DND_TOOL::INAVLID:
		string_out = "INVALID";
		break;
	}

	return string_out;
}

string DND_CHARACTER_UTILITIES::get_string_from_ABILITY_SCORE_TYPES( ABILITY_SCORE_TYPES ability_score )
{
	std::string string_out;

	switch ( ability_score )
	{
	case ABILITY_SCORE_TYPES::STRENGTH:
		string_out = "Strength";
		break;
	case ABILITY_SCORE_TYPES::DEXTERITY:
		string_out = "Dexterity";
		break;
	case ABILITY_SCORE_TYPES::CONSTITUTION:
		string_out = "Constitution";
		break;
	case ABILITY_SCORE_TYPES::INTELLIGENCE:
		string_out = "Intelligence";
		break;
	case ABILITY_SCORE_TYPES::WISDOM:
		string_out = "Wisdom";
		break;
	case ABILITY_SCORE_TYPES::CHARISMA:
		string_out = "Charisma";
		break;
	case ABILITY_SCORE_TYPES::INVALID:
		string_out = "INVALID";
		break;
	}

	return string_out;
}

string DND_CHARACTER_UTILITIES::get_string_from_DND_SKILL_TYPE( DND_SKILL_TYPE skill )
{
	std::string string_out;
	switch ( skill )
	{
	case ACROBATICS:
		string_out = "Acrobatics";
		break;
	case ANIMAL_HANDLING:
		string_out = "Animal Handling";
		break;
	case ARCANA:
		string_out = "Arcana";
		break;
	case ATHLETICS:
		string_out = "Athletics";
		break;
	case DECEPTION:
		string_out = "Deception";
		break;
	case HISTORY:
		string_out = "History";
		break;
	case INSIGHT:
		string_out = "Insight";
		break;
	case INTIMIDATION:
		string_out = "Intimidation";
		break;
	case INVESTIGATION:
		string_out = "Investigation";
		break;
	case MEDICINE:
		string_out = "Medicine";
		break;
	case NATURE:
		string_out = "Nature";
		break;
	case PERCEPTION:
		string_out = "Perception";
		break;
	case PERFORMANCE:
		string_out = "Performance";
		break;
	case PERSUASION:
		string_out = "Persuasion";
		break;
	case RELIGION:
		string_out = "Religion";
		break;
	case SLEIGHT_OF_HAND:
		string_out = "Sleight of Hand";
		break;
	case STEALTH:
		string_out = "Stealth";
		break;
	case SURVIVAL:
		string_out = "Survival";
		break;
	case INVALID:
		string_out = "INVALID";
		break;
	}
	return string_out;
}

DND_LANGUAGE DND_CHARACTER_UTILITIES::get_DND_LANGUAGE_from_string( string lang )
{
	if ( lang == get_string_from_DND_LANGUAGE( DND_LANGUAGE::COMMON ) )
	{
		return  DND_LANGUAGE::COMMON;
	}
	else if ( lang == get_string_from_DND_LANGUAGE( DND_LANGUAGE::DWARVISH ) )
	{
		return  DND_LANGUAGE::DWARVISH;
	}
	else if ( lang == get_string_from_DND_LANGUAGE( DND_LANGUAGE::ELVISH ) )
	{
		return  DND_LANGUAGE::ELVISH;
	}
	else if ( lang == get_string_from_DND_LANGUAGE( DND_LANGUAGE::GIANT ) )
	{
		return  DND_LANGUAGE::GIANT;
	}
	else if ( lang == get_string_from_DND_LANGUAGE( DND_LANGUAGE::GNOMISH ) )
	{
		return  DND_LANGUAGE::GNOMISH;
	}
	else if ( lang == get_string_from_DND_LANGUAGE( DND_LANGUAGE::GOBLIN ) )
	{
		return  DND_LANGUAGE::GOBLIN;
	}
	else if ( lang == get_string_from_DND_LANGUAGE( DND_LANGUAGE::HALFLING ) )
	{
		return  DND_LANGUAGE::HALFLING;
	}
	else if ( lang == get_string_from_DND_LANGUAGE( DND_LANGUAGE::ORC ) )
	{
		return  DND_LANGUAGE::ORC;
	}
	else if ( lang == get_string_from_DND_LANGUAGE( DND_LANGUAGE::ABYSSAL ) )
	{
		return  DND_LANGUAGE::ABYSSAL;
	}
	else if ( lang == get_string_from_DND_LANGUAGE( DND_LANGUAGE::CELESTIAL ) )
	{
		return  DND_LANGUAGE::CELESTIAL;
	}
	else if ( lang == get_string_from_DND_LANGUAGE( DND_LANGUAGE::DEEP_SPEECH ) )
	{
		return  DND_LANGUAGE::DEEP_SPEECH;
	}
	else if ( lang == get_string_from_DND_LANGUAGE( DND_LANGUAGE::DRACONIC ) )
	{
		return  DND_LANGUAGE::DRACONIC;
	}
	else if ( lang == get_string_from_DND_LANGUAGE( DND_LANGUAGE::INFERNAL ) )
	{
		return  DND_LANGUAGE::INFERNAL;
	}
	else if ( lang == get_string_from_DND_LANGUAGE( DND_LANGUAGE::PRIMORDIAL ) )
	{
		return  DND_LANGUAGE::PRIMORDIAL;
	}
	else if ( lang == get_string_from_DND_LANGUAGE( DND_LANGUAGE::SYLVAN ) )
	{
		return  DND_LANGUAGE::SYLVAN;
	}
	else if ( lang == get_string_from_DND_LANGUAGE( DND_LANGUAGE::UNDERCOMMON ) )
	{
		return  DND_LANGUAGE::UNDERCOMMON;
	}
	return  DND_LANGUAGE::INVALID;
}

DND_RACE DND_CHARACTER_UTILITIES::get_DND_RACE_from_string( string race )
{
	if ( race == get_string_from_DND_RACE( DND_RACE::HUMAN ) )
	{
		return  DND_RACE::HUMAN;
	}
	else if ( race == get_string_from_DND_RACE( DND_RACE::DRAGONBORN ) )
	{
		return  DND_RACE::DRAGONBORN;
	}
	else if ( race == get_string_from_DND_RACE( DND_RACE::DWARF ) )
	{
		return  DND_RACE::DWARF;
	}
	else if ( race == get_string_from_DND_RACE( DND_RACE::DROW_ELF ) )
	{
		return  DND_RACE::DROW_ELF;
	}
	else if ( race == get_string_from_DND_RACE( DND_RACE::GNOME ) )
	{
		return  DND_RACE::GNOME;
	}
	else if ( race == get_string_from_DND_RACE( DND_RACE::HALF_ELF ) )
	{
		return  DND_RACE::HALF_ELF;
	}
	else if ( race == get_string_from_DND_RACE( DND_RACE::HALF_ORC ) )
	{
		return  DND_RACE::HALF_ORC;
	}
	else if ( race == get_string_from_DND_RACE( DND_RACE::HALFLING ) )
	{
		return  DND_RACE::HALFLING;
	}
	else if ( race == get_string_from_DND_RACE( DND_RACE::HIGH_ELF ) )
	{
		return  DND_RACE::HIGH_ELF;
	}
	else if ( race == get_string_from_DND_RACE( DND_RACE::HILL_DWARF ) )
	{
		return  DND_RACE::HILL_DWARF;
	}
	else if ( race == get_string_from_DND_RACE( DND_RACE::MOUNTAIN_DWARF ) )
	{
		return  DND_RACE::MOUNTAIN_DWARF;
	}
	else if ( race == get_string_from_DND_RACE( DND_RACE::TIEFLING ) )
	{
		return  DND_RACE::TIEFLING;
	}
	else if ( race == get_string_from_DND_RACE( DND_RACE::WOOD_ELF ) )
	{
		return  DND_RACE::WOOD_ELF;
	}
	else if ( race == get_string_from_DND_RACE( DND_RACE::INVALID ) )
	{
		return  DND_RACE::INVALID;
	}
	return  DND_RACE::INVALID;
}

DND_ALIGNMENT DND_CHARACTER_UTILITIES::get_DND_ALIGNMENT_from_string( string dnd_alignment )
{
	DND_ALIGNMENT return_alignment = DND_ALIGNMENT::INVALID;

	if ( dnd_alignment == "chaotic evil" )
	{
		return_alignment = DND_ALIGNMENT::CHAOTIC_EVIL;
	}
	else if ( dnd_alignment == "chaotic good" )
	{
		return_alignment = DND_ALIGNMENT::CHAOTIC_GOOD;
	}
	else if ( dnd_alignment == "chaotic neutral" )
	{
		return_alignment = DND_ALIGNMENT::CHAOTIC_NEUTRAL;
	}
	else if ( dnd_alignment == "lawful evil" )
	{
		return_alignment = DND_ALIGNMENT::LAWFUL_EVIL;
	}
	else if ( dnd_alignment == "lawful good" )
	{
		return_alignment = DND_ALIGNMENT::LAWFUL_GOOD;
	}
	else if ( dnd_alignment == "lawful neutral" )
	{
		return_alignment = DND_ALIGNMENT::LAWFUL_NEUTRAL;
	}
	else if ( dnd_alignment == "neutral" )
	{
		return_alignment = DND_ALIGNMENT::NEUTRAL;
	}
	else if ( dnd_alignment == "neutral evil" )
	{
		return_alignment = DND_ALIGNMENT::NEUTRAL_EVIL;
	}
	else if ( dnd_alignment == "neutral good" )
	{
		return_alignment = DND_ALIGNMENT::NEUTRAL_GOOD;
	}
	return return_alignment;
}

DND_TOOL DND_CHARACTER_UTILITIES::get_DND_TOOL_from_string( string tool_prof )
{
	if ( tool_prof == "brewer's supplies" || tool_prof == "b" )
	{
		return  DND_TOOL::BREWERS_SUPPLIES;
	}
	else if ( tool_prof == "mason's tools" || tool_prof == "m" )
	{
		return  DND_TOOL::MASONS_TOOLS;
	}
	else if ( tool_prof == "smith's tools" || tool_prof == "s" )
	{
		return  DND_TOOL::SMITHS_TOOLS;
	}
	return  DND_TOOL::INAVLID;
}

DND_SIZE DND_CHARACTER_UTILITIES::get_DND_SIZE_from_string( string size_string )
{
	if ( size_string == "Small" )
	{
		return  DND_SIZE::SMALL;
	}
	else if ( size_string == "Medium" )
	{
		return  DND_SIZE::MEDIUM;
	}
	else if ( size_string == "Large" )
	{
		return  DND_SIZE::LARGE;
	}
	return  DND_SIZE::INVALID;
}

DND_SKILL_TYPE DND_CHARACTER_UTILITIES::get_DND_SKILL_from_string( string skill_string )
{
	for ( char i = 0; i < DND_SKILL_TYPE::INVALID; i++ )
	{
		const auto type = static_cast<DND_SKILL_TYPE>(i);
		string skill = get_string_from_DND_SKILL_TYPE( type );
		lower_string( skill );

		if ( skill_string == skill )
		{
			return type;
		}
	}
	return DND_SKILL_TYPE::INVALID;
}

DND_CLASS DND_CHARACTER_UTILITIES::get_DND_CLASS_from_string( string class_string )
{
	if ( class_string == "Barbarian" || class_string == "barbarian" )
	{
		return  DND_CLASS::BARBARIAN;
	}
	else if ( class_string == "Bard" || class_string == "bard" )
	{
		return  DND_CLASS::BARD;
	}
	else if ( class_string == "Cleric" || class_string == "cleric" )
	{
		return  DND_CLASS::CLERIC;
	}
	else if ( class_string == "Druid" || class_string == "druid" )
	{
		return  DND_CLASS::DRUID;
	}
	else if ( class_string == "Fighter" || class_string == "fighter" )
	{
		return  DND_CLASS::FIGHTER;
	}
	else if ( class_string == "Monk" || class_string == "monk" )
	{
		return  DND_CLASS::MONK;
	}
	else if ( class_string == "Paladin" || class_string == "paladin" )
	{
		return  DND_CLASS::PALADIN;
	}
	else if ( class_string == "Ranger" || class_string == "ranger" )
	{
		return  DND_CLASS::RANGER;
	}
	else if ( class_string == "Rogue" || class_string == "rogue" )
	{
		return  DND_CLASS::ROGUE;
	}
	else if ( class_string == "Sorcerer" || class_string == "sorcerer" )
	{
		return  DND_CLASS::SORCERER;
	}
	else if ( class_string == "Warlock" || class_string == "warlock" )
	{
		return  DND_CLASS::WARLOCK;
	}
	else if ( class_string == "Wizard" || class_string == "wizard" )
	{
		return  DND_CLASS::WIZARD;
	}
	return  DND_CLASS::INVALID;
}

ABILITY_SCORE_TYPES DND_CHARACTER_UTILITIES::get_ABILITY_SCORE_TYPE_from_string( string ability )
{
	if ( ability == "Strength" )
	{
		return  ABILITY_SCORE_TYPES::STRENGTH;
	}
	else if ( ability == "Dexterity" )
	{
		return  ABILITY_SCORE_TYPES::DEXTERITY;
	}
	else if ( ability == "Constitution" )
	{
		return  ABILITY_SCORE_TYPES::CONSTITUTION;
	}
	else if ( ability == "Intelligence" )
	{
		return  ABILITY_SCORE_TYPES::INTELLIGENCE;
	}
	else if ( ability == "Wisdom" )
	{
		return  ABILITY_SCORE_TYPES::WISDOM;
	}
	else if ( ability == "Charisma" )
	{
		return  ABILITY_SCORE_TYPES::CHARISMA;
	}
	return  ABILITY_SCORE_TYPES::INVALID;
}

ABILITY_SCORE_TYPES DND_CHARACTER_UTILITIES::get_ABILITY_SORE_TYPE_from_DND_SKILL_TYPE( DND_SKILL_TYPE skill )
{
	ABILITY_SCORE_TYPES ability = ABILITY_SCORE_TYPES::INVALID;
	switch ( skill )
	{
	case ACROBATICS:
	case SLEIGHT_OF_HAND:
	case STEALTH:
		ability = ABILITY_SCORE_TYPES::DEXTERITY;
		break;

	case ANIMAL_HANDLING:
	case INSIGHT:
	case MEDICINE:
	case PERCEPTION:
	case SURVIVAL:
		ability = ABILITY_SCORE_TYPES::WISDOM;
		break;

	case ARCANA:
	case HISTORY:
	case INVESTIGATION:
	case NATURE:
	case RELIGION:
		ability = ABILITY_SCORE_TYPES::INTELLIGENCE;
		break;

	case ATHLETICS:
		ability = ABILITY_SCORE_TYPES::STRENGTH;
		break;

	case DECEPTION:
	case INTIMIDATION:
	case PERFORMANCE:
	case PERSUASION:
		ability = ABILITY_SCORE_TYPES::CHARISMA;
		break;

	case INVALID:
		ability = ABILITY_SCORE_TYPES::INVALID;
		break;
	}
	return ability;
}

short int DND_CHARACTER_UTILITIES::get_ability_score_modifier( u_int ability_score )
{
	u_int modifier_value = -100;
	if ( ability_score == 1 )
	{
		modifier_value = -5;
	}
	else if ( ability_score > 1 && ability_score <= 3 )
	{
		modifier_value = -4;
	}
	else if ( ability_score > 3 && ability_score <= 5 )
	{
		modifier_value = -3;
	}
	else if ( ability_score > 5 && ability_score <= 7 )
	{
		modifier_value = -2;
	}
	else if ( ability_score > 7 && ability_score <= 9 )
	{
		modifier_value = -1;
	}
	else if ( ability_score > 9 && ability_score <= 11 )
	{
		modifier_value = 0;
	}
	else if ( ability_score > 11 && ability_score <= 13 )
	{
		modifier_value = 1;
	}
	else if ( ability_score > 13 && ability_score <= 15 )
	{
		modifier_value = 2;
	}
	else if ( ability_score > 15 && ability_score <= 17 )
	{
		modifier_value = 3;
	}
	else if ( ability_score > 17 && ability_score <= 19 )
	{
		modifier_value = 4;
	}
	else if ( ability_score > 19 && ability_score <= 21 )
	{
		modifier_value = 5;
	}
	else if ( ability_score > 21 && ability_score <= 23 )
	{
		modifier_value = 6;
	}
	else if ( ability_score > 23 && ability_score <= 25 )
	{
		modifier_value = 7;
	}
	else if ( ability_score > 25 && ability_score <= 27 )
	{
		modifier_value = 8;
	}
	else if ( ability_score > 27 && ability_score <= 29 )
	{
		modifier_value = 9;
	}
	else if ( ability_score >= 30 )
	{
		modifier_value = 10;
	}
	return modifier_value;
}