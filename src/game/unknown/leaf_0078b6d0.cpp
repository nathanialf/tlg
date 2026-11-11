/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_simd.h"

/* derived names: slot 9 of the vtable at 0x16ad480: FUN_00785b40 on the
 * object, then the record at +0x68 keeps its vector at +0xc40 at +0xc50 too.
 * Class and method unknown. */
struct State0078b6d0 { /* derived name */
    u8 unknown0[0xc40];
    Vec4 unknownc40;
    Vec4 unknownc50;
};

struct Object0078b6d0 { /* derived name */
    u8 unknown0[0x68];
    State0078b6d0 *unknown68;
};

void FUN_00785b40(Object0078b6d0 *self); /* derived name */

void FUN_0078b6d0(Object0078b6d0 *self) /* derived name */
{
    FUN_00785b40(self);
    State0078b6d0 *state = self->unknown68;
    state->unknownc50 = state->unknownc40;
}
