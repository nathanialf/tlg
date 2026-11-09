/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback that sets the int at +0x40 of its argument to 3.
 * FUN_008380b0 passes its address twice (lea at 0x8388f7 and 0x838a97) as the
 * second argument of FUN_01370670, the first the pointer at +0x1f0 of its
 * record and the third 0, a registration whose call of the callback is not
 * traced; one pointer parameter, the record the store shows. Owner and meaning
 * unknown. */
struct Object0083cbf0 { /* derived name */
    u8 unknown0[0x40];
    int unknown40;
};

void FUN_0083cbf0(Object0083cbf0 *self) /* derived name */
{
    self->unknown40 = 3;
}
