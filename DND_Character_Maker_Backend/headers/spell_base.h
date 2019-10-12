#pragma once
#include <string>
#include "typedefs.h"

class SPELL_BASE
{
public:
	SPELL_BASE();
	~SPELL_BASE();

	virtual string get_spell_description() = 0;
	string get_spell_name() const						{ return m_spell_name; };

	void set_spell_name( string spell_name )	{ m_spell_name = spell_name; };
	virtual void set_spell_description( string spell_description ) = 0;

	virtual void print_spell() const = 0;

protected:
	string m_spell_description{ "not set" };
	string m_spell_name{ "not set" };
};
