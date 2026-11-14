/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"

/* derived names: a holder of three arrays emptied: FUN_013442d0 first, then
 * each array's count cleared (the counted references of the second dropped,
 * its block kept), each array's state put back to 0, and the pointer at
 * +0x40 cleared. The element classes of the first and third arrays are not
 * traced (no element is destroyed: ints here). */
struct Object01343a80 { /* derived name */
    u8 unknown0[0x10];
    Array01343a80<int> unknown10;                       /* +0x10 */
    Array01343a80<Ref00503fb0<Node00503fb0>> unknown28; /* +0x28 */
    void *unknown40;                                    /* +0x40 */
    Array01343a80<int> unknown48;                       /* +0x48 */
};

void FUN_013442d0(Object01343a80 *self); /* derived name */

void FUN_01343a80(Object01343a80 *self) /* derived name */
{
    FUN_013442d0(self);
    self->unknown10.removeAll();
    self->unknown28.removeAll();
    self->unknown48.removeAll();
    self->unknown10.release();
    self->unknown28.release();
    self->unknown48.release();
    self->unknown40 = 0;
}
