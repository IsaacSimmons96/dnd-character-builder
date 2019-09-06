#pragma once
#include "dnd_character.h"

namespace UI_FUNCTION
{
	void select_character_race( const DND_CHARACTER& character, DND_RACE race );
	void select_character_skill_proficiency( const DND_CHARACTER& character, DND_SKILL_TYPE skill );
	void select_character_tool_proficiency( const DND_CHARACTER& character, DND_TOOL_PROFICIENCY tool );
}