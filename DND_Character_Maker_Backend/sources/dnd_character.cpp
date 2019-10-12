#include "..\headers\dnd_character.h"
#include "..\headers\dnd_character_utilities.h"
#include "..\headers\generic_utilities.h"
#include <assert.h>
#include <iostream>

DND_CHARACTER::~DND_CHARACTER()
{
}

DND_CHARACTER::DND_CHARACTER()
{
}


DND_CHARACTER::DND_CHARACTER( DND_CHARACTER const &character_in )
{
	m_character_name = character_in.m_character_name;
	m_class = character_in.m_class;
	m_background = character_in.m_background;
	m_race = character_in.m_race;
	m_alignment = character_in.m_alignment;
}

void DND_CHARACTER::set_race( DND_RACE race_in, RACIAL_TRAITS_MANAGER& rtm ) 
{
	m_race = race_in;

	const auto race_traits = rtm.get_race_traits( m_race );

	m_speed = race_traits->get_speed();
	m_size = race_traits->get_size();

	for ( auto lang : race_traits->get_languages() )
	{
		add_language( lang );
	}

	for ( auto ab_bonus : race_traits->get_ability_score_bonuses() )
	{
		const auto ability_type = ab_bonus->get_bonus_type();
		switch ( ability_type )
		{
		case ABILITY_SCORE_TYPES::STRENGTH:
			m_strength += ab_bonus->get_bonus_value();
			break;
		case ABILITY_SCORE_TYPES::DEXTERITY:
			m_dexterity += ab_bonus->get_bonus_value();
			break;
		case ABILITY_SCORE_TYPES::CONSTITUTION:
			m_constitution += ab_bonus->get_bonus_value();
			break;
		case ABILITY_SCORE_TYPES::INTELLIGENCE:
			m_intelligence += ab_bonus->get_bonus_value();
			break;
		case ABILITY_SCORE_TYPES::WISDOM:
			m_wisdom += ab_bonus->get_bonus_value();
			break;
		case ABILITY_SCORE_TYPES::CHARISMA:
			m_charisma += ab_bonus->get_bonus_value();
			break;
		case ABILITY_SCORE_TYPES::INVALID:
		default:
			break;
		}
	}

	const auto tool_profs = race_traits->get_tool_proficiencys();
	if ( tool_profs.size() > 0 )
	{
		// Dwarves and the subrace dwarves get to pick 1 of 3 tool profs. See PHB page 20.
		if ( race_traits->get_race() == DND_RACE::DWARF || race_traits->get_race() == DND_RACE::HILL_DWARF || race_traits->get_race() == DND_RACE::MOUNTAIN_DWARF )
		{
			bool chosen_tool = false;
			while ( !chosen_tool )
			{
				std::cout << "Race Chosen can select 1 of these tools to be proficient in." << std::endl;

				for ( auto tool : tool_profs )
				{
					std::cout << DND_CHARACTER_UTILITIES::get_string_from_DND_TOOL( tool ) << std::endl;
				}

				string temp;
				ask_for_input( "Please enter one of these. (Type b, m, or s):", temp );
				const auto tool = DND_CHARACTER_UTILITIES::get_DND_TOOL_from_string( temp );

				if ( tool != DND_TOOL::INAVLID )
				{
					chosen_tool = true;
				}
			}
		}
		else if ( race_traits->get_race() != DND_RACE::INVALID )
		{
			for ( auto tool : tool_profs )
			{
				add_tool_proficiency( tool );
			}
		}
		else
		{
			std::cout << "Somethings gone wrong here.";
		}
	}
}

void DND_CHARACTER::set_passive_perception()
{
	m_passive_perception = 10 + DND_CHARACTER_UTILITIES::get_ability_score_modifier( m_wisdom );
}

void DND_CHARACTER::set_proficiency_bonus_from_level( u_int level )
{
	u_int prof_bonus;
	if ( level <= 4 )
	{
		prof_bonus = 2;
	}
	else if ( level > 4 && level <= 8 )
	{
		prof_bonus = 3;
	}
	else if ( level > 8 && level <= 12 )
	{
		prof_bonus = 4;
	}
	else if ( level > 12 && level <= 16 )
	{
		prof_bonus = 5;
	}
	else if ( level > 16 )
	{
		prof_bonus = 6;
	}
	set_proficiency_bonus( prof_bonus );
}

void DND_CHARACTER::add_skill_proficiency( DND_SKILL_TYPE skill )
{
	m_skills_proficient_in.push_back( skill );
}

void DND_CHARACTER::add_language( DND_LANGUAGE lang )
{
	m_languages.push_back( lang );
}

void DND_CHARACTER::add_tool_proficiency( DND_TOOL tool )
{
	m_tool_profs.push_back( tool );
}

void DND_CHARACTER::update_hit_dice( DND_DICE die, u_int number )
{
	if ( die != DND_DICE::PERCENTILE )
	{
		std::pair<std::map<DND_DICE, u_int>::iterator, bool> not_in_use;
		not_in_use = m_hit_dice.insert( std::make_pair( die, number ) );

		if ( !not_in_use.second )
		{
			m_hit_dice.at( die ) = number;
		}
	}
}

void DND_CHARACTER::update_skills()
{
	m_skills.clear();
	for ( u_int8 skill_index = 0; skill_index != INVALID; ++skill_index )
	{
		bool is_proficient = false;
		for ( auto skill : m_skills_proficient_in )
		{
			if ( skill_index == skill )
			{
				is_proficient = true;
			}
		}
		auto skill = (DND_SKILL_TYPE)skill_index;
		auto new_character_skill = new CHARACTER_SKILL( skill, DND_CHARACTER_UTILITIES::get_ABILITY_SORE_TYPE_from_DND_SKILL_TYPE( skill ), is_proficient, *this );

		m_skills.insert( std::make_pair( skill, new_character_skill ) );
	}
}

void DND_CHARACTER::print_skills()
{
	const std::string border = "*****************";

	std::cout << "Character Skills " << std::endl;
	std::cout << border << std::endl;
	for ( auto it = m_skills.begin(); it != m_skills.end(); ++it )
	{
		std::cout << DND_CHARACTER_UTILITIES::get_string_from_DND_SKILL_TYPE( it->first ) << " = " << std::to_string( it->second->m_skill_value ) << std::endl;
	}
	std::cout << border << std::endl;
}

void DND_CHARACTER::print_hit_dice()
{
	std::cout << "Hit Dice" << std::endl;
	for ( auto it = m_hit_dice.begin(); it != m_hit_dice.end(); ++it )
	{
		std::cout << get_string_from_DND_DICE( it->first ) << " = " << std::to_string( it->second ) << std::endl;
	}
}

void DND_CHARACTER::print_character_info()
{
	const std::string border = "************************************************************************************";
	const std::string spacer = "\n";
	std::cout << border << std::endl;
	std::cout << border << std::endl;
	std::cout << "Player Name = " << m_player_name << std::endl;
	std::cout << "Character Name = " << m_character_name << std::endl;
	std::cout << "Character Level = " << std::to_string( m_level ) << std::endl;
	std::cout << "Character Class = " << DND_CHARACTER_UTILITIES::get_string_from_DND_CLASS( m_class ) << std::endl;
	std::cout << "Character Background = " << DND_CHARACTER_UTILITIES::get_string_from_DND_BACKGROUND( m_background ) << std::endl;
	std::cout << "Character Race = " << DND_CHARACTER_UTILITIES::get_string_from_DND_RACE( m_race ) << std::endl;
	std::cout << "Character Alignment = " << DND_CHARACTER_UTILITIES::get_string_from_DND_ALIGNMENT( m_alignment ) << std::endl;
	std::cout << "Character Hit Points = " << std::to_string( m_hit_points ) << std::endl;
	std::cout << "Character Prof Bonus = " << std::to_string( m_proficiency_bonus ) << std::endl;
	std::cout << "Character Armour Class = " << std::to_string( m_armour_class ) << std::endl;
	std::cout << "Character Passive Perception = " << std::to_string( m_passive_perception ) << std::endl;
	std::cout << spacer << std::endl;
	std::cout << "Character Strength = " << std::to_string( m_strength ) << std::endl;
	std::cout << "Character Dexterity = " << std::to_string( m_dexterity ) << std::endl;
	std::cout << "Character Constitution = " << std::to_string( m_constitution ) << std::endl;
	std::cout << "Character Intelligence = " << std::to_string( m_intelligence ) << std::endl;
	std::cout << "Character Wisdom = " << std::to_string( m_wisdom ) << std::endl;
	std::cout << "Character Charisma = " << std::to_string( m_charisma ) << std::endl;
	print_saving_throws();
	std::cout << spacer << std::endl;
	print_skills();
	print_hit_dice();
	std::cout << spacer << std::endl;
	std::cout << border << std::endl;
	std::cout << border << std::endl;
}

u_int DND_CHARACTER::get_ability_value_from_DND_ABILITY_SCORE_TYPES( ABILITY_SCORE_TYPES ability_type )
{
	u_int value;
	switch ( ability_type )
	{
	case ABILITY_SCORE_TYPES::STRENGTH:
		value = get_strength();
		break;
	case ABILITY_SCORE_TYPES::DEXTERITY:
		value = get_dexterity();
		break;
	case ABILITY_SCORE_TYPES::CONSTITUTION:
		value = get_constitution();
		break;
	case ABILITY_SCORE_TYPES::INTELLIGENCE:
		value = get_intelligence();
		break;
	case ABILITY_SCORE_TYPES::WISDOM:
		value = get_wisdom();
		break;
	case ABILITY_SCORE_TYPES::CHARISMA:
		value = get_charisma();
		break;
	case ABILITY_SCORE_TYPES::INVALID:
		value = 0;
		break;
	}
	return value;
}

std::vector< DND_SKILL_TYPE > DND_CHARACTER::get_skill_proficiencys()
{
	return m_skills_proficient_in;
}

void DND_CHARACTER::SAVING_THROWS::set_saving_throws( DND_CHARACTER &character )
{
	m_strength_throw = DND_CHARACTER_UTILITIES::get_ability_score_modifier( character.get_strength() );
	m_dexterity_throw = DND_CHARACTER_UTILITIES::get_ability_score_modifier( character.get_dexterity() );
	m_constitution_throw = DND_CHARACTER_UTILITIES::get_ability_score_modifier( character.get_constitution() );
	m_intelligence_throw = DND_CHARACTER_UTILITIES::get_ability_score_modifier( character.get_intelligence() );
	m_wisdom_throw = DND_CHARACTER_UTILITIES::get_ability_score_modifier( character.get_wisdom() );
	m_charisma_throw = DND_CHARACTER_UTILITIES::get_ability_score_modifier( character.get_charisma() );

	switch ( character.get_character_class() )
	{
	case DND_CLASS::BARBARIAN:
	case DND_CLASS::FIGHTER:
		m_strength_throw += character.get_proficiency_bonus();
		m_constitution_throw += character.get_proficiency_bonus();
		break;

	case DND_CLASS::BARD:
		m_dexterity_throw += character.get_proficiency_bonus();
		m_charisma_throw += character.get_proficiency_bonus();
		break;

	case DND_CLASS::CLERIC:
	case DND_CLASS::PALADIN:
	case DND_CLASS::WARLOCK:
		m_wisdom_throw += character.get_proficiency_bonus();
		m_charisma_throw += character.get_proficiency_bonus();
		break;

	case DND_CLASS::DRUID:
	case DND_CLASS::WIZARD:
		m_intelligence_throw += character.get_proficiency_bonus();
		m_wisdom_throw += character.get_proficiency_bonus();
		break;

	case DND_CLASS::MONK:
	case DND_CLASS::RANGER:
		m_strength_throw += character.get_proficiency_bonus();
		m_dexterity_throw += character.get_proficiency_bonus();
		break;

	case DND_CLASS::ROGUE:
		m_dexterity_throw += character.get_proficiency_bonus();
		m_intelligence_throw += character.get_proficiency_bonus();
		break;

	case DND_CLASS::SORCERER:
		m_constitution_throw += character.get_proficiency_bonus();
		m_charisma_throw += character.get_proficiency_bonus();
		break;

	case DND_CLASS::INVALID:
	default:
		break;
	}
}

void DND_CHARACTER::SAVING_THROWS::print_saving_throws()
{
	std::cout << "Strength throw = " << std::to_string( m_strength_throw ) << std::endl;
	std::cout << "Dex throw = " << std::to_string( m_dexterity_throw ) << std::endl;
	std::cout << "Const throw = " << std::to_string( m_constitution_throw ) << std::endl;
	std::cout << "Intel throw = " << std::to_string( m_intelligence_throw ) << std::endl;
	std::cout << "Wisdom throw = " << std::to_string( m_wisdom_throw ) << std::endl;
	std::cout << "Charisma throw = " << std::to_string( m_charisma_throw ) << std::endl;
}

DND_CHARACTER::CHARACTER_SKILL::CHARACTER_SKILL( DND_SKILL_TYPE skill_type, ABILITY_SCORE_TYPES ability_base, bool is_prof, DND_CHARACTER &character )
{
	m_skill_name = skill_type;
	m_ability_dependant_on = ability_base;
	m_is_proficient = is_prof;
	m_skill_value = DND_CHARACTER_UTILITIES::get_ability_score_modifier( character.get_ability_value_from_DND_ABILITY_SCORE_TYPES( m_ability_dependant_on ) );

	if ( m_is_proficient )
	{
		m_skill_value += character.get_proficiency_bonus();
	}
}