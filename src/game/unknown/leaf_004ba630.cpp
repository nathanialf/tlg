/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_math.h"

/* derived names: returns the 4-float record at +0xa0 by value; the record is
 * a class with its own copy constructor, so it comes back through a hidden
 * pointer rather than in xmm0/xmm1. Unknown owner. */
struct Owner4ba630 {
    u8 unknown0[0xa0];
    Float4 position;
};

Float4 FUN_004ba630(const Owner4ba630 *self) /* derived name */
{
    return self->position;
}
