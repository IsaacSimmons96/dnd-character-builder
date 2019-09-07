#pragma once

enum class DAMAGE_TYPE : char
{
	ACID,
	BLUDGEONING,
	COLD,
	FIRE,
	FORCE,
	LIGHTNING,
	NECROTIC,
	PIERCING,
	POISON,
	PSYCHIC,
	RADIANT,
	SLASHING,
	THUNDER,
	INVALID
};

enum class WEAPON_PROPERTIES : char
{
	AMMUNITION,
	FINESSE,
	HEAVY,
	LIGHT,
	LOADING,
	RANGE,
	REACH,
	SPECIAL,
	THROWN,
	TWO_HANDED,
	VERSATILE,
	IMPROVISED_WEAPON,
	INVALID
};

enum class WEAPON_PROFICIENCY : char
{
	SIMPLE,
	MARTIAL,
	INVALID
};

enum class WEAPON_TYPE : char
{
	MELEE,
	RANGED,
	INVALID
};

enum class ARMOR_CATEGORY : char
{
	LIGHT,
	MEDIUM,
	HEAVY,
	INVALID
};