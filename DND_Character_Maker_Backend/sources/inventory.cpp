#include "..\headers\inventory.h"

INVENTORY::INVENTORY()
{
}

INVENTORY::~INVENTORY()
{
}

std::vector< ITEM*> INVENTORY::get_all_items() const
{
	return m_items;
}

std::vector< const ITEM*> INVENTORY::get_items( string item_name ) const
{
	std::vector< const ITEM*> items;
	if ( m_items.size() > 0 )
	{
		for ( const auto& item : m_items )
		{
			if ( item && item->get_name() == item_name )
			{
				items.push_back( item );
			}
		}
	}
	return items;
}

const ITEM* INVENTORY::get_item( string item_name ) const
{
	if ( m_items.size() > 0 )
	{
		for ( const auto& item : m_items )
		{
			if ( item->get_name() == item_name )
			{
				return item;
			}
		}
	}
	return nullptr;
}

const WEAPON* INVENTORY::get_weapon( string item_name ) const
{
	if ( m_items.size() > 0 )
	{
		for ( const auto& item : m_items )
		{
			if ( item->get_name() == item_name )
			{
				const WEAPON* weap = dynamic_cast<WEAPON*>(item);
				if ( weap )
				{
					return weap;
				}
			}
		}
	}
	return nullptr;
}

std::vector<const WEAPON*> INVENTORY::get_weapons() const
{
	std::vector< const WEAPON*> weapons;
	if ( m_items.size() > 0 )
	{
		for ( const auto& item : m_items )
		{
			const WEAPON* weap = dynamic_cast<WEAPON*>(item);
			if ( weap )
			{
				weapons.push_back( weap );
			}
		}
	}
	return weapons;
}

const ARMOUR* INVENTORY::get_armour( string item_name ) const
{
	if ( m_items.size() > 0 )
	{
		for ( const auto& item : m_items )
		{
			if ( item->get_name() == item_name )
			{
				const ARMOUR* armour = dynamic_cast<ARMOUR*>(item);
				if ( armour )
				{
					return armour;
				}
			}
		}
	}
	return nullptr;
}

std::vector< const ARMOUR*> INVENTORY::get_armour() const
{
	std::vector< const ARMOUR*> armour;
	if ( m_items.size() > 0 )
	{
		for ( const auto& item : m_items )
		{
			const ARMOUR* armour_item = dynamic_cast<ARMOUR*>(item);
			if ( armour_item )
			{
				armour.push_back( armour_item );
			}
		}
	}
	return armour;
}

std::vector< const PACK*> INVENTORY::get_packs() const
{
	std::vector<const PACK*> packs;
	if ( m_items.size() > 0 )
	{
		for ( const auto& item : m_items )
		{
			const PACK* pack = dynamic_cast<PACK*>(item);
			if ( pack )
			{
				packs.push_back( pack );
			}
		}
	}
	return packs;
}

const PACK* INVENTORY::get_pack( string item_name ) const
{
	if ( m_items.size() > 0 )
	{
		for ( const auto& item : m_items )
		{
			if ( item->get_name() == item_name )
			{
				const PACK* pack = dynamic_cast<PACK*>(item);
				if ( pack )
				{
					return pack;
				}
			}
		}
	}
	return nullptr;
}

uint64_t INVENTORY::get_inventory_count() const
{
	uint64_t count( 0 );
	if ( m_items.size() > 0 )
	{
		for ( const auto& item : m_items )
		{
			count++;
		}
	}
	return count;
}

uint64_t INVENTORY::get_item_count( const ITEM * item ) const
{
	uint64_t count( 0 );
	if ( m_items.size() > 0 )
	{
		for ( const auto& found_item : m_items )
		{
			if ( found_item == item )
			{
				count++;
			}
		}
	}
	return count;
}

void INVENTORY::add_item( ITEM * item )
{
	if ( item )
	{
		m_items.push_back( item );
	}
}

void INVENTORY::add_items( const std::vector<ITEM*> items_in )
{
	if ( items_in.size() > 0 )
	{
		for ( const auto& item : items_in )
		{
			if ( item )
			{
				m_items.push_back( item );
			}
		}
	}
}

void INVENTORY::remove_item( const ITEM* item )
{
	if ( m_items.size() > 0 )
	{
		for ( auto it = m_items.begin(); it != m_items.end(); it++ )
		{
			if ( (*it) == item )
			{
				m_items.erase( it-- );
				return;
			}
		}
	}
}

void INVENTORY::remove_items( const ITEM* item )
{
	if ( m_items.size() > 0 )
	{
		for ( auto it = m_items.begin(); it != m_items.end(); it++ )
		{
			if ( (*it) == item )
			{
				m_items.erase( it-- );
			}
		}
	}
}

void INVENTORY::print() const
{
	for ( const auto& item : m_items )
	{
		item->print();
	}
}

void INVENTORY::print_cash() const
{
	m_cash.print();
}

bool INVENTORY::has_item( const ITEM * item ) const
{
	if ( m_items.size() > 0 )
	{
		for ( const auto& item_found : m_items )
		{
			if ( item_found == item )
			{
				return true;
			}
		}
	}
	return false;
}

bool INVENTORY::is_empty() const
{
	return m_items.size() == 0;
}

bool INVENTORY::has_items() const
{
	return m_items.size() > 0;
}

void INVENTORY::subtract_cash( const CASH& subtraction_cash )
{
	m_cash -= subtraction_cash;
}

void INVENTORY::add_cash( const CASH& subtraction_cash )
{
	m_cash += subtraction_cash;
}

bool INVENTORY::can_afford_item( const ITEM * item ) const
{
	return m_cash >= item->get_cost();
}
