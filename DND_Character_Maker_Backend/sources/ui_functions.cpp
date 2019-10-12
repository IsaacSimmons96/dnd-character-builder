#include "..\headers\ui_functions.h"

#include "..\headers\character_enums.h"
#include "..\headers\dnd_character.h"
#include "..\headers\racial_traits.h"
#include "..\headers\racial_traits_manager.h"

void UI_FUNCTION::select_character_race( const DND_CHARACTER& character, DND_RACE race )
{
	//RACIAL_TRAITS* traits = racial_trait_manager.get_race_traits( m_race );

	//auto bonuses = traits->get_ability_score_bonuses();

	//for ( auto bonus : bonuses )
	//{
	//	switch ( bonus->get_bonus_type() )
	//	{
	//	case ABILITY_SCORE_TYPES::STRENGTH:
	//		m_strength += bonus->get_bonus_value();
	//		break;
	//	case ABILITY_SCORE_TYPES::DEXTERITY:
	//		m_dexterity += bonus->get_bonus_value();
	//		break;
	//	case ABILITY_SCORE_TYPES::CONSTITUTION:
	//		m_constitution += bonus->get_bonus_value();
	//		break;
	//	case ABILITY_SCORE_TYPES::INTELLIGENCE:
	//		m_intelligence += bonus->get_bonus_value();
	//		break;
	//	case ABILITY_SCORE_TYPES::WISDOM:
	//		m_wisdom += bonus->get_bonus_value();
	//		break;
	//	case ABILITY_SCORE_TYPES::CHARISMA:
	//		m_charisma += bonus->get_bonus_value();
	//		break;
	//	case ABILITY_SCORE_TYPES::INVALID:
	//		break;
	//	}
	//}

	//auto langs = traits->get_languages();
	//for ( auto language : langs )
	//{
	//	add_language( language );
	//}

	//m_speed = traits->get_speed();

	//auto trait_spells = traits->get_trait_spells();
	//for ( TRAIT_SPELL* t_spell : trait_spells )
	//{
	//	m_trait_spells.push_back( t_spell );
	//}
}

void UI_FUNCTION::select_character_skill_proficiency( const DND_CHARACTER& character, DND_SKILL_TYPE skill )
{
}

void UI_FUNCTION::select_character_tool_proficiency( const DND_CHARACTER& character, DND_TOOL_PROFICIENCY tool )
{
}