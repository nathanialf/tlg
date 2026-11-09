/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores 8 in the ints at +0x2c and +0x30 (one 64-bit store);
 * no caller or pointer slot found (an inline's out-of-line copy). Class and
 * method unknown. */
struct Object001ab440 { /* derived name */
    u8 unknown0[0x2c];
    int unknown2c;
    int unknown30;
};

void FUN_001ab440(Object001ab440 *self) /* derived name */
{
    self->unknown2c = 8;
    self->unknown30 = 8;
}
