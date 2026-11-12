/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_object0134f620.h"

/* derived names: the complete destructor of a class whose vtable is at
 * 0x16ba0c8 (config/vtables.derived.base.txt), slot 0, its deleting one
 * FUN_00d1da50 at slot 1, the vtable also stored by FUN_00c32940: it stores
 * the vtable and tail-calls 0x134f620, the destructor of its member at +0x8
 * (which first tests the int at +0x8 of that member), written as a free
 * function on that record, as the derived complete destructors are. The
 * destructor is the class's key function, so this file emits the vtable. */

class Object00d1da30 /* derived name */
{
  public:
    virtual ~Object00d1da30();

  private:
    Object0134f620 unknown8; /* +0x8 */
};

Object00d1da30::~Object00d1da30() {}
