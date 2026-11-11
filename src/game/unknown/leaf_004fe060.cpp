/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: FUN_004ccff0's shape with one more test first: unless bit 1
 * of the byte at +0x25 of the source the pointer at +0x28 holds is set (read
 * before the pointer is tested), and when the pointer is set and the one at
 * +0x108 is still null, has FUN_002054d0 fill the slot at +0x108 from it
 * (third argument 0) and clears bit 1 of the byte at +0x100 of the object the
 * slot then holds. Class and method unknown. */
struct Source004fe060 /* derived name */
{
    u8 unknown0[0x25];
    u8 flags25; /* +0x25 */
};

struct Target004fe060 /* derived name */
{
    u8 unknown0[0x100];
    u8 flags100; /* +0x100 */
};

struct Object004fe060 /* derived name */
{
    u8 unknown0[0x28];
    Source004fe060 *unknown28; /* +0x28 */
    u8 unknown30[0xd8];
    Target004fe060 *unknown108; /* +0x108 */
};

void FUN_002054d0(Target004fe060 **slot, Source004fe060 *source, int flag); /* derived name */

// NONMATCHING: the base tests the source's flag before the pointer (`test byte ptr [rsi + 0x25],
// 2; jne; test rsi, rsi; je`), the source order; this tests the pointer first and loads the byte
// (`mov al, byte ptr [rsi + 0x25]; and al, 2`), also with the flag test as a return of its own
void FUN_004fe060(Object004fe060 *self) /* derived name */
{
    if (!(self->unknown28->flags25 & 2) && self->unknown28 && !self->unknown108) {
        FUN_002054d0(&self->unknown108, self->unknown28, 0);
        if (self->unknown108)
            self->unknown108->flags100 &= ~2;
    }
}
