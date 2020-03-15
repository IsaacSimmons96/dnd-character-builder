#include "..\headers\race_utilities.h"

std::vector<DND_LANGUAGE> RACE_UTILITIES::get_languages_from_race( DND_RACE race )
{
	std::vector<DND_LANGUAGE> langs_out;

	switch ( race )
	{
	case DND_RACE::HUMAN:
		langs_out.push_back( DND_LANGUAGE::COMMON );
		break;
	case DND_RACE::DWARF:
		langs_out.push_back( DND_LANGUAGE::COMMON );
		langs_out.push_back( DND_LANGUAGE::DWARVISH );
		break;
	case DND_RACE::ELF:
	case DND_RACE::HIGH_ELF:
		langs_out.push_back( DND_LANGUAGE::COMMON );
		langs_out.push_back( DND_LANGUAGE::ELVISH );
		break;
	case DND_RACE::HALFLING:
		langs_out.push_back( DND_LANGUAGE::COMMON );
		langs_out.push_back( DND_LANGUAGE::HALFLING );
		break;
	case DND_RACE::DRAGONBORN:
		langs_out.push_back( DND_LANGUAGE::COMMON );
		langs_out.push_back( DND_LANGUAGE::DRACONIC );
		break;
	case DND_RACE::GNOME:
		langs_out.push_back( DND_LANGUAGE::COMMON );
		langs_out.push_back( DND_LANGUAGE::GNOMISH );
		break;
	case DND_RACE::HALF_ORC:
		langs_out.push_back( DND_LANGUAGE::COMMON );
		langs_out.push_back( DND_LANGUAGE::ORC );
		break;
	case DND_RACE::TIEFLING:
		langs_out.push_back( DND_LANGUAGE::COMMON );
		langs_out.push_back( DND_LANGUAGE::INFERNAL );
		break;
	default:
		break;
	}
	return langs_out;
}

std::vector<DND_TOOL> RACE_UTILITIES::get_tool_profs_from_race( DND_RACE race )
{
	std::vector<DND_TOOL> profs_out;

	switch ( race )
	{
	case DND_RACE::MOUNTAIN_DWARF:
	case DND_RACE::HILL_DWARF:
	case DND_RACE::DWARF:
		profs_out.push_back( DND_TOOL::BREWERS_SUPPLIES );
		profs_out.push_back( DND_TOOL::MASONS_TOOLS );
		profs_out.push_back( DND_TOOL::SMITHS_TOOLS );
		break;

	case DND_RACE::ROCK_GNOME:
		profs_out.push_back( DND_TOOL::TINKERS_TOOLS );
		break;

	default:
		profs_out.push_back( DND_TOOL::INVALID );
		break;
	}
	return profs_out;
}

RACE_UTILITIES::RACE_UTILITIES()
{
}

RACE_UTILITIES::~RACE_UTILITIES()
{
}