#pragma once
#include "typedefs.h"
#include "combat_and_item_enums.h"

class ITEM_AND_COMBAT_UTILITIES
{
public:
	static string get_string_from_DAMAGE_TYPE( DAMAGE_TYPE type_in );
	static string get_string_from_WEAPON_PROPERTIES( WEAPON_PROPERTIES type_in );
	static string get_string_from_WEAPON_PROFICIENCY( WEAPON_PROFICIENCY type_in );
	static string get_string_from_WEAPON_TYPE( DAMAGE_TYPE type_in );
	static string get_string_from_ARMOR_CATEGORY( ARMOR_CATEGORY type_in );

	static DAMAGE_TYPE get_DAMAGE_TYPE_from_string( string string_in );
	static WEAPON_PROPERTIES get_WEAPON_PROPERTIES_from_string( string string_in );
	static WEAPON_PROFICIENCY get_WEAPON_PROFICIENCY_from_string( string string_in );
	static WEAPON_TYPE get_WEAPON_TYPE_from_string( string string_in );
	static ARMOR_CATEGORY get_ARMOR_CATEGORY_from_string( string string_in );
};

