#include "..\headers\background.h"
#include "..\headers\items.h"
#include "..\headers\generic_utilities.h"
#include <iostream>

BACKGROUND::BACKGROUND()
{
}

BACKGROUND::~BACKGROUND()
{
}

std::vector< ITEM* > BACKGROUND::get_choice_items()
{
	std::vector< ITEM* > items_to_add;

	auto print_items = []( std::vector< ITEM* > items_to_print )
	{
		string string_out;
		size_t i;
		for ( auto item : items_to_print )
		{
			string_out += i == items_to_print.size() ? item->get_name() + "." : string_out += item->get_name() + ", ";
			i++;
		}
		return string_out;
	};

	for ( auto choices : m_equipment_choices )
	{
		bool chosen = false;
		while ( !chosen )
		{
			string question = "Choose between: A) " + print_items( choices.second.first ) + " OR  B) " + print_items( choices.second.second );

			string temp;
			ask_for_input( question, temp );

			if ( temp == "a" || temp == "b" )
			{
				auto items = temp == "a" ? choices.second.first : choices.second.second;
				std::copy( items.begin(), items.end(), std::back_inserter( items_to_add ) );
				chosen = true;
			}
			else
			{
				print( "Invalid choice. Please try again." );
			}
		}
	}

	return items_to_add;
}
