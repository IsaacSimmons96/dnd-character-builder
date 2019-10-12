#pragma once
#include "typedefs.h"
#include "spell_enums.h"

class SPELL_UTILITIES
{
public:
	static string get_string_from_SCHOOL_OF_MAGIC( SCHOOL_OF_MAGIC school_in );
	static string get_string_from_SPELL_CASTING_TIME( SPELL_CASTING_TIME casting_in );
	static string get_string_from_SPELL_COMPONENT( SPELL_COMPONENT comp_in );
	static string get_string_from_SPELL_DURATION( SPELL_DURATION duration_in );
	static string get_string_from_SPELL_DURATION_TIME( SPELL_DURATION_TIME time_in );

	static SPELL_CASTING_TIME get_casting_time_from_string( string string_in );
	static SPELL_COMPONENT get_spell_component_from_string( string string_in );
	static SPELL_DURATION get_duration_from_string( string string_in );
	static SPELL_DURATION_TIME get_duration_time_from_string( string string_in );
	static SCHOOL_OF_MAGIC get_school_of_magic_from_string( string string_in );
};
