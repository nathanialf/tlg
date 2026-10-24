/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_simd.h"

/* derived names: two rows of a sub-object at +0x4e0 copied out. Unknown owner. */
struct Sub4ba5f0 {
    u8 unknown0[0x50];
    Vec4 a;
    u8 unknown60[0x10];
    Vec4 b;
};

struct Owner4ba5f0 {
    u8 unknown0[0x4e0];
    Sub4ba5f0 *sub;
};

void FUN_004ba5f0(const Owner4ba5f0 *self, Vec4 *a, Vec4 *b) /* derived name */
{
    *a = self->sub->a;
    *b = self->sub->b;
}
