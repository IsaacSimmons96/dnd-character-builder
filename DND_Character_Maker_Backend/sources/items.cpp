#include "..\headers\items.h"
#include "..\headers\typedefs.h"
#include "..\headers\item_utilities.h"
#include "..\headers\dice_functions.h"
#include <iostream>
#include <vector>

ITEM_BASE::ITEM_BASE( string name, const CASH& cost, double weight, bool include_in_shop )
{
	m_item_name = name;
	m_item_cost = cost;
	m_weight = weight;
	m_in_shop = include_in_shop;
}

void ITEM_BASE::print() const
{
	std::cout << m_item_name << std::endl;
	std::cout << "Cost: ";
	m_item_cost.print();
	std::cout << std::endl;
	std::cout << "Weight: " << std::to_string( m_weight ) << std::endl;
}

ITEM::ITEM( string name,CASH cost, double weight, bool include_in_shop ) : ITEM_BASE( name, cost, weight, include_in_shop /*= true*/ )
{}

bool ITEM::operator==( const ITEM & item_in )
{
	return m_item_name == item_in.get_name() && m_item_cost == item_in.m_item_cost && m_weight == item_in.m_weight;
}

void ITEM::print() const
{
	ITEM_BASE::print();
}

WEAPON::WEAPON( string name,CASH cost, double weight, bool include_in_shop, dmg::DAMAGE damage, bool is_versatile, dmg::DAMAGE vers_damage, WEAPON_TYPE type, WEAPON_PROFICIENCY weap_prof,
				std::vector<WEAPON_PROPERTIES> properties, uint16_t min_range, uint16_t max_range ) : ITEM_BASE( name, cost, weight, include_in_shop )
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

void WEAPON::print() const
{
	ITEM_BASE::print();
	std::cout << "Damage: " << std::to_string( m_damage.m_number_of_dice ) << " " << get_string_from_DND_DICE( m_damage.m_dice ) << " " << ITEM_AND_COMBAT_UTILITIES::get_string_from_DAMAGE_TYPE( m_damage.m_damage_type ) << std::endl;
}

ARMOUR::ARMOUR( string name,CASH cost, double weight, bool include_in_shop, ARMOR_CATEGORY type, bool stealth_dis, bool dex_mod_bonus, bool dex_cap, uint16_t ac, uint16_t strength_needed )
	: ITEM_BASE( name, cost, weight, include_in_shop )
{
	m_armor_type = type;
	m_stealth_disadvantage = stealth_dis;
	m_add_dexterity_modifier = dex_mod_bonus;
	m_dex_cap_at_2 = dex_cap;
	m_armor_class = ac;
	m_strength_needed = strength_needed;
}

void ARMOUR::print() const
{
	ITEM_BASE::print();
}

PACK::PACK( string name, CASH cost, double weight, std::vector<ITEM*> items, bool include_in_shop /*= true*/ )
	: ITEM_BASE( name, cost, weight, include_in_shop )
{
	m_items = items;
}

void PACK::print() const
{
	ITEM_BASE::print();
	std::cout << "Items In Pack:" << std::endl;
	std::cout << "***************************************************" << std::endl;
	std::cout << std::endl;

	for ( auto item : m_items )
	{
		item->print();
		std::cout << std::endl;
	}

	std::cout << "***************************************************" << std::endl;
}
