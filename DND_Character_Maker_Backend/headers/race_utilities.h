#pragma once
#include "character_enums.h"
#include <vector>

class RACE_UTILITIES
{
public:
	static std::vector<DND_LANGUAGE>			get_languages_from_race( DND_RACE race );
	static std::vector<DND_TOOL_PROFICIENCY>	get_tool_profs_from_race( DND_RACE race );

private:
	RACE_UTILITIES();
	~RACE_UTILITIES();
};
