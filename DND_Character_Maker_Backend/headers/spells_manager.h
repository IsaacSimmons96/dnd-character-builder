#pragma once
#include "typedefs.h"
#include <map>
#include "spells.h"

class SPELLS_MANAGER
{
public:

	void read_in_spells();
	void print();

private:
	std::map<const string, const SPELL*> m_spells;
	const char m_filename[104]{ "C:/Users/Isaac/source/repos/DND_Character_Maker_Backend/DND_Character_Maker_Backend/csv/spell_list.csv" };
};
