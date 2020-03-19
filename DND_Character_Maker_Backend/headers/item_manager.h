#pragma once

#include "items.h"
#include <map>
#include "typedefs.h"
#include "character_enums.h"

class ITEM_MANAGER
{
public:
	~ITEM_MANAGER();

	void print();
	void refresh_items();

	ITEM* get_item( string search );
	ARMOUR* get_armour( string search );
	WEAPON* get_weapon( string search );
	PACK * get_pack( string item_name );

private:
	std::map<string, ITEM*> m_items;
	std::map<string, WEAPON*> m_weapons;
	std::map<string, ARMOUR*> m_armour;
	std::map<string, PACK*> m_packs;

	const char m_file_items[89]{ "C:/Users/Isaac/Documents/dnd-character-builder/DND_Character_Maker_Backend/csv/items.csv" };
	const char m_file_weapons[93]{ "C:/Users/Isaac/Documents/dnd-character-builder/DND_Character_Maker_Backend/csv/weapons.csv" };
	const char m_file_armour[91]{ "C:/Users/Isaac/Documents/dnd-character-builder/DND_Character_Maker_Backend/csv/armour.csv" };
	const char m_file_packs[89]{ "C:/Users/Isaac/Documents/dnd-character-builder/DND_Character_Maker_Backend/csv/packs.csv" };

	void read_in_all();
	void read_in_items();
	void read_in_weapons();
	void read_in_armour();
	void read_in_packs();
};