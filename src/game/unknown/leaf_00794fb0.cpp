/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_simd.h"

/* derived names: empties the counted reference at +0x100 of the object, by
 * compare-and-swap, then in the record at +0x68 clears the int at +0x12cc
 * and copies the four floats at +0x12d0 to +0x12e0. The classes are not
 * traced. */
struct Record00794fb0 { /* derived name */
    u8 unknown0[0x12cc];
    int unknown12cc;  /* +0x12cc */
    Vec4 unknown12d0; /* +0x12d0 */
    Vec4 unknown12e0; /* +0x12e0 */
};

struct Object00794fb0 { /* derived name */
    u8 unknown0[0x68];
    Record00794fb0 *unknown68; /* +0x68 */
    u8 unknown70[0x90];
    AtomicRef0045c470<Node00503fb0> unknown100; /* +0x100 */
};

void FUN_00794fb0(Object00794fb0 *self) /* derived name */
{
    self->unknown100.clear();
    self->unknown68->unknown12cc = 0;
    self->unknown68->unknown12e0 = self->unknown68->unknown12d0;
}
