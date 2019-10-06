// DND_Character_Maker_Backend.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "headers/dice_functions.h"
#include "headers/dnd_character.h"
#include "headers/racial_traits_manager.h"
#include "headers/trait_spell_manager.h"
#include "headers/dnd_character_utilities.h"
#include <iostream>
#include "headers/spells_manager.h"


void lower_string( string& str )
{
	for ( int i = 0; str[i] != '\0'; i++ )
	{
		if ( str[i] >= 'A' && str[i] <= 'Z' )    //checking for uppercase characters
			str[i] = str[i] + 32;         //converting uppercase to lowercase
	}
}

void ask_for_input( string question, string& value )
{
	std::cout << question;
	getline( std::cin, value );
	lower_string( value );
}

void ask_for_input( string question, int& value )
{
	std::cout << question;
	string temp;
	getline( std::cin, temp );
	value = stoi( temp );
}

int main()
{
	DND_CHARACTER character;
	RACIAL_TRAITS_MANAGER trait_manager;

	trait_manager.read_in_race_traits();
	//trait_manager.print_all_races();

	SPELLS_MANAGER spell_manager;
	spell_manager.read_in_spells();
	//spell_manager.print_all_spells();

	string temp;
	int temp_int;
	ask_for_input( "Enter player name: ", temp );
	character.set_player_name( temp );
	ask_for_input( "Enter character name: ", temp );
	character.set_character_name( temp );

	const string character_name_prefix = "Enter " + character.get_name();
	ask_for_input( character_name_prefix + "'s Class: ", temp );
	character.set_character_class( DND_CHARACTER_UTILITIES::get_DND_CLASS_from_string( temp ) );

	ask_for_input( character_name_prefix + "'s Race: ", temp );
	character.set_race( DND_CHARACTER_UTILITIES::get_DND_RACE_from_string( temp ) );

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

	std::cout << "Setting hit points based on 1 " + get_string_from_DND_DICE( get_hit_dice_from_DND_CLASS( character.get_character_class() ) ) + " plus " + character.get_name() + "'s Constitution modifier (" + std::to_string( DND_CHARACTER_UTILITIES::get_ability_score_modifier( character.get_constitution() )) + ") \n" ;
	character.set_hit_points( get_max_roll_for_dice( get_hit_dice_from_DND_CLASS( character.get_character_class() ) ) + DND_CHARACTER_UTILITIES::get_ability_score_modifier( character.get_constitution() ) );
	std::cout << "Hit point maximum is: " + std::to_string( character.get_hit_points() ) + "\n";

	ask_for_input( character_name_prefix + "'s Armor Class: ", temp_int );
	character.set_armour_class( temp_int );

	character.set_saving_throws( SAVING_THROW_TYPES::CONSTITUTION, SAVING_THROW_TYPES::STRENGTH );
	character.add_skill_proficiency( HISTORY );
	character.add_skill_proficiency( PERCEPTION );
	character.add_skill_proficiency( NATURE );
	character.update_skills();
	character.update_hit_dice( DND_DICE::D10, 2 );

	character.print_character_info();




}
