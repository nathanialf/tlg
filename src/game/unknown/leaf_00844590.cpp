/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016aeed0.h"

/* derived name: the complete destructor: the list at +0x98 emptied
 * (FUN_0138c3b0) and the array at +0xd0 emptied to no block, then the
 * members released, last first (the ten Names, the array's block, the
 * list's block), and the base's destructor FUN_00d687e0 as a tail call.
 * FUN_008448d0, slot 1, is the deleting one. The destructor is the class's
 * key function, so this file emits the vtable. */
Object016aeed0::~Object016aeed0()
{
    FUN_0138c3b0(&list98);
    arrayd0.clear();
}
