#include "..\headers\trait_spell.h"
#include <iostream>

TRAIT::TRAIT( string name, string desc, bool read_only )
{
	m_spell_description = desc;
	m_spell_name = name;
	m_read_only = read_only;
}

TRAIT::~TRAIT()
{
}

void TRAIT::set_spell_description( string spell_description )
{
	m_spell_description = spell_description;
}

string TRAIT::get_spell_description()
{
	return m_spell_description;
}

void TRAIT::print() const
{
	std::cout << m_spell_name << std::endl;
	std::cout << m_spell_description << std::endl;
}