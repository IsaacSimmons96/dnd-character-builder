#pragma once
#include "trait_spell.h"
#include <map>

class TRAIT_SPELL_MANAGER
{
public:
	void print_all_trait_spells();
	TRAIT_SPELL* get_trait_spell( string name );
	~TRAIT_SPELL_MANAGER();

private:
	void read_in_trait_spells();
	std::map<string, TRAIT_SPELL*> m_trait_spells;
	const char filename[96]{ "C:/Users/Isaac/Documents/dnd-character-builder/DND_Character_Maker_Backend/csv/trait_spells.csv" };
};