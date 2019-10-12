#include "..\headers\trait_spell.h"
#include <iostream>

TRAIT_SPELL::TRAIT_SPELL( string name, string desc )
{
	m_spell_description = desc;
	m_spell_name = name;
}

TRAIT_SPELL::~TRAIT_SPELL()
{
}

void TRAIT_SPELL::set_spell_description( string spell_description )
{
	m_spell_description = spell_description;
}

string TRAIT_SPELL::get_spell_description()
{
	return m_spell_description;
}

void TRAIT_SPELL::print_spell() const
{
	std::cout << m_spell_name << std::endl;
	std::cout << m_spell_description << std::endl;
}