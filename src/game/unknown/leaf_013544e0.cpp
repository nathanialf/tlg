/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_math.h"

/* derived names: a holder of three arrays emptied, FUN_01343a80's sibling
 * over a holder with a 16-byte aligned vector at +0x40: FUN_01354250 first,
 * then each array's count cleared (the counted references of the second
 * dropped, its block kept), each array's state put back to 0, the vector
 * zeroed (`vmovaps`) and the pointer at +0x50 cleared. The element classes
 * of the first and third arrays are not traced. */
struct Object013544e0 { /* derived name */
    u8 unknown0[0x10];
    Array01343a80<int> unknown10;                       /* +0x10 */
    Array01343a80<Ref00503fb0<Node00503fb0>> unknown28; /* +0x28 */
    Float4A unknown40;                                  /* +0x40 */
    void *unknown50;                                    /* +0x50 */
    Array01343a80<int> unknown58;                       /* +0x58 */
};

void FUN_01354250(Object013544e0 *self); /* derived name */

void FUN_013544e0(Object013544e0 *self) /* derived name */
{
    FUN_01354250(self);
    self->unknown10.removeAll();
    self->unknown28.removeAll();
    self->unknown58.removeAll();
    self->unknown10.release();
    self->unknown28.release();
    self->unknown58.release();
    self->unknown40.set(0.0f, 0.0f, 0.0f, 0.0f);
    self->unknown50 = 0;
}
