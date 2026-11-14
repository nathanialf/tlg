/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_object0139b6b0.h"

/* derived names: the complete destructor of a class whose vtable is at
 * 0x16c05d8 (config/vtables.derived.base.txt; stored by the constructor
 * FUN_00ffe8c0 and by the destructors FUN_00ff18f0 and FUN_00ff1910): it
 * stores the vtable and tail-calls 0x13e9b40, the destructor of its member
 * at +0x98, an array of tlg_game_object0139b6b0.h, as the derived complete
 * destructors are (leaf_0037aa70.cpp); FUN_00ff1910, slot 1, is the deleting
 * one. The member's fields are not traced. The destructor is the class's key
 * function, so this file emits the vtable. */
class Object00ff18f0 /* derived name */
{
  public:
    virtual ~Object00ff18f0();

  private:
    u8 unknown8[0x90];
    Object013e9b40 unknown98; /* +0x98 */
};

Object00ff18f0::~Object00ff18f0() {}
