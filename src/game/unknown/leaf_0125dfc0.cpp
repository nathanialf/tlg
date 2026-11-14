/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_object0139b6b0.h"

/* derived names: the complete destructor of a class whose vtable is at
 * 0x16c2780 (config/vtables.derived.base.txt; stored by the constructor
 * FUN_0126a510 and by the destructors FUN_0125dfc0 and FUN_0125dfe0): it
 * stores the vtable and tail-calls 0x13e9b40, the destructor of its member
 * at +0x98, an array of tlg_game_object0139b6b0.h, as the derived complete
 * destructors are (leaf_0037aa70.cpp); FUN_0125dfe0, slot 1, is the deleting
 * one. The member's fields are not traced. The destructor is the class's key
 * function, so this file emits the vtable. */
class Object0125dfc0 /* derived name */
{
  public:
    virtual ~Object0125dfc0();

  private:
    u8 unknown8[0x90];
    Object013e9b40 unknown98; /* +0x98 */
};

Object0125dfc0::~Object0125dfc0() {}
