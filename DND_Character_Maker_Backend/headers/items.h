#pragma once
#include "typedefs.h"
#include "combat_and_item_enums.h"
#include "dice_functions.h"
#include <vector>

namespace dmg
{
	struct DAMAGE
	{
		DAMAGE_TYPE m_damage_type{ DAMAGE_TYPE::INVALID };
		DND_DICE m_dice{ DND_DICE::D4 };
		u_int8 m_number_of_dice{ 0 };
	};
}

class ITEM_BASE
{
public:
	ITEM_BASE( string name, u_int cost, u_int weight );

	virtual void print_item() const = 0;
	string get_name() const { return m_item_name; };

protected:

	string m_item_name;
	// TODO make proper DND currency
	u_int m_item_cost;
	// TODO add proper units of weight
	u_int m_weight;
};

class ITEM : ITEM_BASE
{
public:
	ITEM( string name, u_int cost, u_int weight );
	virtual void print_item() const override;
	string get_name() const { return m_item_name; };
};

class WEAPON : ITEM_BASE
{
public:
	WEAPON( string name, u_int cost, u_int weight,
			dmg::DAMAGE damage, dmg::DAMAGE vers_damage, WEAPON_TYPE type,
			WEAPON_PROFICIENCY weap_prof, std::vector<WEAPON_PROPERTIES> properties,
			u_int min_range, u_int max_range );

	void print_item() const override;
	string get_name() const { return m_item_name; };

private:
	dmg::DAMAGE m_damage;
	dmg::DAMAGE m_versatile_damage;
	WEAPON_TYPE m_type;
	WEAPON_PROFICIENCY m_weapon_prof;
	std::vector<WEAPON_PROPERTIES> m_properties;
	u_int m_min_range;
	u_int m_max_range;
};

class ARMOR : ITEM_BASE
{
public:
	ARMOR( string name, u_int cost, u_int weight, ARMOR_CATEGORY type, bool stealth_dis, bool dex_mod_bonus, bool dex_cap, u_int ac, u_int strength_needed );

	void print_item() const override;
	string get_name() const { return m_item_name; };

private:
	ARMOR_CATEGORY m_armor_type{ ARMOR_CATEGORY::INVALID };
	bool m_stealth_disadvantage{ false };
	bool m_add_dexterity_modifier{ false };
	bool m_dex_cap_at_2{ false };
	u_int m_armor_class{ 0 };
	u_int m_strength_needed{ 0 };
};
