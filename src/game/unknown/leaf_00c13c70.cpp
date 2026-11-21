/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b7e70.h"

/* derived name: the complete destructor (0xc13c70): the fields emptied,
 * then the members' destructors, the block at +0x18 before the reference at
 * +0x10. The destructor is the class's key function, so this file emits the
 * vtable and the deleting destructor (0xc13dc0). */
Object016b7e70::~Object016b7e70()
{
    reset();
}
