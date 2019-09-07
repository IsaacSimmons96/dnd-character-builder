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
	ITEM_BASE::print_item();
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
	ITEM_BASE::print_item();
	std::cout << m_item_name << std::endl;
	std::cout << "Cost: " << std::to_string( m_item_cost ) << std::endl;
	std::cout << "Weight: " << std::to_string( m_weight ) << std::endl;
}

ARMOR::ARMOR( string name, u_int cost, u_int weight, ARMOR_CATEGORY type, bool stealth_dis, bool dex_mod_bonus, bool dex_cap, u_int ac, u_int strength_needed )
	: ITEM_BASE( name, cost, weight )
{
	m_armor_type = type;
	m_stealth_disadvantage = stealth_dis;
	m_add_dexterity_modifier = dex_mod_bonus;
	m_dex_cap_at_2 = dex_cap;
	m_armor_class = ac;
	m_strength_needed = strength_needed;
}

void ARMOR::print_item() const
{
	ITEM_BASE::print_item();
	std::cout << m_item_name << std::endl;
}
