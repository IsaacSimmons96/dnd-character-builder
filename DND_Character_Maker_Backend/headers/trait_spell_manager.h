#pragma once
#include "trait_spell.h"
#include <map>

class TRAIT_MANAGER
{
public:
	void print();
	TRAIT* get_trait_spell( string name );
	~TRAIT_MANAGER();

private:
	void read_in_traits();
	std::map<string, TRAIT*> m_traits;
	const char filename[96]{ "C:/Users/Isaac/Documents/dnd-character-builder/DND_Character_Maker_Backend/csv/traits.csv" };
};