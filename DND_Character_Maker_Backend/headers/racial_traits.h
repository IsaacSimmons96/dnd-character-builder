#pragma once

#include "character_enums.h"
#include "trait_spell.h"
#include "typedefs.h"
#include <vector>
#include "ability_score_bonus.h"

class RACIAL_TRAITS
{
public:
	RACIAL_TRAITS( DND_RACE race, u_int age, u_int speed, string align_desc, DND_SIZE size, std::vector<DND_LANGUAGE> langs, std::vector<DND_TOOL> tool_profs,
				   std::vector<TRAIT_SPELL*> trait_spells, std::vector<ABILITY_SCORE_BONUS*> ability_bonuses );

	~RACIAL_TRAITS();

	DND_RACE							get_race() { return m_race; };
	u_int								get_typical_age() { return m_typical_age; };
	u_int								get_speed() { return m_race_speed; };
	string								get_alignment_desc() { return m_alignment_description; };
	DND_SIZE							get_size() { return m_race_size; };
	std::vector<DND_LANGUAGE>			get_languages() { return m_race_languages; };
	std::vector<DND_TOOL>				get_tool_proficiencys() { return m_tool_proficiency; };
	std::vector<TRAIT_SPELL*>			get_trait_spells() { return m_trait_spells; };
	std::vector<ABILITY_SCORE_BONUS*>	get_ability_score_bonuses() { return m_ability_score_bonuses; };

	void								print_racial_traits();

private:

	DND_RACE							m_race{ DND_RACE::INVALID };
	DND_SIZE							m_race_size{ DND_SIZE::INVALID };

	u_int								m_typical_age{ 0 };
	u_int								m_race_speed{ 0 };

	string								m_alignment_description{ "not set" };

	std::vector<ABILITY_SCORE_BONUS*>	m_ability_score_bonuses;
	std::vector<DND_LANGUAGE>			m_race_languages;
	std::vector<DND_TOOL>	m_tool_proficiency;
	std::vector<TRAIT_SPELL*>			m_trait_spells;
};
