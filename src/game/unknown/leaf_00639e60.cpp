/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_simd.h"

/* derived names: copies the row at +0x23a0 into the target at +0x28, offset
 * +0x220. Unknown owner. */
struct Target639e60 {
    u8 unknown0[0x220];
    Vec4 value;
};

struct Owner639e60 {
    u8 unknown0[0x28];
    Target639e60 *target;
    u8 unknown30[0x23a0 - 0x30];
    Vec4 value;
};

void FUN_00639e60(const Owner639e60 *self) /* derived name */
{
    self->target->value = self->value;
}
