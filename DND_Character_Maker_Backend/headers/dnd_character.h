#pragma once
#include "character_enums.h"
#include "combat_and_item_enums.h"
#include "dice_functions.h"
#include "racial_traits_manager.h"
#include "typedefs.h"
#include <map>
#include <vector>

class TRAIT;
class WEAPON;

class DND_CHARACTER
{
	struct CHARACTER_SKILL
	{
		CHARACTER_SKILL( DND_SKILL skill_type, ABILITY_SCORE_TYPES ability_base, bool is_prof, DND_CHARACTER &character );
		ABILITY_SCORE_TYPES m_ability_dependant_on{ ABILITY_SCORE_TYPES::INVALID };
		DND_SKILL m_skill_name{ DND_SKILL::INVALID };
		short int m_skill_value{ 0 };
		bool m_is_proficient{ false };
	};

	struct SAVING_THROWS
	{
		short int		m_strength_throw{ 0 };
		short int		m_dexterity_throw{ 0 };
		short int		m_constitution_throw{ 0 };
		short int		m_intelligence_throw{ 0 };
		short int		m_wisdom_throw{ 0 };
		short int		m_charisma_throw{ 0 };

		void set_saving_throws( DND_CHARACTER &character );
		void print_saving_throws();
	};

public:
	DND_CHARACTER();
	~DND_CHARACTER();
	DND_CHARACTER( DND_CHARACTER const &character_in );

	// name setters
	void set_character_name( std::string name_in )		{ m_character_name = name_in; };
	void set_player_name( std::string name_in )			{ m_player_name = name_in; };

	// main information setters
	void set_character_class( DND_CLASS class_in );
	void set_background( DND_BACKGROUND background_in ) { m_background = background_in; };
	void set_race( DND_RACE race_in, RACIAL_TRAITS_MANAGER& rtm );
	void set_alignment( DND_ALIGNMENT alignment_in )	{ m_alignment = alignment_in; };
	void set_level( uint16_t number_in )					{ m_level = number_in; set_proficiency_bonus_from_level( m_level ); };
	void set_exp( uint16_t number_in )						{ m_exp = number_in; };
	void set_initiative_modifier();

	// other stats setters
	void set_hit_points( uint16_t number_in )				{ m_hit_points = number_in; };
	void set_proficiency_bonus( uint16_t number_in )		{ m_proficiency_bonus = number_in; };
	void set_armour_class( uint16_t number_in )			{ m_armour_class = number_in; };
	void set_passive_perception();
	void set_proficiency_bonus_from_level( uint16_t level );

	void set_saving_throws(){ m_saving_throws.set_saving_throws( *this ); };

	void update_skills();

	// character stats setters
	void set_strength( uint16_t number_in )				{ m_strength += number_in; };
	void set_dexterity( uint16_t number_in )				{ m_dexterity += number_in; set_initiative_modifier(); };
	void set_constitution( uint16_t number_in )			{ m_constitution += number_in; };
	void set_intelligence( uint16_t number_in )			{ m_intelligence += number_in; };
	void set_wisdom( uint16_t number_in )					{ m_wisdom += number_in; set_passive_perception(); };
	void set_charisma( uint16_t number_in )				{ m_charisma += number_in; };

	void add_skill_proficiency( DND_SKILL skill );
	void add_general_weapon_proficiency( WEAPON_PROFICIENCY weapon );
	void add_specific_weapon_proficiency( WEAPON* weapon );
	void add_armor_proficiency( ARMOR_CATEGORY cat );
	void add_language( DND_LANGUAGE lang );
	void add_tool_proficiency( DND_TOOL tool );
	void add_trait( TRAIT* trait );
	void update_hit_dice( DND_DICE die, uint16_t number );

	// main information getters
	std::string		get_name()							{ return m_character_name; };
	std::string		get_player_name()					{ return m_player_name; };
	DND_CLASS		get_character_class()				{ return m_class; };
	DND_BACKGROUND	get_background()					{ return m_background; };
	DND_RACE		get_race()							{ return m_race; };
	DND_ALIGNMENT	get_alignment()						{ return m_alignment; };
	uint16_t			get_proficiency_bonus()				{ return m_proficiency_bonus; };
	uint16_t			get_level()							{ return m_level; };
	uint16_t			get_exp()							{ return m_exp; };
	uint16_t			get_initiative_modifier()			{ return m_initiative_modifier; };
	uint16_t			get_hit_points()					{ return m_hit_points; };

	// character stats getters
	uint16_t get_strength()								{ return m_strength; };
	uint16_t get_dexterity()								{ return m_dexterity; };
	uint16_t get_constitution()							{ return m_constitution; };
	uint16_t get_intelligence()							{ return m_intelligence; };
	uint16_t get_wisdom()									{ return m_wisdom; };
	uint16_t get_charisma()								{ return m_charisma; };
	uint16_t get_ability_value( ABILITY_SCORE_TYPES ability_type );
	std::vector< DND_SKILL > get_skill_proficiencys();

	//prints
	void print_saving_throws() { m_saving_throws.print_saving_throws(); };
	void print_character_info();
	void print_skills();
	void print_hit_dice();
	void print_languages();
	void print_tool_proficiencies();
	void print_weapon_and_armor_proficiencies();
	void print_traits();

private:
	void apply_racial_traits( DND_RACE race, RACIAL_TRAITS_MANAGER& rtm, bool has_applied_race );

	// names
	std::string		m_character_name{ "INVALID" };
	std::string		m_player_name{ "INVALID" };

	// main information
	DND_CLASS		m_class{ DND_CLASS::INVALID };
	DND_BACKGROUND	m_background{ DND_BACKGROUND::INVALID };
	DND_RACE		m_race{ DND_RACE::INVALID };
	DND_ALIGNMENT	m_alignment{ DND_ALIGNMENT::INVALID };
	uint16_t			m_level{ 1 };
	uint16_t			m_exp{ 0 };

	// other stats
	uint16_t			m_hit_points{ 0 };
	uint16_t			m_proficiency_bonus{ 0 };
	uint16_t			m_initiative_modifier{ 0 };
	uint16_t			m_armour_class{ 0 };
	uint16_t			m_passive_perception{ 0 };
	uint16_t			m_speed{ 0 };
	DND_SIZE		m_size{ DND_SIZE::INVALID };

	SAVING_THROWS	m_saving_throws;
	std::map< DND_SKILL, CHARACTER_SKILL* > m_skills;
	std::map< DND_DICE, uint16_t > m_hit_dice;
	std::vector< DND_SKILL > m_skills_proficient_in;
	std::vector<DND_LANGUAGE> m_languages;
	std::vector<TRAIT*> m_traits;
	std::vector<DND_TOOL> m_tool_profs;
	std::vector<WEAPON*> m_weapon_profs;
	std::vector<ARMOR_CATEGORY> m_armor_profs;
	std::vector<WEAPON_PROFICIENCY> m_general_weapon_profs;

	// character stats
	uint16_t			m_strength{ 0 };
	uint16_t			m_dexterity{ 0 };
	uint16_t			m_constitution{ 0 };
	uint16_t			m_intelligence{ 0 };
	uint16_t			m_wisdom{ 0 };
	uint16_t			m_charisma{ 0 };
};
