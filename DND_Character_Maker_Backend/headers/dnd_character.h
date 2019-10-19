#pragma once
#include "character_enums.h"
#include "typedefs.h"
#include <map>
#include <vector>
#include "dice_functions.h"
#include "racial_traits_manager.h"

class DND_CHARACTER
{
	class TRAIT_SPELL;

	struct CHARACTER_SKILL
	{
		CHARACTER_SKILL( DND_SKILL_TYPE skill_type, ABILITY_SCORE_TYPES ability_base, bool is_prof, DND_CHARACTER &character );
		ABILITY_SCORE_TYPES m_ability_dependant_on{ ABILITY_SCORE_TYPES::INVALID };
		DND_SKILL_TYPE m_skill_name{ DND_SKILL_TYPE::INVALID };
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
	void set_character_class( DND_CLASS class_in )		{ m_class = class_in; };
	void set_background( DND_BACKGROUND background_in ) { m_background = background_in; };
	void set_race( DND_RACE race_in, RACIAL_TRAITS_MANAGER& rtm );
	void set_alignment( DND_ALIGNMENT alignment_in )	{ m_alignment = alignment_in; };
	void set_level( u_int number_in )					{ m_level = number_in; set_proficiency_bonus_from_level( m_level ); };
	void set_exp( u_int number_in )						{ m_exp = number_in; };
	void set_initiative_modifier( u_int number_in )		{ m_initiative_modifier = number_in; };

	// other stats setters
	void set_hit_points( u_int number_in )				{ m_hit_points = number_in; };
	void set_proficiency_bonus( u_int number_in )		{ m_proficiency_bonus = number_in; };
	void set_armour_class( u_int number_in )			{ m_armour_class = number_in; };
	void set_passive_perception();
	void set_proficiency_bonus_from_level( u_int level );

	void set_saving_throws(){ m_saving_throws.set_saving_throws( *this ); };

	void update_skills();

	// character stats setters
	void set_strength( u_int number_in )				{ m_strength += number_in; };
	void set_dexterity( u_int number_in )				{ m_dexterity += number_in; };
	void set_constitution( u_int number_in )			{ m_constitution += number_in; };
	void set_intelligence( u_int number_in )			{ m_intelligence += number_in; };
	void set_wisdom( u_int number_in )					{ m_wisdom += number_in; set_passive_perception(); };
	void set_charisma( u_int number_in )				{ m_charisma += number_in; };

	void add_skill_proficiency( DND_SKILL_TYPE skill );
	void add_language( DND_LANGUAGE lang );
	void add_tool_proficiency( DND_TOOL tool );
	void update_hit_dice( DND_DICE die, u_int number );

	// main information getters
	std::string		get_name()							{ return m_character_name; };
	std::string		get_player_name()					{ return m_player_name; };
	DND_CLASS		get_character_class()				{ return m_class; };
	DND_BACKGROUND	get_background()					{ return m_background; };
	DND_RACE		get_race()							{ return m_race; };
	DND_ALIGNMENT	get_alignment()						{ return m_alignment; };
	u_int			get_proficiency_bonus()				{ return m_proficiency_bonus; };
	u_int			get_level()							{ return m_level; };
	u_int			get_exp()							{ return m_exp; };
	u_int			get_initiative_modifier()			{ return m_initiative_modifier; };
	u_int			get_hit_points()					{ return m_hit_points; };

	// character stats getters
	u_int get_strength()								{ return m_strength; };
	u_int get_dexterity()								{ return m_dexterity; };
	u_int get_constitution()							{ return m_constitution; };
	u_int get_intelligence()							{ return m_intelligence; };
	u_int get_wisdom()									{ return m_wisdom; };
	u_int get_charisma()								{ return m_charisma; };
	u_int get_ability_value_from_DND_ABILITY_SCORE_TYPES( ABILITY_SCORE_TYPES ability_type );
	std::vector< DND_SKILL_TYPE > get_skill_proficiencys();

	//prints
	void print_saving_throws() { m_saving_throws.print_saving_throws(); };
	void print_character_info();
	void print_skills();
	void print_hit_dice();
	void print_languages();

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
	u_int			m_level{ 1 };
	u_int			m_exp{ 0 };

	// other stats
	u_int			m_hit_points{ 0 };
	u_int			m_proficiency_bonus{ 0 };
	u_int			m_initiative_modifier{ 0 };
	u_int			m_armour_class{ 0 };
	u_int			m_passive_perception{ 0 };
	u_int			m_speed{ 0 };
	DND_SIZE		m_size{ DND_SIZE::INVALID };

	SAVING_THROWS	m_saving_throws;
	std::map< DND_SKILL_TYPE, CHARACTER_SKILL* > m_skills;
	std::map< DND_DICE, u_int > m_hit_dice;
	std::vector< DND_SKILL_TYPE > m_skills_proficient_in;
	std::vector<DND_LANGUAGE> m_languages;
	std::vector<TRAIT_SPELL*> m_trait_spells;
	std::vector<DND_TOOL> m_tool_profs;

	// character stats
	u_int			m_strength{ 0 };
	u_int			m_dexterity{ 0 };
	u_int			m_constitution{ 0 };
	u_int			m_intelligence{ 0 };
	u_int			m_wisdom{ 0 };
	u_int			m_charisma{ 0 };
};
