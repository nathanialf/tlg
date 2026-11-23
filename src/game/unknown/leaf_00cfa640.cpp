/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"

/* derived names: a 12-byte element (three 32-bit words, copied as bytes);
 * not traced */
struct Element00cfa640 { /* derived name */
    u32 unknown0;        /* +0x0 */
    u32 unknown4;        /* +0x4 */
    u32 unknown8;        /* +0x8 */
};

/* derived names: FUN_00cfa640, called by FUN_00e7c8e0, copies an array of
 * the elements into the one at +0xc8 of its object (tlg_game_array.h's
 * assignment) and sets bit 0 of the byte at +0x20, a change to take up.
 * The object is not traced further. */
struct Object00cfa640 {                      /* derived name */
    u8 unknown0[0x20];                       /* not traced */
    u8 flags;                                /* +0x20 */
    u8 unknown21[0xa7];                      /* not traced */
    Array05943280<Element00cfa640> elements; /* +0xc8 */
};

void FUN_00cfa640(Object00cfa640 *self,
                  const Array05943280<Element00cfa640> &elements) /* derived name */
{
    self->elements = elements;
    self->flags |= 1;
}
