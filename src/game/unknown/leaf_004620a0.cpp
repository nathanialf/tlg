/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_math.h"

/* derived names: a 48-byte entry, an int, a Name at +0x4 and two 16-byte
 * aligned points; only the Name has a destructor. FUN_004303d0 empties the
 * array at +0x1820 of its object through it (a tail call at its end) */
struct Entry004620a0 { /* derived name */
    int unknown0;      /* +0x0 */
    Name name;         /* +0x4 */
    Float4A unknown10; /* +0x10 */
    Float4A unknown20; /* +0x20 */
};

// NONMATCHING: register assignment only: the base holds the block in rdx and the entry's
// Name index in rcx inside the loop, the build the other way round (same instructions and
// size; 0x4aaa20, the same body over 8-byte entries, is equal)
/* FUN_004620a0: the array emptied and its block given back: each entry's
 * Name released (the array and the count read again at each one), the
 * count cleared, then a capacity that is not zero cleared and the block
 * reallocated to no bytes */
template void Array05943280<Entry004620a0>::clear();
