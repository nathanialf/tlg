/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <stdlib.h>

#include "tlg_game_object0139e050.h"

/* derived names: the complete destructor, slot 0 of the vtable at 0x16d0180:
 * it stores the vtable, frees the block at +0x30 with the C library's free
 * and clears the pointer and the 8 bytes after it (one 16-byte store), then
 * runs its base's destructor FUN_0130acb0 (its row named for it, D15) as a
 * tail call. FUN_0139e090, slot 1, is the deleting one. The destructor is
 * the class's key function, so this file emits the vtable. */
Object0139e050::~Object0139e050()
{
    free(data);
    data = 0;
    size = 0;
}
