#pragma once
#include "character_enums.h"
#include "typedefs.h"


class DND_CHARACTER_UTILITIES
{
public:
	static string get_string_from_DND_CLASS( DND_CLASS dnd_class );
	static string get_string_from_DND_BACKGROUND( DND_BACKGROUND dnd_background );
	static string get_string_from_DND_RACE( DND_RACE dnd_race );
	static string get_string_from_DND_ALIGNMENT( DND_ALIGNMENT dnd_alignment );
	static string get_string_from_DND_LANGUAGE( DND_LANGUAGE dnd_lang );
	static string get_string_from_DND_SIZE( DND_SIZE dnd_size );
	static string get_string_from_DND_TOOL_PROFICIENCY( DND_TOOL_PROFICIENCY dnd_tool );
	static string get_string_from_ABILITY_SCORE_TYPES( ABILITY_SCORE_TYPES ability_score );
	static string get_string_from_DND_SKILL_TYPE( DND_SKILL_TYPE skill );

	static DND_LANGUAGE get_DND_LANGUAGE_from_string( string lang );
	static DND_ALIGNMENT get_DND_ALIGNMENT_from_string( string dnd_alignment );
	static DND_RACE get_DND_RACE_from_string( string race );
	static DND_TOOL_PROFICIENCY get_DND_TOOL_PROFICIENCY_from_string( string tool_prof );
	static DND_SIZE get_DND_SIZE_from_string( string size_string );
	static DND_CLASS get_DND_CLASS_from_string( string class_string );
	static ABILITY_SCORE_TYPES get_ABILITY_SCORE_TYPE_from_string( string ability );

	static ABILITY_SCORE_TYPES get_ABILITY_SORE_TYPE_from_DND_SKILL_TYPE( DND_SKILL_TYPE skill );

	static short int get_ability_score_modifier( u_int ability_score );
};