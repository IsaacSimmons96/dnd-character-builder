#include "..\headers\trait_spell_manager.h"
#include "..\headers\typedefs.h"
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

TRAIT_SPELL_MANAGER::~TRAIT_SPELL_MANAGER()
{
	for ( auto it = m_trait_spells.begin(); it != m_trait_spells.end(); ++it )
	{
		delete it->second;
	}
	m_trait_spells.clear();
}

void TRAIT_SPELL_MANAGER::read_in_trait_spells()
{
	std::ifstream file( filename );
	string value;
	std::stringstream ss;

	while ( getline( file, value ) )
	{
		ss << value;
		string name, desc, read_only_str;

		getline( ss, name, ';' );
		getline( ss, desc, ';' );
		getline( ss, read_only_str, ';' );

		bool read_only = false;
		if ( read_only_str == "TRUE" )
		{
			read_only = true;
		}

		TRAIT_SPELL* spell = read_only == true ? new TRAIT_SPELL( name, desc, read_only ) : new TRAIT_SPELL( name, desc, false );
		m_trait_spells.insert( std::make_pair( spell->get_spell_name(), spell ) );
		ss.clear();
	}
}

void TRAIT_SPELL_MANAGER::print_all_trait_spells()
{
	if ( m_trait_spells.size() <= 0 )
	{
		read_in_trait_spells();
	}
	for ( auto it = m_trait_spells.begin(); it != m_trait_spells.end(); ++it )
	{
		std::cout << it->second->get_spell_name() << std::endl;
		std::cout << it->second->get_spell_description() << "\n" << std::endl;
	}
}

TRAIT_SPELL* TRAIT_SPELL_MANAGER::get_trait_spell( string name )
{
	if ( m_trait_spells.size() <= 0 )
	{
		read_in_trait_spells();
	}
	for ( auto it = m_trait_spells.begin(); it != m_trait_spells.end(); ++it )
	{
		if ( it->first == name )
		{
			return it->second;
		}
	}
	return nullptr;
}