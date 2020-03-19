#pragma once
#include "spell_base.h"
#include "typedefs.h"

class TRAIT : public SPELL_BASE
{
public:
	// Reminder for if i forget.
	// Read Only means its a trait that youd only read and act upon. You wouldent actually write this on your sheet. See PHB page 20 - Tool Proficiency
	TRAIT( string name, string desc, bool read_only );
	~TRAIT();

	void set_spell_description( string spell_description );
	string get_spell_description();
	void print() const override;
	bool is_read_only() const { return m_read_only; };

private:
	bool m_read_only{ false };
};
