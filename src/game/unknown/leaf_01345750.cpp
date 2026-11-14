/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"

/* derived names: a holder of three arrays emptied: the exchanged reference
 * at +0x10 emptied and FUN_013459e0 called first, then each array's count
 * cleared (the counted references of the first dropped, its block kept) and
 * each array's state put back to 0, the array at +0x30 before the one at
 * +0x18 each time. The element classes of the second and third arrays are
 * not traced (no element is destroyed: ints here). */
struct Object01345750 { /* derived name */
    u8 unknown0[0x10];
    AtomicRef0045c470<Node00503fb0> unknown10;          /* +0x10 */
    Array01343a80<Ref00503fb0<Node00503fb0>> unknown18; /* +0x18 */
    Array01343a80<int> unknown30;                       /* +0x30 */
    Array01343a80<int> unknown48;                       /* +0x48 */
};

void FUN_013459e0(Object01345750 *self); /* derived name */

void FUN_01345750(Object01345750 *self) /* derived name */
{
    self->unknown10.clear();
    FUN_013459e0(self);
    self->unknown30.removeAll();
    self->unknown18.removeAll();
    self->unknown48.removeAll();
    self->unknown30.release();
    self->unknown18.release();
    self->unknown48.release();
}
