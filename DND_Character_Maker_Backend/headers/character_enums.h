#pragma once

enum class DND_CLASS : char
{
	BARBARIAN,
	BARD,
	CLERIC,
	DRUID,
	FIGHTER,
	MONK,
	PALADIN,
	RANGER,
	ROGUE,
	SORCERER,
	WARLOCK,
	WIZARD,
	INVALID
};

enum class DND_BACKGROUND : char
{
	PLACEHOLDER,
	INVALID
};

enum class DND_RACE : char
{
	HUMAN,
	DWARF,
	HILL_DWARF,
	MOUNTAIN_DWARF,
	HIGH_ELF,
	WOOD_ELF,
	DROW_ELF,
	HALFLING,
	DRAGONBORN,
	GNOME,
	HALF_ELF,
	HALF_ORC,
	TIEFLING,
	INVALID
};

enum class DND_ALIGNMENT : char
{
	LAWFUL_GOOD,
	NEUTRAL_GOOD,
	CHAOTIC_GOOD,
	LAWFUL_NEUTRAL,
	NEUTRAL,
	CHAOTIC_NEUTRAL,
	LAWFUL_EVIL,
	NEUTRAL_EVIL,
	CHAOTIC_EVIL,
	INVALID

};

enum class DND_LANGUAGE : char
{
	COMMON,
	DWARVISH,
	ELVISH,
	GIANT,
	GNOMISH,
	GOBLIN,
	HALFLING,
	ORC,
	ABYSSAL,
	CELESTIAL,
	DEEP_SPEECH,
	DRACONIC,
	INFERNAL,
	PRIMORDIAL,
	SYLVAN,
	UNDERCOMMON,
	INVALID
};


enum class SAVING_THROW_TYPES : char
{
	STRENGTH,
	DEXTERITY,
	CONSTITUTION,
	INTELLIGENCE,
	WISDOM,
	CHARISMA
};

enum class ABILITY_SCORE_TYPES : char
{
	STRENGTH,
	DEXTERITY,
	CONSTITUTION,
	INTELLIGENCE,
	WISDOM,
	CHARISMA,
	INVALID
};

enum class DND_SIZE : char
{
	SMALL,
	MEDIUM,
	LARGE,
	INVALID
};


enum class DND_TOOL_PROFICIENCY : char
{
	BREWERS_SUPPLIES,
	MASONS_TOOLS,
	SMITHS_TOOLS,
	INAVLID
};

enum DND_SKILL_TYPE : char
{
	ACROBATICS,
	ANIMAL_HANDLING,
	ARCANA,
	ATHLETICS,
	DECEPTION,
	HISTORY,
	INSIGHT,
	INTIMIDATION,
	INVESTIGATION,
	MEDICINE,
	NATURE,
	PERCEPTION,
	PERFORMANCE,
	PERSUASION,
	RELIGION,
	SLEIGHT_OF_HAND,
	STEALTH,
	SURVIVAL,
	INVALID
};
