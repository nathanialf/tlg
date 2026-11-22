/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_math.h"

/* derived names: a 64-byte record that FUN_0033eac0 builds on its stack
 * (three ints from -0x70, a box's low and high corners from the lanes'
 * minima and maxima at -0x60 and -0x50, a flag cleared at -0x40) and
 * appends to a local array at 0x33f440 and 0x33f654. The ints are copied
 * as one 8-byte and one 4-byte move, the corners lane by lane, the flag as
 * a byte; the block is aligned 16 and grows by at most 0x10000 elements */
struct Box00342e20 { /* derived name */
    int unknown0;    /* +0x0 */
    int unknown4;    /* +0x4 */
    int unknown8;    /* +0x8 */
    Float4A low;     /* +0x10 */
    Float4A high;    /* +0x20 */
    bool unknown30;  /* +0x30 */
};

/* FUN_00342e20 */
template void Array05943280<Box00342e20>::push(const Box00342e20 &);
