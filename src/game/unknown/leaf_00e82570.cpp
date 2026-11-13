/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00c55550.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16be050 (config/vtables.derived.base.txt; stored also by FUN_00e828c0):
 * it stores the vtable, passes the object to FUN_00e82150 and runs its base's
 * destructor FUN_00c55550 as a tail call. FUN_00e825a0, slot 1, is the deleting
 * one. The destructor is the class's key function, so this file emits the
 * vtable. */
class Object00e82570 : public Object00c55550 /* derived name */
{
  public:
    virtual ~Object00e82570();
};

void FUN_00e82150(Object00e82570 *self); /* derived name */

Object00e82570::~Object00e82570()
{
    FUN_00e82150(this);
}
