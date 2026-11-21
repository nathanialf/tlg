/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 20 of the vtable at 0x16d3408 (its pointer at
 * 0x16d34a8): keeps, in their order and at the front of the array, the
 * pairs for which FUN_00eadcb0 gives nonzero with the second argument
 * (leaf_013cc260.cpp's call), and returns how many it kept. The object is
 * not read; the types beyond the widths are not traced. */
struct Object013cc180;        /* derived name */
struct Member05a8dbc0_268_38; /* derived name */

struct Pair013cc180 { /* derived name */
    int first;
    int second;
};

int FUN_00eadcb0(Member05a8dbc0_268_38 *member, int first, int second); /* derived name */

int FUN_013cc180(Object013cc180 *, Member05a8dbc0_268_38 *member, Pair013cc180 *pairs,
                 int count) /* derived name */
{
    int kept = 0;
    for (int i = 0; i < count;) {
        const Pair013cc180 &pair = pairs[i++];
        if (!FUN_00eadcb0(member, pair.first, pair.second))
            continue;
        Pair013cc180 &place = pairs[kept++];
        if (kept != i) {
            place.first = pair.first;
            place.second = pair.second;
        }
    }
    return kept;
}
