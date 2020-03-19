#pragma once
#include "character_enums.h"
#include "spell_base.h"
#include "spell_enums.h"
#include "typedefs.h"
#include <vector>

class SPELL : public SPELL_BASE
{
public:
	SPELL( string name, string desc, string higher_desc, uint16_t spell_level, std::vector<DND_CLASS> classes );

	void set_spell_description( string spell_description )	{ m_spell_description = spell_description; };

	string get_spell_description()			{ return m_spell_description; };
	string get_higher_spell_description()	{ return m_higher_level_description; };
	string get_full_spell_description()		{ return get_spell_description() + "\n\n" + get_higher_spell_description(); };

	void print() const override;

	bool is_available_to_class( DND_CLASS class_in );

protected:
	string m_higher_level_description;
	uint16_t m_spell_level;
	std::vector<DND_CLASS> m_available_to_classes;
};

class MAGIC_SPELL : public SPELL
{
public:
	MAGIC_SPELL( string name, SCHOOL_OF_MAGIC school, string desc, string higher_desc, SPELL_CASTING_TIME casting_t, uint16_t range,
				 SPELL_COMPONENT components, string material_description, SPELL_DURATION duration, SPELL_DURATION_TIME spell_duration_time,
				 uint16_t spell_level, std::vector<DND_CLASS> classes );
	void print() const override;

private:
	uint16_t m_spell_range;
	string m_material_description;
	SPELL_DURATION m_spell_duration;
	SPELL_DURATION_TIME m_spell_duration_time;
	SPELL_CASTING_TIME m_casting_time;
	SPELL_COMPONENT m_spell_components;
	SCHOOL_OF_MAGIC m_school;
};
//
//class PHYSICAL_SPELL : public SPELL_BASE
//{
//public:
//	PHYSICAL_SPELL( string name, string desc );
//	~PHYSICAL_SPELL();
//
//
//	void set_spell_description( string spell_description );
//	string get_spell_description();
//
//private:
//
//};