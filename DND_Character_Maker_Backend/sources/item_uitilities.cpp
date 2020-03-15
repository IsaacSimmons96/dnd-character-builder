#include "..\headers\item_utilities.h"
#include "..\headers\typedefs.h"

string ITEM_AND_COMBAT_UTILITIES::get_string_from_DAMAGE_TYPE( DAMAGE_TYPE type_in )
{
	string return_string;

	switch ( type_in )
	{
	case DAMAGE_TYPE::ACID:
		return_string = "Acid";
		break;
	case DAMAGE_TYPE::BLUDGEONING:
		return_string = "Bludgeoning";
		break;
	case DAMAGE_TYPE::COLD:
		return_string = "Cold";
		break;
	case DAMAGE_TYPE::FIRE:
		return_string = "Fire";
		break;
	case DAMAGE_TYPE::FORCE:
		return_string = "Force";
		break;
	case DAMAGE_TYPE::LIGHTNING:
		return_string = "Lightning";
		break;
	case DAMAGE_TYPE::NECROTIC:
		return_string = "Necrotic";
		break;
	case DAMAGE_TYPE::PIERCING:
		return_string = "Piercing";
		break;
	case DAMAGE_TYPE::POISON:
		return_string = "Poison";
		break;
	case DAMAGE_TYPE::PSYCHIC:
		return_string = "Psychic";
		break;
	case DAMAGE_TYPE::RADIANT:
		return_string = "Radiant";
		break;
	case DAMAGE_TYPE::SLASHING:
		return_string = "Slashing";
		break;
	case DAMAGE_TYPE::THUNDER:
		return_string = "Thunder";
		break;
	default:
		return_string = "INVALID";
		break;
	}
	return return_string;
}

DAMAGE_TYPE ITEM_AND_COMBAT_UTILITIES::get_DAMAGE_TYPE_from_string( string string_in )
{
	DAMAGE_TYPE return_type;

	if ( string_in == "acid" )
	{
		return_type = DAMAGE_TYPE::ACID;
	}
	else if ( string_in == "bludgeoning" )
	{
		return_type = DAMAGE_TYPE::BLUDGEONING;
	}
	else if ( string_in == "cold" )
	{
		return_type = DAMAGE_TYPE::COLD;
	}
	else if ( string_in == "fire" )
	{
		return_type = DAMAGE_TYPE::FIRE;
	}
	else if ( string_in == "force" )
	{
		return_type = DAMAGE_TYPE::FORCE;
	}
	else if ( string_in == "lightning" )
	{
		return_type = DAMAGE_TYPE::LIGHTNING;
	}
	else if ( string_in == "necrotic" )
	{
		return_type = DAMAGE_TYPE::NECROTIC;
	}
	else if ( string_in == "piercing" )
	{
		return_type = DAMAGE_TYPE::PIERCING;
	}
	else if ( string_in == "poison" )
	{
		return_type = DAMAGE_TYPE::POISON;
	}
	else if ( string_in == "psychic" )
	{
		return_type = DAMAGE_TYPE::PSYCHIC;
	}
	else if ( string_in == "radiant" )
	{
		return_type = DAMAGE_TYPE::RADIANT;
	}
	else if ( string_in == "slashing" )
	{
		return_type = DAMAGE_TYPE::SLASHING;
	}
	else if ( string_in == "thunder" )
	{
		return_type = DAMAGE_TYPE::THUNDER;
	}
	else
	{
		return_type = DAMAGE_TYPE::INVALID;
	}
	return return_type;
}

string ITEM_AND_COMBAT_UTILITIES::get_string_from_WEAPON_PROPERTIES( WEAPON_PROPERTIES type_in )
{
	string return_string;
	switch ( type_in )
	{
	case WEAPON_PROPERTIES::AMMUNITION:
		return_string = "Ammunition";
		break;
	case WEAPON_PROPERTIES::FINESSE:
		return_string = "Finesse";
		break;
	case WEAPON_PROPERTIES::HEAVY:
		return_string = "Heavy";
		break;
	case WEAPON_PROPERTIES::LIGHT:
		return_string = "Light";
		break;
	case WEAPON_PROPERTIES::LOADING:
		return_string = "Loading";
		break;
	case WEAPON_PROPERTIES::RANGE:
		return_string = "Range";
		break;
	case WEAPON_PROPERTIES::REACH:
		return_string = "Reach";
		break;
	case WEAPON_PROPERTIES::SPECIAL:
		return_string = "Special";
		break;
	case WEAPON_PROPERTIES::THROWN:
		return_string = "Thrown";
		break;
	case WEAPON_PROPERTIES::TWO_HANDED:
		return_string = "Two Handed";
		break;
	case WEAPON_PROPERTIES::VERSATILE:
		return_string = "Versatile";
		break;
	case WEAPON_PROPERTIES::IMPROVISED_WEAPON:
		return_string = "Improvised Weapon";
		break;
	default:
		return_string = "INVALID";
		break;
	}
	return return_string;
}

WEAPON_PROPERTIES ITEM_AND_COMBAT_UTILITIES::get_WEAPON_PROPERTIES_from_string( string string_in )
{
	WEAPON_PROPERTIES return_type;

	if ( string_in == "ammunition" )
	{
		return_type = WEAPON_PROPERTIES::AMMUNITION;
	}
	else if ( string_in == "finesse" )
	{
		return_type = WEAPON_PROPERTIES::FINESSE;
	}
	else if ( string_in == "heavy" )
	{
		return_type = WEAPON_PROPERTIES::HEAVY;
	}
	else if ( string_in == "improvised" )
	{
		return_type = WEAPON_PROPERTIES::IMPROVISED_WEAPON;
	}
	else if ( string_in == "light" )
	{
		return_type = WEAPON_PROPERTIES::LIGHT;
	}
	else if ( string_in == "loading" )
	{
		return_type = WEAPON_PROPERTIES::LOADING;
	}
	else if ( string_in == "range" )
	{
		return_type = WEAPON_PROPERTIES::RANGE;
	}
	else if ( string_in == "reach" )
	{
		return_type = WEAPON_PROPERTIES::REACH;
	}
	else if ( string_in == "special" )
	{
		return_type = WEAPON_PROPERTIES::SPECIAL;
	}
	else if ( string_in == "thrown" )
	{
		return_type = WEAPON_PROPERTIES::THROWN;
	}
	else if ( string_in == "two handed" )
	{
		return_type = WEAPON_PROPERTIES::TWO_HANDED;
	}
	else if ( string_in == "versatile" )
	{
		return_type = WEAPON_PROPERTIES::VERSATILE;
	}
	else
	{
		return_type = WEAPON_PROPERTIES::INVALID;
	}
	return return_type;
}

string ITEM_AND_COMBAT_UTILITIES::get_string_from_WEAPON_PROFICIENCY( WEAPON_PROFICIENCY type_in )
{
	string return_string;

	switch ( type_in )
	{
	case WEAPON_PROFICIENCY::SIMPLE:
		return_string = "Simple Weapons";
		break;
	case WEAPON_PROFICIENCY::MARTIAL:
		return_string = "Martial Weapons";
		break;
	default:
		return_string = "INVALID";
		break;
	}

	return return_string;
}

WEAPON_PROFICIENCY ITEM_AND_COMBAT_UTILITIES::get_WEAPON_PROFICIENCY_from_string( string string_in )
{
	WEAPON_PROFICIENCY return_prof;

	if ( string_in == "simple" )
	{
		return_prof = WEAPON_PROFICIENCY::SIMPLE;
	}
	else if ( string_in == "martial" )
	{
		return_prof = WEAPON_PROFICIENCY::MARTIAL;
	}
	else
	{
		return_prof = WEAPON_PROFICIENCY::INVALID;
	}
	return return_prof;
}

ARMOR_CATEGORY ITEM_AND_COMBAT_UTILITIES::get_ARMOR_CATEGORY_from_string( string string_in )
{
	ARMOR_CATEGORY return_cat;

	if ( string_in == "heavy" )
	{
		return_cat = ARMOR_CATEGORY::HEAVY;
	}
	else if ( string_in == "light" )
	{
		return_cat = ARMOR_CATEGORY::LIGHT;
	}
	else if ( string_in == "medium" )
	{
		return_cat = ARMOR_CATEGORY::MEDIUM;
	}
	else if ( string_in == "shield" )
	{
		return_cat = ARMOR_CATEGORY::SHIELD;
	}
	else
	{
		return_cat = ARMOR_CATEGORY::INVALID;
	}
	return return_cat;
}

std::vector<WEAPON_PROFICIENCY> ITEM_AND_COMBAT_UTILITIES::get_general_weapon_profs_from_class( DND_CLASS dnd_class )
{
	std::vector<WEAPON_PROFICIENCY> return_vector;
	switch ( dnd_class )
	{
	case DND_CLASS::BARBARIAN:
	case DND_CLASS::FIGHTER:
	case DND_CLASS::PALADIN:
	case DND_CLASS::RANGER:
		return_vector = std::vector<WEAPON_PROFICIENCY>{ WEAPON_PROFICIENCY::SIMPLE, WEAPON_PROFICIENCY::MARTIAL };
		break;
	case DND_CLASS::BARD:
	case DND_CLASS::CLERIC:
	case DND_CLASS::MONK:
	case DND_CLASS::ROGUE:
	case DND_CLASS::WARLOCK:
		return_vector = std::vector<WEAPON_PROFICIENCY>{ WEAPON_PROFICIENCY::SIMPLE };
		break;
	default:
		break;
	}
	return return_vector;
}

std::vector<ARMOR_CATEGORY> ITEM_AND_COMBAT_UTILITIES::get_armor_profs_from_class( DND_CLASS dnd_class )
{
	std::vector<ARMOR_CATEGORY> return_vector;
	switch ( dnd_class )
	{
	case DND_CLASS::BARBARIAN:
	case DND_CLASS::CLERIC:
	case DND_CLASS::DRUID:
	case DND_CLASS::RANGER:
		return_vector = std::vector<ARMOR_CATEGORY>{ ARMOR_CATEGORY::LIGHT, ARMOR_CATEGORY::MEDIUM, ARMOR_CATEGORY::SHIELD };
		break;
	case DND_CLASS::BARD:
	case DND_CLASS::ROGUE:
	case DND_CLASS::WARLOCK:
		return_vector = std::vector<ARMOR_CATEGORY>{ ARMOR_CATEGORY::LIGHT };
		break;
	case DND_CLASS::FIGHTER:
	case DND_CLASS::PALADIN:
		return_vector = std::vector<ARMOR_CATEGORY>{ ARMOR_CATEGORY::LIGHT, ARMOR_CATEGORY::MEDIUM, ARMOR_CATEGORY::HEAVY, ARMOR_CATEGORY::SHIELD };
		break;
	default:
		break;
	}
	return return_vector;
}

string ITEM_AND_COMBAT_UTILITIES::get_string_from_ARMOR_CATEGORY( ARMOR_CATEGORY type_in )
{
	string return_string;

	switch ( type_in )
	{
	case ARMOR_CATEGORY::LIGHT:
		return_string = "Light Armour";
		break;
	case ARMOR_CATEGORY::MEDIUM:
		return_string = "Medium Armour";
		break;
	case ARMOR_CATEGORY::HEAVY:
		return_string = "Heavy Armour";
		break;
	case ARMOR_CATEGORY::SHIELD:
		return_string = "Shields";
		break;
	default:
		return_string = "INVALID";
		break;
	}
	return return_string;
}

WEAPON_TYPE ITEM_AND_COMBAT_UTILITIES::get_WEAPON_TYPE_from_string( string string_in )
{
	WEAPON_TYPE weapon_type;
	if ( string_in == "melee" )
	{
		weapon_type = WEAPON_TYPE::MELEE;
	}
	else if ( string_in == "ranged" )
	{
		weapon_type = WEAPON_TYPE::RANGED;
	}
	else
	{
		weapon_type = WEAPON_TYPE::INVALID;
	}
	return weapon_type;
}

string ITEM_AND_COMBAT_UTILITIES::get_string_from_WEAPON_TYPE( WEAPON_TYPE type_in )
{
	string return_string;

	switch ( type_in )
	{
	case WEAPON_TYPE::MELEE:
		return_string = "Melee";
		break;
	case WEAPON_TYPE::RANGED:
		return_string = "Ranged";
		break;
	default:
		return_string = "INVALID";
		break;
	}
	return return_string;
}