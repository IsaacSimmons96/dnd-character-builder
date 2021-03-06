#pragma once

#include "character_enums.h"
#include "trait_spell.h"
#include "typedefs.h"
#include <vector>
#include "ability_score_bonus.h"

class RACIAL_TRAITS
{
public:
	RACIAL_TRAITS( DND_RACE race, uint16_t age, uint16_t speed, string align_desc, DND_SIZE size, std::vector<DND_LANGUAGE> langs, std::vector<DND_TOOL> tool_profs,
				   std::vector<TRAIT*> traits, std::vector<ABILITY_SCORE_BONUS*> ability_bonuses, bool need_to_pick_subrace, DND_RACE main_race = DND_RACE::INVALID );

	~RACIAL_TRAITS();

	DND_RACE							get_race() { return m_race; };
	DND_RACE							get_main_race() { return m_main_race; };
	uint16_t								get_typical_age() { return m_typical_age; };
	uint16_t								get_speed() { return m_race_speed; };
	string								get_alignment_desc() { return m_alignment_description; };
	DND_SIZE							get_size() { return m_race_size; };
	std::vector<DND_LANGUAGE>			get_languages() { return m_race_languages; };
	std::vector<DND_TOOL>				get_tool_proficiencys() { return m_tool_proficiency; };
	std::vector<TRAIT*>					get_traits() { return m_traits; };
	std::vector<TRAIT*>					get_sheet_traits() { return m_sheet_traits; };
	std::vector<ABILITY_SCORE_BONUS*>	get_ability_score_bonuses() { return m_ability_score_bonuses; };
	bool								is_subrace() { return m_main_race != DND_RACE::INVALID ? true : false; }
	bool								must_pick_subrace() { return m_must_pick_subrace; }

	void								print();

private:

	DND_RACE							m_race{ DND_RACE::INVALID };
	DND_RACE							m_main_race{ DND_RACE::INVALID };
	DND_SIZE							m_race_size{ DND_SIZE::INVALID };
	bool								m_must_pick_subrace{ false };

	uint16_t								m_typical_age{ 0 };
	uint16_t								m_race_speed{ 0 };

	string								m_alignment_description{ "not set" };

	std::vector<ABILITY_SCORE_BONUS*>	m_ability_score_bonuses;
	std::vector<DND_LANGUAGE>			m_race_languages;
	std::vector<DND_TOOL>				m_tool_proficiency;
	std::vector<TRAIT*>					m_traits;
	std::vector<TRAIT*>					m_sheet_traits; // traits a person would actually write on their sheet
};
