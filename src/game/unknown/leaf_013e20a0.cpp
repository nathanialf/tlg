/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013e4200.h"

/* derived names: the complete destructor of a class whose vtable is at
 * 0x16ca6b8 (config/vtables.derived.base.txt; stored by FUN_00f9ab50 FUN_013e20a0 FUN_013e20e0): it stores
 * the vtable, deletes the object the pointer at +0x460 holds through its
 * virtual deleting destructor (slot 1 of its vtable, skipped for null), then
 * runs its base's destructor FUN_013e4200 (its row named for it, D15) as a
 * tail call. FUN_013e20e0, slot 1, is the deleting one. The owned object
 * (Owned013e4200) is the base's member (tlg_game_object013e4200.h). The destructor is the class's
 * key function, so this file emits the vtable. */
class Object013e20a0 : public Object013e4200 /* derived name */
{
  public:
    virtual ~Object013e20a0();
};

Object013e20a0::~Object013e20a0()
{
    delete unknown460;
}
