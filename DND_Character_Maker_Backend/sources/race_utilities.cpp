#include "..\headers\race_utilities.h"

std::vector<DND_LANGUAGE> RACE_UTILITIES::get_languages_from_race( DND_RACE race )
{
	std::vector<DND_LANGUAGE> langs_out;

	switch ( race )
	{
	case DND_RACE::HUMAN:
		langs_out.push_back( DND_LANGUAGE::COMMON );
		break;
	case DND_RACE::HILL_DWARF:
		langs_out.push_back( DND_LANGUAGE::COMMON );
		break;
	case DND_RACE::DWARF:
		langs_out.push_back( DND_LANGUAGE::COMMON );
		langs_out.push_back( DND_LANGUAGE::DWARVISH );
		break;
	case DND_RACE::MOUNTAIN_DWARF:
		langs_out.push_back( DND_LANGUAGE::COMMON );
		break;
	case DND_RACE::HIGH_ELF:
		langs_out.push_back( DND_LANGUAGE::COMMON );
		break;
	case DND_RACE::WOOD_ELF:
		langs_out.push_back( DND_LANGUAGE::COMMON );
		break;
	case DND_RACE::DROW_ELF:
		langs_out.push_back( DND_LANGUAGE::COMMON );
		break;
	case DND_RACE::HALFLING:
		langs_out.push_back( DND_LANGUAGE::COMMON );
		break;
	case DND_RACE::DRAGONBORN:
		langs_out.push_back( DND_LANGUAGE::COMMON );
		break;
	case DND_RACE::GNOME:
		langs_out.push_back( DND_LANGUAGE::COMMON );
		break;
	case DND_RACE::HALF_ELF:
		langs_out.push_back( DND_LANGUAGE::COMMON );
		break;
	case DND_RACE::HALF_ORC:
		langs_out.push_back( DND_LANGUAGE::COMMON );
		break;
	case DND_RACE::TIEFLING:
		langs_out.push_back( DND_LANGUAGE::COMMON );
		break;
	case DND_RACE::INVALID:
		langs_out.push_back( DND_LANGUAGE::COMMON );
		break;
	}
	return langs_out;
}

std::vector<DND_TOOL_PROFICIENCY> RACE_UTILITIES::get_tool_profs_from_race( DND_RACE race )
{
	std::vector<DND_TOOL_PROFICIENCY> profs_out;

	switch ( race )
	{
	case DND_RACE::HUMAN:
		profs_out.push_back( DND_TOOL_PROFICIENCY::INAVLID );
		break;
	case DND_RACE::HILL_DWARF:
		profs_out.push_back( DND_TOOL_PROFICIENCY::INAVLID );
		break;
	case DND_RACE::DWARF:
		profs_out.push_back( DND_TOOL_PROFICIENCY::BREWERS_SUPPLIES );
		profs_out.push_back( DND_TOOL_PROFICIENCY::MASONS_TOOLS );
		profs_out.push_back( DND_TOOL_PROFICIENCY::SMITHS_TOOLS );
		break;
	case DND_RACE::MOUNTAIN_DWARF:
		profs_out.push_back( DND_TOOL_PROFICIENCY::INAVLID );
		break;
	case DND_RACE::HIGH_ELF:
		profs_out.push_back( DND_TOOL_PROFICIENCY::INAVLID );
		break;
	case DND_RACE::WOOD_ELF:
		profs_out.push_back( DND_TOOL_PROFICIENCY::INAVLID );
		break;
	case DND_RACE::DROW_ELF:
		profs_out.push_back( DND_TOOL_PROFICIENCY::INAVLID );
		break;
	case DND_RACE::HALFLING:
		profs_out.push_back( DND_TOOL_PROFICIENCY::INAVLID );
		break;
	case DND_RACE::DRAGONBORN:
		profs_out.push_back( DND_TOOL_PROFICIENCY::INAVLID );
		break;
	case DND_RACE::GNOME:
		profs_out.push_back( DND_TOOL_PROFICIENCY::INAVLID );
		break;
	case DND_RACE::HALF_ELF:
		profs_out.push_back( DND_TOOL_PROFICIENCY::INAVLID );
		break;
	case DND_RACE::HALF_ORC:
		profs_out.push_back( DND_TOOL_PROFICIENCY::INAVLID );
		break;
	case DND_RACE::TIEFLING:
		profs_out.push_back( DND_TOOL_PROFICIENCY::INAVLID );
		break;
	case DND_RACE::INVALID:
		profs_out.push_back( DND_TOOL_PROFICIENCY::INAVLID );
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