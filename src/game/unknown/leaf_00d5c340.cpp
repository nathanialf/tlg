/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016ba7f8.h"

/* derived name: the complete destructor: FUN_00d5c810 first, then the
 * members are torn down, last first, then the base. FUN_00d5cc70, slot 1,
 * is the deleting one. The destructor is the class's key function, so this
 * file emits the vtable. */
Object016ba7f8::~Object016ba7f8()
{
    FUN_00d5c810(this);
}
