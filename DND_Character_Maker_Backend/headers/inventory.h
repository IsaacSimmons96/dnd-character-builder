#pragma once
#include "typedefs.h"
#include "items.h"

class INVENTORY
{
public:
	INVENTORY();
	~INVENTORY();

	std::vector< ITEM* >			get_all_items() const;
	std::vector< const ITEM* >		get_items( string item_name ) const;
	const ITEM*						get_item( string item_name ) const;

	const WEAPON*					get_weapon( string item_name ) const;
	std::vector< const WEAPON* >	get_weapons() const;

	const ARMOUR*					get_armour( string item_name ) const;
	std::vector< const ARMOUR* >	get_armour() const;

	const PACK*						get_pack( string item_name ) const;
	std::vector< const PACK* >		get_packs() const;

	uint64_t get_inventory_count() const;
	uint64_t get_item_count( const ITEM* item ) const;

	void add_item( ITEM* item );
	void add_items( const std::vector< ITEM* > items_in );
	void remove_item( const ITEM* item );
	void remove_items( const ITEM * item );
	
	void print() const;
	void print_cash() const;

	bool has_item( const ITEM* item ) const;
	bool is_empty() const;
	bool has_items() const;

	void subtract_cash( const CASH& subtraction_cash );
	void add_cash( const CASH& subtraction_cash );
	bool can_afford_item( const ITEM* item ) const;

private:
	CASH m_cash;
	std::vector< ITEM* > m_items;
};

