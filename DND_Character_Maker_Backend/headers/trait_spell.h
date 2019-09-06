#pragma once
#include "spell_base.h"
#include "typedefs.h"

class TRAIT_SPELL : public SPELL_BASE
{
public:
	TRAIT_SPELL( string name, string desc );
	~TRAIT_SPELL();


	void set_spell_description( string spell_description );
	string get_spell_description();
	void print_spell() const override;

private:

};
