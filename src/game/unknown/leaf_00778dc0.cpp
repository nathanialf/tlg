/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_simd.h"

/* derived names: copies the row at +0x100 into the target at +0x68, offset
 * +0x2110. Unknown owner. */
struct Target778dc0 {
    u8 unknown0[0x2110];
    Vec4 value;
};

struct Owner778dc0 {
    u8 unknown0[0x68];
    Target778dc0 *target;
    u8 unknown70[0x100 - 0x70];
    Vec4 value;
};

void FUN_00778dc0(const Owner778dc0 *self) /* derived name */
{
    self->target->value = self->value;
}
