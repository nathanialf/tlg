/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_simd.h"

/* derived names: the 0x70-byte element of the array FUN_0021e410,
 * FUN_0021e920 and FUN_013398d0 extend: its constructor leaves the first
 * 0x40 bytes (16-byte aligned), clears the 28 bytes from +0x40 and stores
 * -1 at +0x5c and the 64-bit 0xffffffff at +0x60; the fields
 * are not traced */
struct Record00220c10 { /* derived name */

    Record00220c10() : unknown40(), unknown5c(-1), unknown60(0xffffffffu) {}

    Vec4 unknown0[4]; /* +0x0 */
    int unknown40[7]; /* +0x40 */
    int unknown5c;    /* +0x5c */
    u64 unknown60;    /* +0x60 */
};

/* FUN_00220c10: default elements appended (the count raised by the number,
 * the block grown when it is too small, then each new element built) */
template void Array05943280<Record00220c10>::addDefault(unsigned);
