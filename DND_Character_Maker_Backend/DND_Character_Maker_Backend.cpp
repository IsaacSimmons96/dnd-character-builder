// DND_Character_Maker_Backend.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "headers/dice_functions.h"
#include "headers/dnd_character.h"
#include "headers/dnd_character_utilities.h"
#include "headers/generic_utilities.h"
#include "headers/racial_traits_manager.h"
#include "headers/spells_manager.h"
#include "headers/trait_spell_manager.h"
#include <iostream>

int main()
{
	DND_CHARACTER character;
	TRAIT_SPELL_MANAGER tsm;
	RACIAL_TRAITS_MANAGER trait_manager( tsm );
	//trait_manager.print_all_races();

	/*SPELLS_MANAGER spell_manager;
	spell_manager.read_in_spells();*/
	//spell_manager.print_all_spells();

	// ISAAC ADD SUPPORT FOR SUB RACES WHEN SELECTING A RACE !!!!!!!!!!!!

	string temp;
	int temp_int;
	ask_for_input_no_lowercasing( "Enter player name: ", temp );
	character.set_player_name( temp );
	ask_for_input_no_lowercasing( "Enter character name: ", temp );
	character.set_character_name( temp );

	const string character_name_prefix = "Enter " + character.get_name();
	ask_for_input( character_name_prefix + "'s Class: ", temp );
	character.set_character_class( DND_CHARACTER_UTILITIES::get_DND_CLASS_from_string( temp ) );

	ask_for_input( character_name_prefix + "'s Race: ", temp );
	character.set_race( DND_CHARACTER_UTILITIES::get_DND_RACE_from_string( temp ), trait_manager );

	ask_for_input( character_name_prefix + "'s Level: ", temp_int );
	character.set_level( temp_int );

	ask_for_input( character_name_prefix + "'s Alignment:", temp );
	character.set_alignment( DND_CHARACTER_UTILITIES::get_DND_ALIGNMENT_from_string( temp ) );

	ask_for_input( character_name_prefix + "'s Strength: ", temp_int );
	character.set_strength( temp_int );
	ask_for_input( character_name_prefix + "'s Dexterity: ", temp_int );
	character.set_dexterity( temp_int );
	ask_for_input( character_name_prefix + "'s Consitution: ", temp_int );
	character.set_constitution( temp_int );
	ask_for_input( character_name_prefix + "'s Intelligence: ", temp_int );
	character.set_intelligence( temp_int );
	ask_for_input( character_name_prefix + "'s Wisdom: ", temp_int );
	character.set_wisdom( temp_int );
	ask_for_input( character_name_prefix + "'s Charisma: ", temp_int );
	character.set_charisma( temp_int );

	bool entered_all_skill_profs = false;

	while ( !entered_all_skill_profs )
	{
		ask_for_input( "Add a Skill Proficiency: ", temp );
		character.add_skill_proficiency( DND_CHARACTER_UTILITIES::get_DND_SKILL_from_string( temp ) );

		ask_for_input( "Finished Adding Skill Proficiencys? (yes/no):", temp );
		if ( temp == "yes" || temp == "y" )
		{
			entered_all_skill_profs = true;
		}
	}
	character.update_skills();

	const auto char_class = character.get_character_class();
	std::cout << "Setting hit points based on 1 " + get_string_from_DND_DICE( get_hit_dice_from_DND_CLASS( char_class ) ) + " plus " + character.get_name() + "'s Constitution modifier (" + std::to_string( DND_CHARACTER_UTILITIES::get_ability_score_modifier( character.get_constitution() ) ) + ") \n";
	character.set_hit_points( get_max_roll_for_dice( get_hit_dice_from_DND_CLASS( char_class ) ) + DND_CHARACTER_UTILITIES::get_ability_score_modifier( character.get_constitution() ) );
	std::cout << "Hit point maximum is: " + std::to_string( character.get_hit_points() ) + "\n";

	ask_for_input( character_name_prefix + "'s Armor Class: ", temp_int );
	character.set_armour_class( temp_int );

	std::cout << "Setting Saving Throws.";
	character.set_saving_throws();

	std::cout << "Setting Hit Dice.";
	character.update_hit_dice( get_hit_dice_from_DND_CLASS( char_class ), character.get_level() );

	character.print_character_info();
}