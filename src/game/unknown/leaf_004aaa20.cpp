/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"

/* derived names: a Name and an int, 8 bytes aligned 4 */
struct Entry004aaa20 { /* derived name */
    Name name;         /* +0x0 */
    int unknown4;      /* +0x4 */
};

/* FUN_004aaa20: the array emptied and its block given back: each entry's
 * Name released (the array and the count read again at each one), the
 * count cleared, then a capacity that is not zero cleared and the block
 * reallocated to no bytes */
template void Array05943280<Entry004aaa20>::clear();
