// DND_Character_Maker_Backend.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "headers/dice_functions.h"
#include "headers/dnd_character.h"
#include "headers/racial_traits_manager.h"
#include "headers/trait_spell_manager.h"
#include <iostream>
#include "headers/spells_manager.h"


int main()
{
	DND_CHARACTER john;
	RACIAL_TRAITS_MANAGER trait_manager;

	trait_manager.read_in_race_traits();
	//trait_manager.print_all_races();

	SPELLS_MANAGER spell_manager;
	spell_manager.read_in_spells();
	//spell_manager.print_all_spells();

	john.set_player_name( "Isaac" );
	john.set_character_name( "Hal Redwood" );
	john.set_character_class( DND_CLASS::FIGHTER );
	john.set_race( DND_RACE::DWARF );
	john.set_alignment( DND_ALIGNMENT::NEUTRAL_GOOD );
	john.set_hit_points( roll_dice( DND_DICE::D6, 0, 3 ) );
	john.set_strength( 18 );
	john.set_dexterity( 12 );
	john.set_constitution( 20 );
	john.set_intelligence( 8 );
	john.set_wisdom( 9 );
	john.set_charisma( 10 );
	john.set_level( 2 );
	john.set_armour_class( 16 );
	john.set_saving_throws( SAVING_THROW_TYPES::CONSTITUTION, SAVING_THROW_TYPES::STRENGTH );
	john.add_skill_proficiency( HISTORY );
	john.add_skill_proficiency( PERCEPTION );
	john.add_skill_proficiency( NATURE );
	john.update_skills();
	john.update_hit_dice( DND_DICE::D10, 2 );

	//john.print_character_info();




}
