/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback (its address taken by FUN_00202800, lea at
 * 0x202847): calls FUN_002178a0 on the object, clears bit 2 of its byte at
 * +0x34 and returns 1. Class unknown. */
struct Object002186a0 { /* derived name */
    u8 unknown0[0x34];
    u8 unknown34;
};

void FUN_002178a0(Object002186a0 *self); /* derived name */

int FUN_002186a0(Object002186a0 *self) /* derived name */
{
    FUN_002178a0(self);
    self->unknown34 &= ~4;
    return 1;
}
