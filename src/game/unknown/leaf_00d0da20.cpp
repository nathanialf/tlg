/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"

/* derived names: three 4-byte values copied one by one (FUN_013cb600
 * clears a local of it, the first by a 4-byte store and the other two by
 * one 8-byte store, has FUN_00c8e050 fill it and appends it at 0x13cb90e);
 * the block aligned 4; the fields are not traced */
struct Triple00d0da20 { /* derived name */
    float x;            /* +0x0 */
    float y;            /* +0x4 */
    float z;            /* +0x8 */

    Triple00d0da20() {}

    Triple00d0da20(const Triple00d0da20 &o) : x(o.x), y(o.y), z(o.z) {}
};

/* FUN_00d0da20: the append (the count raised, the block grown when it is
 * full, then the element's copy) */
template void Array05943280<Triple00d0da20>::push(const Triple00d0da20 &);
