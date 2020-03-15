#include "..\headers\trait_spell_manager.h"
#include "..\headers\typedefs.h"
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

TRAIT_MANAGER::~TRAIT_MANAGER()
{
	for ( auto it = m_traits.begin(); it != m_traits.end(); ++it )
	{
		delete it->second;
	}
	m_traits.clear();
}

void TRAIT_MANAGER::read_in_traits()
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

		const bool read_only = read_only_str == "TRUE";
		TRAIT* spell = new TRAIT( name, desc, read_only );
		m_traits.insert( std::make_pair( spell->get_spell_name(), spell ) );
		ss.clear();
	}
}

void TRAIT_MANAGER::print_all_traits()
{
	if ( m_traits.size() <= 0 )
	{
		read_in_traits();
	}
	for ( auto it = m_traits.begin(); it != m_traits.end(); ++it )
	{
		std::cout << it->second->get_spell_name() << std::endl;
		std::cout << it->second->get_spell_description() << "\n" << std::endl;
	}
}

TRAIT* TRAIT_MANAGER::get_trait_spell( string name )
{
	if ( m_traits.size() <= 0 )
	{
		read_in_traits();
	}
	for ( auto it = m_traits.begin(); it != m_traits.end(); ++it )
	{
		if ( it->first == name )
		{
			return it->second;
		}
	}
	return nullptr;
}