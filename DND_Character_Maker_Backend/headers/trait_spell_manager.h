#pragma once

#include "trait_spell.h"
#include <map>

class TRAIT_SPELL_MANAGER
{
public:
	static TRAIT_SPELL_MANAGER& get_instance() { static TRAIT_SPELL_MANAGER instance; return instance; }
	TRAIT_SPELL_MANAGER( TRAIT_SPELL_MANAGER const& ) = delete;
	void operator=( TRAIT_SPELL_MANAGER const& ) = delete;

	void print_all_trait_spells();
	TRAIT_SPELL* get_trait_spell( string name );

private:
	~TRAIT_SPELL_MANAGER();
	TRAIT_SPELL_MANAGER() { read_in_trait_spells(); };
	void read_in_trait_spells();
	std::map<string, TRAIT_SPELL*> m_trait_spells;
	const char filename[105]{ "C:/Users/Isaac/source/repos/DND_Character_Maker_Backend/DND_Character_Maker_Backend/csv/trait_spells.csv" };
};
