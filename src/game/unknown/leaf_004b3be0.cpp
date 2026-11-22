/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016aa1b0.h"

/* derived name: the entry of each point index (unsigned four-byte indices in
 * .rodata) */
extern const unsigned D_151f484[];

/* slot 8 of 0x16aa1b0: the point of an index below the count less one, the
 * entry the table at 0x151f484 picks for it; any other index gets
 * Object016aa0d0's point (inlined) */
Float4 Object016aa1b0::slot8(int index) const
{
    if (index >= 0 && index < slot7() - 1)
        return entries[D_151f484[index]].point;
    return Object016aa0d0::slot8(index);
}
