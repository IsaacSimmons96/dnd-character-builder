#include "..\headers\items.h"
#include "..\headers\typedefs.h"
#include <vector>
#include <iostream>

ITEM_BASE::ITEM_BASE( string name, u_int cost, u_int weight )
{
	m_item_name = name;
	m_item_cost = cost;
	m_weight = weight;
}


void ITEM_BASE::print_item() const
{
	std::cout << m_item_name << std::endl;
	std::cout << "Cost: " << std::to_string( m_item_cost ) << std::endl;
	std::cout << "Weight: " << std::to_string( m_weight ) << std::endl;
}

ITEM::ITEM( string name, u_int cost, u_int weight ) : ITEM_BASE( name, cost, weight )
{}

void ITEM::print_item() const
{

}

WEAPON::WEAPON( string name, u_int cost, u_int weight, dmg::DAMAGE damage, dmg::DAMAGE vers_damage, WEAPON_TYPE type, WEAPON_PROFICIENCY weap_prof,
				std::vector<WEAPON_PROPERTIES> properties, u_int min_range, u_int max_range ) : ITEM_BASE( name, cost, weight )
{
	m_damage = damage;
	m_versatile_damage = vers_damage;
	m_type = type;
	m_weapon_prof = weap_prof;

	for ( auto prop : properties )
	{
		m_properties.push_back( prop );
	}

	m_min_range = min_range;
	m_max_range = max_range;
}

void WEAPON::print_item() const
{
	std::cout << m_item_name << std::endl;
	std::cout << "Cost: " << std::to_string( m_item_cost ) << std::endl;
	std::cout << "Weight: " << std::to_string( m_weight ) << std::endl;
}
