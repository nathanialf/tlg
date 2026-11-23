/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"

/* derived names: FUN_00d417d0 has no direct caller (a slot of a vtable not
 * found): when bit 1 of the byte at +0x16 is set it copies the array of
 * 32-bit values slot 5 of the object gives into its own at +0x28
 * (tlg_game_array.h's assignment, over the values one memcpy); it returns
 * 1. The class and what the values are are not traced. */
class Object00d417d0 /* derived name */
{
  public:
    virtual void slot0();                      /* derived name; not traced */
    virtual void slot1();                      /* derived name; not traced */
    virtual void slot2();                      /* derived name; not traced */
    virtual void slot3();                      /* derived name; not traced */
    virtual void slot4();                      /* derived name; not traced */
    virtual const Array05943280<u32> *slot5(); /* derived name: the values to take */

    u8 unknown8[0xe];          /* not traced */
    u8 flags16;                /* +0x16 */
    u8 unknown17[0x11];        /* not traced */
    Array05943280<u32> values; /* +0x28 */
};

// NONMATCHING: two registers in the growth (single file, the module not measured yet): the base
// keeps the byte count in r9d (`lea r9d, [r14*4]`) and the owner's vtable in rax, where the
// build has them the other way round, as FUN_00cfa640 (equal) has in the base.
int FUN_00d417d0(Object00d417d0 *self) /* derived name */
{
    if (self->flags16 & 2)
        self->values = *self->slot5();
    return 1;
}
