#include "..\headers\item_utilities.h"

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

	switch ( string_in )
	{
	case "acid":
		return_type = DAMAGE_TYPE::ACID;
		break;
	case "bludgeoning":
		return_type = DAMAGE_TYPE::BLUDGEONING;
		break;
	case "cold":
		return_type = DAMAGE_TYPE::COLD;
		break;
	case "fire":
		return_type = DAMAGE_TYPE::FIRE;
		break;
	case "force":
		return_type = DAMAGE_TYPE::FORCE;
		break;
	case "lightning":
		return_type = DAMAGE_TYPE::LIGHTNING;
		break;
	case "necrotic":
		return_type = DAMAGE_TYPE::NECROTIC;
		break;
	case "piercing":
		return_type = DAMAGE_TYPE::PIERCING;
		break;
	case "poison":
		return_type = DAMAGE_TYPE::POISON;
		break;
	case "psychic":
		return_type = DAMAGE_TYPE::PSYCHIC;
		break;
	case "radiant":
		return_type = DAMAGE_TYPE::RADIANT;
		break;
	case "slashing":
		return_type = DAMAGE_TYPE::SLASHING;
		break;
	case "thunder":
		return_type = DAMAGE_TYPE::THUNDER;
		break;
	default:
		return_type = DAMAGE_TYPE::INVALID;
		break;
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

	switch ( string_in )
	{
	case "ammunition":
		return_type = WEAPON_PROPERTIES::AMMUNITION;
		break;
	case "finesse":
		return_type = WEAPON_PROPERTIES::FINESSE;
		break;
	case "heavy":
		return_type = WEAPON_PROPERTIES::HEAVY;
		break;
	case "improvised":
		return_type = WEAPON_PROPERTIES::IMPROVISED_WEAPON;
		break;
	case "light":
		return_type = WEAPON_PROPERTIES::LIGHT;
		break;
	case "loading":
		return_type = WEAPON_PROPERTIES::LOADING;
		break;
	case "range":
		return_type = WEAPON_PROPERTIES::RANGE;
		break;
	case "reach":
		return_type = WEAPON_PROPERTIES::REACH;
		break;
	case "special":
		return_type = WEAPON_PROPERTIES::SPECIAL;
		break;
	case "thrown":
		return_type = WEAPON_PROPERTIES::THROWN;
		break;
	case "two handed":
		return_type = WEAPON_PROPERTIES::TWO_HANDED;
		break;
	case "versatile":
		return_type = WEAPON_PROPERTIES::VERSATILE;
		break;
	default:
		return_type = WEAPON_PROPERTIES::INVALID;
		break;
	}
	return return_type;
}

string ITEM_AND_COMBAT_UTILITIES::get_string_from_WEAPON_PROFICIENCY( WEAPON_PROFICIENCY type_in )
{
	string return_string;

	switch ( type_in )
	{
	case WEAPON_PROFICIENCY::SIMPLE:
		return_string = "Simple";
		break;
	case WEAPON_PROFICIENCY::MARTIAL:
		return_string = "Martial";
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

	switch ( string_in )
	{
	case "simple":
		return_prof = WEAPON_PROFICIENCY::SIMPLE;
		break;
	case "martial":
		return_prof = WEAPON_PROFICIENCY::MARTIAL;
		break;
	default:
		return_prof = WEAPON_PROFICIENCY::INVALID;
		break;
	}
	return return_prof;
}

ARMOR_CATEGORY ITEM_AND_COMBAT_UTILITIES::get_ARMOR_CATEGORY_from_string( string string_in )
{
	ARMOR_CATEGORY return_cat;

	switch ( string_in )
	{
	case "heavy":
		return_cat = ARMOR_CATEGORY::HEAVY;
		break;
	case "light":
		return_cat = ARMOR_CATEGORY::LIGHT;
		break;
	case "medium":
		return_cat = ARMOR_CATEGORY::MEDIUM;
		break;
	case "shield":
		return_cat = ARMOR_CATEGORY::SHIELD;
		break;
	default:
		return_cat = ARMOR_CATEGORY::INVALID;
		break;
	}
	return return_cat;
}

string ITEM_AND_COMBAT_UTILITIES::get_string_from_ARMOR_CATEGORY( ARMOR_CATEGORY type_in )
{
	string return_string;

	switch ( type_in )
	{
	case ARMOR_CATEGORY::LIGHT:
		return_string = "Light";
		break;
	case ARMOR_CATEGORY::MEDIUM:
		return_string = "Medium";
		break;
	case ARMOR_CATEGORY::HEAVY:
		return_string = "Heavy";
		break;
	case ARMOR_CATEGORY::SHIELD:
		return_string = "Shield";
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

	switch ( string_in )
	{
	case "melee":
		weapon_type = WEAPON_TYPE::MELEE;
		break;
	case "ranged":
		weapon_type = WEAPON_TYPE::RANGED;
		break;
	default:
		weapon_type = WEAPON_TYPE::INVALID;
		break;
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



