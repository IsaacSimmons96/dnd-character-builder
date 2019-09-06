#include "..\headers\spells_manager.h"

#include "..\headers\dnd_character_utilities.h"
#include "..\headers\spell_utilities.h"
#include "..\headers\typedefs.h"
#include <fstream>
#include <iosfwd>
#include <sstream>

void SPELLS_MANAGER::read_in_spells()
{
	std::ifstream file( m_filename );
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
		string spell_name = temp;

		getline( ss, temp, ';' );
		const SPELL_CASTING_TIME cast_time = SPELL_UTILITIES::get_casting_time_from_string( temp );

		getline( ss, temp, ';' );
		const SCHOOL_OF_MAGIC magic_school = SPELL_UTILITIES::get_school_of_magic_from_string( temp );

		getline( ss, temp, ';' );
		convert_string_to_int();
		const u_int spell_range = uint_temp;

		getline( ss, temp, ';' );
		const SPELL_COMPONENT spell_components = SPELL_UTILITIES::get_spell_component_from_string( temp );

		string material_description;
		getline( ss, temp, ';' );
		if ( spell_components == SPELL_COMPONENT::MATERIAL || spell_components == SPELL_COMPONENT::VERBAL_MATERIAL || spell_components == SPELL_COMPONENT::VERBAL_SOMATIC_MATERIAL || spell_components == SPELL_COMPONENT::SOMATIC_MATERIAL )
		{
			material_description = "(";
			material_description += temp;
			material_description += ")";
		}
		
		getline( ss, temp, ';' );
		const SPELL_DURATION duration_type = SPELL_UTILITIES::get_duration_from_string( temp );

		SPELL_DURATION_TIME duration_time_value = SPELL_DURATION_TIME::INVALID;
		getline( ss, temp, ';' );
		if ( duration_type == SPELL_DURATION::CONCENTRATION_UP_TO_TIME || duration_type == SPELL_DURATION::TIME )
		{
			duration_time_value = SPELL_UTILITIES::get_duration_time_from_string( temp );
		}

		getline( ss, temp, ';' );
		const string description = temp;

		getline( ss, temp, ';' );
		const string higher_level_description = temp;

		getline( ss, temp, ';' );
		temp.erase( 0, 4 );
		convert_string_to_int();
		const u_int spell_level = uint_temp;

		std::vector<DND_CLASS> classes;
		while ( getline( ss, temp, ';' ) )
		{
			const DND_CLASS dnd_class = DND_CHARACTER_UTILITIES::get_DND_CLASS_from_string( temp );
			if ( dnd_class != DND_CLASS::INVALID )
			{
				classes.push_back( dnd_class );
			}
		}

		const MAGIC_SPELL* new_spell = new MAGIC_SPELL( spell_name, magic_school, description, higher_level_description, cast_time, spell_range,
														spell_components, material_description, duration_type, duration_time_value, spell_level, classes );
		m_spells.insert( std::make_pair( new_spell->get_spell_name(), new_spell ) );

		ss.clear();
	}
}

void SPELLS_MANAGER::print_all_spells()
{
	for ( auto it = m_spells.begin(); it != m_spells.end(); ++it )
	{
		it->second->print_spell();
	}
}

