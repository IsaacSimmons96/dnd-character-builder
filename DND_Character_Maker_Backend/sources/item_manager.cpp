#include "..\headers\item_manager.h"

#include "..\headers\dnd_character_utilities.h"
#include "..\headers\item_utilities.h"
#include <fstream>
#include <iosfwd>
#include <sstream>

#include <cstring>

ITEM_MANAGER::~ITEM_MANAGER()
{
	m_items.clear();
	m_armour.clear();
	m_weapons.clear();
	m_packs.clear();
}

void ITEM_MANAGER::read_in_all()
{
	read_in_items();
	read_in_weapons();
	read_in_armour();
	read_in_packs();
}

void ITEM_MANAGER::refresh_items()
{
	m_items.clear();
	m_armour.clear();
	m_weapons.clear();
	m_packs.clear();
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

PACK* ITEM_MANAGER::get_pack( string item_name )
{
	if ( m_items.size() <= 0 )
	{
		read_in_all();
	}

	PACK* found_item = m_packs.find( item_name )->second;
	return found_item;
}

void ITEM_MANAGER::print()
{
	if ( m_items.size() <= 0 )
	{
		read_in_all();
	}

	for ( auto it = m_items.begin(); it != m_items.end(); ++it )
	{
		it->second->print();
	}
}

void ITEM_MANAGER::read_in_items()
{
	std::ifstream file( m_file_items );
	string value, temp;
	std::stringstream ss;
	int64_t int64_in;

	auto convert_string_to_int = [&]()
	{
		std::stringstream num_stringstream( temp );
		num_stringstream >> int64_in;
	};

	while ( getline( file, value ) )
	{
		ss << value;

		getline( ss, temp, ';' );
		const string item_name = temp;

		getline( ss, temp, ';' );
		convert_string_to_int();
		const money gold( CASH_TYPE::GOLD, int64_in );

		getline( ss, temp, ';' );
		convert_string_to_int();
		const money silver( CASH_TYPE::SILVER, int64_in );

		getline( ss, temp, ';' );
		convert_string_to_int();
		const money copper( CASH_TYPE::COPPER, int64_in );

		getline( ss, temp, ';' );
		uint16_t weight;
		std::stringstream num_stringstream( temp );
		num_stringstream >> weight;

		getline( ss, temp, ';' );
		const bool in_shop = temp == "TRUE";

		const auto new_item = new ITEM( item_name, CASH( gold, silver, copper ), weight, in_shop );

		m_items.insert( std::make_pair( item_name, new_item ) );

		ss.clear();
	}
}

void ITEM_MANAGER::read_in_weapons()
{
	std::ifstream file( m_file_weapons );
	string value, temp;
	std::stringstream ss;
	uint16_t uint_temp;
	uint8_t uint8_temp;

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

	auto create_money = [&]( CASH_TYPE type )
	{
		int64_t int64_in;
		std::stringstream num_stringstream( temp );
		num_stringstream >> int64_in;

		return money( type, int64_in );
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
			const uint8_t ammount = uint8_temp;

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
		const money gold = create_money( CASH_TYPE::GOLD );

		getline( ss, temp, ';' );
		const money silver = create_money( CASH_TYPE::SILVER );

		getline( ss, temp, ';' );
		const money copper = create_money( CASH_TYPE::COPPER );

		getline( ss, temp, ';' );
		convert_string_to_int();
		const uint16_t weight = uint_temp;

		getline( ss, temp, ';' );
		const bool in_shop = temp == "TRUE";

		auto damage_type_main = create_damage();

		getline( ss, temp, ';' );
		const bool is_versatile = temp == "TRUE";

		dmg::DAMAGE damage_type_vers;
		if ( is_versatile )
		{
			damage_type_vers = create_damage();
		}

		getline( ss, temp, ';' );
		const WEAPON_TYPE weapon_type = ITEM_AND_COMBAT_UTILITIES::get_WEAPON_TYPE_from_string( temp );

		getline( ss, temp, ';' );
		const WEAPON_PROFICIENCY weapon_prof = ITEM_AND_COMBAT_UTILITIES::get_WEAPON_PROFICIENCY_from_string( temp );

		uint16_t min_range( 0 );
		uint16_t max_range( 0 );
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

		const auto new_weapon = new WEAPON( item_name, CASH( gold, silver, copper ), weight, in_shop, damage_type_main, is_versatile, damage_type_vers, weapon_type, weapon_prof, props, min_range, max_range );
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
	uint16_t uint_temp;

	auto convert_string_to_int = [&]()
	{
		std::stringstream num_stringstream( temp );
		num_stringstream >> uint_temp;
	};

	auto create_money = [&]( CASH_TYPE type )
	{
		int64_t int64_in;
		std::stringstream num_stringstream( temp );
		num_stringstream >> int64_in;

		return money( type, int64_in );
	};

	while ( getline( file, value ) )
	{
		ss << value;

		getline( ss, temp, ';' );
		const string item_name = temp;

		getline( ss, temp, ';' );
		const money gold = create_money( CASH_TYPE::GOLD );

		getline( ss, temp, ';' );
		const money silver = create_money( CASH_TYPE::SILVER );

		getline( ss, temp, ';' );
		const money copper = create_money( CASH_TYPE::COPPER );

		getline( ss, temp, ';' );
		convert_string_to_int();
		const uint16_t weight = uint_temp;

		getline( ss, temp, ';' );
		const bool in_shop = temp == "TRUE";

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
		const uint16_t base_AC = uint_temp;

		getline( ss, temp, ';' );
		convert_string_to_int();
		const uint16_t str_needed = uint_temp;


		const auto new_armour = new ARMOUR( item_name, CASH( gold, silver, copper ), weight, in_shop, category, stealth_dis, dex_mod_bonus, dex_cap, base_AC, str_needed );
		const auto new_armour_item = dynamic_cast<ITEM*>(new_armour);

		m_armour.insert( std::make_pair( item_name, new_armour ) );
		m_items.insert( std::make_pair( item_name, new_armour_item ) );

		ss.clear();
	}
}

void ITEM_MANAGER::read_in_packs()
{
	std::ifstream file( m_file_packs );
	string value, temp;
	std::stringstream ss;
	int64_t int64_in;

	auto convert_string_to_int = [&]()
	{
		std::stringstream num_stringstream( temp );
		num_stringstream >> int64_in;
	};

	auto is_number = [&]( const string& s )
	{
		std::string::const_iterator it = s.begin();
		while ( it != s.end() && std::isdigit( *it ) ) ++it;
		return !s.empty() && it == s.end();
	};

	while ( getline( file, value ) )
	{
		ss << value;

		getline( ss, temp, ';' );
		const string item_name = temp;

		getline( ss, temp, ';' );
		convert_string_to_int();
		const money gold( CASH_TYPE::GOLD, int64_in );

		getline( ss, temp, ';' );
		convert_string_to_int();
		const money silver( CASH_TYPE::SILVER, int64_in );

		getline( ss, temp, ';' );
		convert_string_to_int();
		const money copper( CASH_TYPE::COPPER, int64_in );

		std::vector<ITEM*> items;
		int64_t number_of_item = 1;
		bool has_just_added_item = false;

		while ( getline( ss, temp, ';' ) )
		{
			if ( has_just_added_item )
			{
				number_of_item = 1;
			}

			if ( is_number( temp ) )
			{
				convert_string_to_int();
				number_of_item = int64_in;
				has_just_added_item = false;
				break;
			}

			auto item = get_item( temp );
			for ( int64_t i = 0; i < number_of_item; i++ )
			{
				items.push_back( item );
			}

			has_just_added_item = true;
		}

		const auto new_pack = new PACK( item_name, CASH( gold, silver, copper ), 0, items );
		const auto new_item = dynamic_cast<ITEM*>(new_pack);

		m_packs.insert( std::make_pair( item_name, new_pack ) );
		m_items.insert( std::make_pair( item_name, new_item ) );

		ss.clear();
	}
}

