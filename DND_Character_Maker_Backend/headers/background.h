#pragma once

#include "typedefs.h"
#include "..\headers\character_enums.h"
#include "..\headers\items.h"
#include <map>

class BACKGROUND
{
public:
	BACKGROUND();
	~BACKGROUND();

	std::vector< DND_SKILL > get_skill_profs(){ return m_skill_profs; };
	std::vector< DND_TOOL > get_tool_profs(){ return m_tool_profs; };
	std::vector< DND_LANGUAGE > get_languages(){ return m_languages; };
	std::vector< ITEM* > get_equipment(){ return m_equipment; };
	std::vector< ITEM* > get_choice_items();

private:
	string m_name{};
	std::vector< DND_SKILL > m_skill_profs;
	std::vector< DND_TOOL > m_tool_profs;
	std::vector< DND_LANGUAGE > m_languages;
	std::vector< ITEM* > m_equipment;
	std::map<string, std::pair< std::vector< ITEM* >, std::vector< ITEM* > > > m_equipment_choices;
	DND_BACKGROUND m_type;
};

