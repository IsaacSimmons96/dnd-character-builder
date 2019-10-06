# dnd-character-builder
The backend for a dnd character builder that will eventually be integrated into Ureal Engine 

NOTES

--- Potential 2D GUI stuff to use ----
https://www.qt.io/download
https://www.cocos.com/en/products#CocosCreator


--- Cacheing ----
class SPELL_CACHE
{
public: 
print_all_spells
get_spell
etc
private:
static std::array spells;
}

then when you call "get_spell"
const SPELL& get_spell
{
    if( spells.size() == 0 )
    { 
         read_in_spells();
    }
    // rest of method
}

that way it only gets read in once, and only once, and only if you ever need it
what's the point of reading in that data if the user never even goes to the screen panel feature etc
