#include "..\headers\items.h"
#include "..\headers\typedefs.h"
#include <vector>
#include <iostream>
#include "..\headers\item_utilities.h"
#include "..\headers\dice_functions.h"

ITEM_BASE::ITEM_BASE( string name, uint16_t cost, uint16_t weight )
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

ITEM::ITEM( string name, uint16_t cost, uint16_t weight ) : ITEM_BASE( name, cost, weight )
{}

void ITEM::print_item() const
{
	ITEM_BASE::print_item();
}

WEAPON::WEAPON( string name, uint16_t cost, uint16_t weight, dmg::DAMAGE damage, dmg::DAMAGE vers_damage, WEAPON_TYPE type, WEAPON_PROFICIENCY weap_prof,
				std::vector<WEAPON_PROPERTIES> properties, uint16_t min_range, uint16_t max_range ) : ITEM_BASE( name, cost, weight )
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
	std::cout << "Damage: " << std::to_string( m_damage.m_number_of_dice ) << " " << get_string_from_DND_DICE( m_damage.m_dice ) << " " << ITEM_AND_COMBAT_UTILITIES::get_string_from_DAMAGE_TYPE( m_damage.m_damage_type ) << std::endl;
}

ARMOUR::ARMOUR( string name, uint16_t cost, uint16_t weight, ARMOR_CATEGORY type, bool stealth_dis, bool dex_mod_bonus, bool dex_cap, uint16_t ac, uint16_t strength_needed )
	: ITEM_BASE( name, cost, weight )
{
	m_armor_type = type;
	m_stealth_disadvantage = stealth_dis;
	m_add_dexterity_modifier = dex_mod_bonus;
	m_dex_cap_at_2 = dex_cap;
	m_armor_class = ac;
	m_strength_needed = strength_needed;
}

void ARMOUR::print_item() const
{
	ITEM_BASE::print_item();
	std::cout << m_item_name << std::endl;
}