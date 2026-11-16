/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object05945a38.h"

/* derived names: under the list's lock, marks every object of the list of
 * objects released on a thread that does not destroy them (+0x201040) with
 * the flag 2 at +0x16, then empties the list, dropping its references
 * (FUN_0138c8d0 with 0). Called with the object at 0x5945a38 by
 * FUN_00c4fdb0 (0xc516e0) and FUN_00dfa570 (0xdfa597), which waits for the
 * flag. */
void FUN_00cbd050(Object05945a38 *self) /* derived name */
{
    self->released.lock.lock();
    int count = self->released.size();
    for (int i = 0; i < count; ++i)
        self->released[i].get()->flags16 |= 2;
    self->released.clear(0);
    self->released.lock.unlock();
}
