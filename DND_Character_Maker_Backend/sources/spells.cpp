#include "..\headers\spells.h"
#include <iostream>
#include "..\headers\spell_utilities.h"

MAGIC_SPELL::MAGIC_SPELL( string name, SCHOOL_OF_MAGIC school, string desc, string higher_desc, SPELL_CASTING_TIME casting_t, uint16_t range,
						  SPELL_COMPONENT components, string material_description, SPELL_DURATION duration, SPELL_DURATION_TIME spell_duration_time,
						  uint16_t spell_level, std::vector<DND_CLASS> classes ) : SPELL( name, desc, higher_desc, spell_level, classes )
{
	m_school = school;
	m_casting_time = casting_t;
	m_spell_range = range;
	m_material_description = material_description;
	m_spell_components = components;
	m_spell_duration = duration;
	m_spell_duration_time = spell_duration_time;
}

void MAGIC_SPELL::print() const
{
	std::cout << m_spell_name << std::endl;
	std::cout << "Level " << std::to_string( m_spell_level ) << " " << SPELL_UTILITIES::get_string_from_SCHOOL_OF_MAGIC( m_school ) << std::endl;
	std::cout << "Casting Time: " << SPELL_UTILITIES::get_string_from_SPELL_CASTING_TIME( m_casting_time ) << std::endl;
	std::cout << "Range: " << std::to_string( m_spell_range ) << std::endl;
	std::cout << "Components: " << SPELL_UTILITIES::get_string_from_SPELL_COMPONENT( m_spell_components ) << m_material_description << std::endl;
	std::cout << "Duration: " << SPELL_UTILITIES::get_string_from_SPELL_DURATION( m_spell_duration )
		<< SPELL_UTILITIES::get_string_from_SPELL_DURATION_TIME( m_spell_duration_time ) << std::endl;
	std::cout << m_spell_description << "\n" << std::endl;
	std::cout << "At Higher Levels. " << m_higher_level_description << std::endl;
}

SPELL::SPELL( string name, string desc, string higher_desc, uint16_t spell_level, std::vector<DND_CLASS> classes )
{
	m_spell_name = name;
	m_spell_description = desc;
	m_higher_level_description = higher_desc;
	m_spell_level = spell_level;
	for ( auto dnd_class : classes )
	{
		m_available_to_classes.push_back( dnd_class );
	}
}

void SPELL::print() const
{
	std::cout << m_spell_name << std::endl;
	std::cout << "Level " << std::to_string( m_spell_level );
	std::cout << m_spell_description << std::endl;
	std::cout << m_higher_level_description << std::endl;
}

bool SPELL::is_available_to_class( DND_CLASS class_in )
{
	for ( auto dnd_class : m_available_to_classes )
	{
		if ( dnd_class == class_in )
		{
			return true;
		}
	}
	return false;
}