#include "..\headers\item_manager.h"

#include "..\headers\dnd_character_utilities.h"
#include "..\headers\item_utilities.h"
#include <fstream>
#include <iosfwd>
#include <sstream>

ITEM_MANAGER::~ITEM_MANAGER()
{
	m_items.clear();
	m_armour.clear();
	m_weapons.clear();
}

void ITEM_MANAGER::read_in_all()
{
	read_in_items();
	read_in_weapons();
	read_in_armour();
}

void ITEM_MANAGER::refresh_items()
{
	m_items.clear();
	m_armour.clear();
	m_weapons.clear();
	read_in_all();
}

ITEM* ITEM_MANAGER::get_item( string item_name )
{
	if ( m_items.size() <= 0 )
	{
		read_in_all();
	}

	ITEM* found_item = m_items.find( item_name )->second;
	return found_item;
}

ARMOUR* ITEM_MANAGER::get_armour( string item_name )
{
	if ( m_armour.size() <= 0 )
	{
		read_in_armour();
	}

	ARMOUR* found_item = m_armour.find( item_name )->second;
	return found_item;
}

WEAPON* ITEM_MANAGER::get_weapon( string item_name )
{
	if ( m_weapons.size() <= 0 )
	{
		read_in_weapons();
	}

	WEAPON* found_item = m_weapons.find( item_name )->second;
	return found_item;
}

void ITEM_MANAGER::print_all_items()
{
	if ( m_items.size() <= 0 )
	{
		read_in_all();
	}

	for ( auto it = m_items.begin(); it != m_items.end(); ++it )
	{
		it->second->print_item();
	}
}

void ITEM_MANAGER::read_in_items()
{
	std::ifstream file( m_file_items );
	string value, temp;
	std::stringstream ss;
	u_int uint_temp;

	auto convert_string_to_int = [&]()
	{
		std::stringstream num_stringstream( temp );
		num_stringstream >> uint_temp;
	};

	while ( getline( file, value ) )
	{
		ss << value;

		getline( ss, temp, ';' );
		const string item_name = temp;

		getline( ss, temp, ';' );
		convert_string_to_int();
		const u_int cost = uint_temp;

		getline( ss, temp, ';' );
		convert_string_to_int();
		const u_int weight = uint_temp;

		const auto new_item = new ITEM( item_name, cost, weight );

		m_items.insert( std::make_pair( item_name, new_item ) );

		ss.clear();
	}
}

void ITEM_MANAGER::read_in_weapons()
{
	std::ifstream file( m_file_weapons );
	string value, temp;
	std::stringstream ss;
	u_int uint_temp;
	u_int8 uint8_temp;

	auto convert_string_to_int = [&]()
	{
		std::stringstream num_stringstream( temp );
		num_stringstream >> uint_temp;
	};

	auto convert_string_to_u_int8 = [&]()
	{
		std::stringstream num_stringstream( temp );
		num_stringstream >> uint_temp;
	};

	while ( getline( file, value ) )
	{
		auto create_damage = [&]()
		{
			getline( ss, temp, ';' );
			const DAMAGE_TYPE dmg_type = ITEM_AND_COMBAT_UTILITIES::get_DAMAGE_TYPE_from_string( temp );

			getline( ss, temp, ';' );
			const DND_DICE dice_type = get_DND_DICE_from_string( temp );

			getline( ss, temp, ';' );
			convert_string_to_u_int8();
			const u_int8 ammount = uint8_temp;

			dmg::DAMAGE weapon_damage;
			weapon_damage.m_damage_type = dmg_type;
			weapon_damage.m_dice = dice_type;
			weapon_damage.m_number_of_dice = ammount;

			return weapon_damage;
		};

		ss << value;

		getline( ss, temp, ';' );
		const string item_name = temp;

		getline( ss, temp, ';' );
		convert_string_to_int();
		const u_int cost = uint_temp;

		getline( ss, temp, ';' );
		convert_string_to_int();
		const u_int weight = uint_temp;

		auto damage_type_main = create_damage();
		auto damage_type_vers = create_damage();

		getline( ss, temp, ';' );
		const WEAPON_TYPE weapon_type = ITEM_AND_COMBAT_UTILITIES::get_WEAPON_TYPE_from_string( temp );

		getline( ss, temp, ';' );
		const WEAPON_PROFICIENCY weapon_prof = ITEM_AND_COMBAT_UTILITIES::get_WEAPON_PROFICIENCY_from_string( temp );

		u_int min_range(0);
		u_int max_range(0);
		if ( weapon_type == WEAPON_TYPE::RANGED )
		{
			getline( ss, temp, ';' );
			convert_string_to_int();
			min_range = uint_temp;

			getline( ss, temp, ';' );
			convert_string_to_int();
			max_range = uint_temp;
		}

		std::vector<WEAPON_PROPERTIES> props;
		while ( getline( ss, temp, ';' ) )
		{
			const WEAPON_PROPERTIES prop = ITEM_AND_COMBAT_UTILITIES::get_WEAPON_PROPERTIES_from_string( temp );
			props.push_back( prop );
		}

		const auto new_weapon = new WEAPON( item_name, cost, weight, damage_type_main, damage_type_vers, weapon_type, weapon_prof, props, min_range, max_range );
		const auto new_weapon_item = dynamic_cast<ITEM*>(new_weapon);

		m_weapons.insert( std::make_pair( item_name, new_weapon ) );
		m_items.insert( std::make_pair( item_name, new_weapon_item ) );
		ss.clear();
	}
}

void ITEM_MANAGER::read_in_armour()
{
	std::ifstream file( m_file_armour );
	string value, temp;
	std::stringstream ss;
	u_int uint_temp;

	auto convert_string_to_int = [&]()
	{
		std::stringstream num_stringstream( temp );
		num_stringstream >> uint_temp;
	};

	while ( getline( file, value ) )
	{
		ss << value;

		getline( ss, temp, ';' );
		const string item_name = temp;

		getline( ss, temp, ';' );
		convert_string_to_int();
		const u_int cost = uint_temp;

		getline( ss, temp, ';' );
		convert_string_to_int();
		const u_int weight = uint_temp;

		getline( ss, temp, ';' );
		const ARMOR_CATEGORY category = ITEM_AND_COMBAT_UTILITIES::get_ARMOR_CATEGORY_from_string( temp );

		getline( ss, temp, ';' );
		const bool stealth_dis = temp == "TRUE";

		getline( ss, temp, ';' );
		const bool dex_mod_bonus = temp == "TRUE";

		getline( ss, temp, ';' );
		const bool dex_cap = temp == "TRUE";

		getline( ss, temp, ';' );
		convert_string_to_int();
		const u_int base_AC = uint_temp;

		getline( ss, temp, ';' );
		convert_string_to_int();
		const u_int str_needed = uint_temp;
		

		const auto new_armour = new ARMOUR( item_name, cost, weight, category, stealth_dis, dex_mod_bonus, dex_cap, base_AC, str_needed );
		const auto new_armour_item = dynamic_cast<ITEM*>(new_armour);

		m_armour.insert( std::make_pair( item_name, new_armour ) );
		m_items.insert( std::make_pair( item_name, new_armour_item ) );

		ss.clear();
	}
}
