#pragma once

#include "racial_traits.h"
#include <map>
#include "typedefs.h"
#include "character_enums.h"

class TRAIT_MANAGER;

class RACIAL_TRAITS_MANAGER
{
public:
	RACIAL_TRAITS_MANAGER( TRAIT_MANAGER& tsm );
	~RACIAL_TRAITS_MANAGER();

	void print_all_races();
	void refresh_races();
	RACIAL_TRAITS* get_race_traits( DND_RACE race );
	std::vector< DND_RACE > get_subraces( DND_RACE race );

private:
	std::map< DND_RACE, RACIAL_TRAITS*> m_race_traits;

	const char filename[95]{ "C:/Users/Isaac/Documents/dnd-character-builder/DND_Character_Maker_Backend/csv/race_traits.csv" };
	TRAIT_MANAGER* m_tsm{ nullptr };

	void read_in_race_traits();
};