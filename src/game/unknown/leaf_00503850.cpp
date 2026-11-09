/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: clears bit 0 of the byte at +0x5c; FUN_00503700 beside it
 * sets it. No call, no stored address and no rip-relative
 * reference reaches either, so the record and the bit are known only from
 * these bytes. */
struct Object00503700 {
    u8 unknown0[0x5c];
    u8 unknown5c;
};

void FUN_00503850(Object00503700 *self) /* derived name */
{
    self->unknown5c &= ~1;
}
