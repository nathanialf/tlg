/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x016be0b0 (config/vtables.derived.base.txt): it stores the vtable, passes the
 * object to FUN_00e82150 (as leaf_00e82570.cpp's class does) and runs the
 * root class's destructor, inlined (the root's vtable stored, its two names
 * dropped). FUN_00e82660, slot 1, is the deleting one. The destructor is the
 * class's key function, so this file emits the vtable. */
class Object016be0b0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016be0b0();
};

void FUN_00e82150(Object016be0b0 *self); /* derived name */

Object016be0b0::~Object016be0b0()
{
    FUN_00e82150(this);
}
