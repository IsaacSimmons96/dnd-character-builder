#pragma once

#include "racial_traits.h"
#include <map>
#include "typedefs.h"
#include "character_enums.h"

class RACIAL_TRAITS_MANAGER
{
public:
	RACIAL_TRAITS_MANAGER();
	~RACIAL_TRAITS_MANAGER();

	void read_in_race_traits();
	void print_all_races();
	RACIAL_TRAITS* get_race_traits( DND_RACE race );

private:
	std::map< DND_RACE , RACIAL_TRAITS*> m_race_traits;
	const char filename[104]{ "C:/Users/Isaac/source/repos/DND_Character_Maker_Backend/DND_Character_Maker_Backend/csv/race_traits.csv" };
};

