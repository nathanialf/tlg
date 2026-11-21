/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016aea40.h"

/* derived name: the destructor, the class's key function (so this file emits
 * the vtable): its body calls FUN_00822250 on the object, then the counted
 * reference at +0x240 is released and the base's destructor is called, a
 * tail call (0x822190, the complete destructor; FUN_00822370 the deleting
 * one, slot 1). */
Object016aea40::~Object016aea40()
{
    FUN_00822250();
}
