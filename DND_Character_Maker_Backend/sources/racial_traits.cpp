#include "..\headers\dnd_character_utilities.h"
#include "..\headers\racial_traits.h"
#include <iostream>

RACIAL_TRAITS::RACIAL_TRAITS( DND_RACE race, u_int age, u_int speed, string align_desc, DND_SIZE size, std::vector<DND_LANGUAGE> langs, std::vector<DND_TOOL> tool_profs,
							  std::vector<TRAIT*> traits, std::vector<ABILITY_SCORE_BONUS*> ability_bonuses, bool need_to_pick_subrace, DND_RACE main_race /*= DND_RACE::INVALID*/ )
{
	m_race = race;
	m_typical_age = age;
	m_race_speed = speed;
	m_alignment_description = align_desc;
	m_race_size = size;
	for ( auto lang : langs )
	{
		m_race_languages.push_back( lang );
	}
	for ( auto prof : tool_profs )
	{
		m_tool_proficiency.push_back( prof );
	}
	for ( auto trait : traits )
	{
		m_traits.push_back( trait );
		if ( !trait->is_read_only() )
		{
			m_sheet_traits.push_back( trait );
		}
	}
	for ( auto bonus : ability_bonuses )
	{
		m_ability_score_bonuses.push_back( bonus );
	}

	m_must_pick_subrace = need_to_pick_subrace;
	m_main_race = main_race;
}

RACIAL_TRAITS::~RACIAL_TRAITS()
{
}

void RACIAL_TRAITS::print_racial_traits()
{
	std::cout << "Race = " << DND_CHARACTER_UTILITIES::get_string_from_DND_RACE( m_race ) << std::endl;
	std::cout << "Typical Max Age = " << std::to_string( m_typical_age ) << std::endl;
	std::cout << "Race Speed = " << std::to_string( m_race_speed ) << std::endl;
	std::cout << "Alignment Description = " << m_alignment_description << std::endl;
	std::cout << "Size = " << DND_CHARACTER_UTILITIES::get_string_from_DND_SIZE( m_race_size ) << std::endl;
	u_int8 counter = 1;
	for ( auto lang : m_race_languages )
	{
		std::cout << "Language " << std::to_string( counter ) << " = " << DND_CHARACTER_UTILITIES::get_string_from_DND_LANGUAGE( lang ) << std::endl;
		counter++;
	}
	counter = 1;
	for ( auto tool : m_tool_proficiency )
	{
		std::cout << "Tool Proficiency Choice " << std::to_string( counter ) << " = " << DND_CHARACTER_UTILITIES::get_string_from_DND_TOOL( tool ) << std::endl;
		counter++;
	}
	counter = 1;
	for ( auto bonus : m_ability_score_bonuses )
	{
		std::cout << "Ability Score Bonus " << std::to_string( counter ) << " = " << DND_CHARACTER_UTILITIES::get_string_from_ABILITY_SCORE_TYPES( bonus->get_bonus_type() ) << ", Value = " << std::to_string( bonus->get_bonus_value() ) << std::endl;

		counter++;
	}
	counter = 1;
	for ( auto spell : m_traits )
	{
		std::cout << "Race Trait " << std::to_string( counter ) << " = " << spell->get_spell_name() << std::endl;
		std::cout << spell->get_spell_description() << std::endl;
		std::cout << "\n";
		counter++;
	}
}