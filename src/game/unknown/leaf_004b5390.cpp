/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016aa258.h"

/* derived name: the complete destructor: the array at +0x28 emptied to no
 * block, then the members released, last first (the references at +0x80
 * and +0x78, the array), and the base. FUN_004b5740, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016aa258::~Object016aa258()
{
    array28.clear();
}
