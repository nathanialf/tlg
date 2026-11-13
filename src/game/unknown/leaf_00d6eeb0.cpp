/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00d30550.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16baac8 (config/vtables.derived.base.txt; stored also by FUN_00d6de50, FUN_00e980d0 and FUN_00e98140):
 * it stores the vtable, passes the object to FUN_00d6e9b0 and runs its base's
 * destructor FUN_00d30550 as a tail call. FUN_00d6eee0, slot 1, is the deleting
 * one. The destructor is the class's key function, so this file emits the
 * vtable. */
class Object00d6eeb0 : public Object00d30550 /* derived name */
{
  public:
    virtual ~Object00d6eeb0();
};

void FUN_00d6e9b0(Object00d6eeb0 *self); /* derived name */

Object00d6eeb0::~Object00d6eeb0()
{
    FUN_00d6e9b0(this);
}
