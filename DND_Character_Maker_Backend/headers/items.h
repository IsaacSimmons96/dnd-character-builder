#pragma once
#include "typedefs.h"
#include "combat_and_item_enums.h"
#include "dice_functions.h"
#include "cash.h"
#include <vector>

namespace dmg
{
	struct DAMAGE
	{
		DAMAGE_TYPE m_damage_type{ DAMAGE_TYPE::INVALID };
		DND_DICE m_dice{ DND_DICE::INVALID };
		uint16_t m_number_of_dice{ 0 };
	};
}

class ITEM_BASE
{
public:
	ITEM_BASE( string name, const CASH& cost, double weight, bool include_in_shop );

	virtual void print() const = 0;
	string get_name() const { return m_item_name; };
	CASH get_cost() const { return m_item_cost; };
	bool is_in_shop() const { return m_in_shop; };

protected:

	string m_item_name;
	CASH m_item_cost;
	double m_weight;
	bool m_in_shop;
};

class ITEM : public ITEM_BASE
{
public:
	ITEM( string name, CASH cost, double weight, bool include_in_shop = true );
	bool operator == ( const ITEM &item_in );
	virtual void print() const override;
};

class WEAPON : public ITEM
{
public:
	WEAPON( string name, CASH cost, double weight, bool include_in_shop,
			dmg::DAMAGE damage, bool is_versatile, dmg::DAMAGE vers_damage, WEAPON_TYPE type,
			WEAPON_PROFICIENCY weap_prof, std::vector<WEAPON_PROPERTIES> properties,
			uint16_t min_range, uint16_t max_range );

	void print() const override;

private:
	dmg::DAMAGE m_damage;
	dmg::DAMAGE m_versatile_damage;
	WEAPON_TYPE m_type;
	WEAPON_PROFICIENCY m_weapon_prof;
	std::vector<WEAPON_PROPERTIES> m_properties;
	uint16_t m_min_range;
	uint16_t m_max_range;
	bool m_versatile;
};

class ARMOUR : public ITEM
{
public:
	ARMOUR( string name, CASH cost, double weight, bool include_in_shop, ARMOR_CATEGORY type, bool stealth_dis, bool dex_mod_bonus, bool dex_cap, uint16_t ac, uint16_t strength_needed );

	void print() const override;

private:
	ARMOR_CATEGORY m_armor_type{ ARMOR_CATEGORY::INVALID };
	bool m_stealth_disadvantage{ false };
	bool m_add_dexterity_modifier{ false };
	bool m_dex_cap_at_2{ false };
	uint16_t m_armor_class{ 0 };
	uint16_t m_strength_needed{ 0 };
};

class PACK : public ITEM
{
public:
	PACK( string name, CASH cost, double weight, std::vector<ITEM*> items, bool include_in_shop = true );
	void print_items() const;
	void print() const override;

private:
	std::vector<ITEM*> m_items;
};
