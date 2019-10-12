#include "..\headers\racial_traits_manager.h"

#include "..\headers\dnd_character_utilities.h"
#include "..\headers\race_utilities.h"
#include "..\headers\trait_spell.h"
#include "..\headers\trait_spell_manager.h"
#include <fstream>
#include <iosfwd>
#include <sstream>

RACIAL_TRAITS_MANAGER::RACIAL_TRAITS_MANAGER()
{
}

RACIAL_TRAITS_MANAGER::~RACIAL_TRAITS_MANAGER()
{
}

void RACIAL_TRAITS_MANAGER::read_in_race_traits()
{
	std::ifstream file( filename );
	string value, temp;
	std::stringstream ss;
	u_int uint_temp;

	auto convert_string_to_int = [&]()
	{
		std::stringstream num_stringstream( temp );
		num_stringstream >> uint_temp;
	};

	while ( getline( file, value ) )
	{
		ss << value;

		getline( ss, temp, ';' );
		const DND_RACE race = DND_CHARACTER_UTILITIES::get_DND_RACE_from_string( temp );
		getline( ss, temp, ';' );
		convert_string_to_int();
		const u_int age = uint_temp;
		getline( ss, temp, ';' );
		convert_string_to_int();
		const u_int speed = uint_temp;
		getline( ss, temp, ';' );
		const string description = temp;
		getline( ss, temp, ';' );
		const DND_SIZE size = DND_CHARACTER_UTILITIES::get_DND_SIZE_from_string( temp );

		std::vector<ABILITY_SCORE_BONUS*> bonuses;

		getline( ss, temp, ';' );
		ABILITY_SCORE_TYPES ability = DND_CHARACTER_UTILITIES::get_ABILITY_SCORE_TYPE_from_string( temp );
		getline( ss, temp, ';' );
		convert_string_to_int();
		u_int ability_score_value = uint_temp;
		if ( ability != ABILITY_SCORE_TYPES::INVALID )
		{
			ABILITY_SCORE_BONUS* bonus = new ABILITY_SCORE_BONUS( ability, ability_score_value );
			bonuses.push_back( bonus );
		}
		getline( ss, temp, ';' );
		ability = DND_CHARACTER_UTILITIES::get_ABILITY_SCORE_TYPE_from_string( temp );
		getline( ss, temp, ';' );
		convert_string_to_int();
		ability_score_value = uint_temp;
		if ( ability != ABILITY_SCORE_TYPES::INVALID )
		{
			ABILITY_SCORE_BONUS* bonus = new ABILITY_SCORE_BONUS( ability, ability_score_value );
			bonuses.push_back( bonus );
		}

		std::vector<TRAIT_SPELL*> spells;
		while ( getline( ss, temp, ';' ) )
		{
			TRAIT_SPELL* spell = TRAIT_SPELL_MANAGER::get_instance().get_trait_spell( temp );
			if ( spell )
			{
				spells.push_back( spell );
			}
		}

		RACIAL_TRAITS* race_traits = new RACIAL_TRAITS( race, age, speed, description, size, RACE_UTILITIES::get_languages_from_race( race ), RACE_UTILITIES::get_tool_profs_from_race( race ), spells, bonuses );

		m_race_traits.insert( std::make_pair( race_traits->get_race(), race_traits ) );

		ss.clear();
	}
}

void RACIAL_TRAITS_MANAGER::print_all_races()
{
	for ( auto it = m_race_traits.begin(); it != m_race_traits.end(); ++it )
	{
		it->second->print_racial_traits();
	}
}

RACIAL_TRAITS* RACIAL_TRAITS_MANAGER::get_race_traits( DND_RACE race )
{
	for ( auto it = m_race_traits.begin(); it != m_race_traits.end(); ++it )
	{
		if ( it->first == race )
		{
			return it->second;
		}
	}
	return nullptr;
}