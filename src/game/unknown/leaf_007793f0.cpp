/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_render_target.h"

/* The same body as FUN_00779070 at another address: two classes sharing one
 * implementation, or two instantiations. */
void FUN_007793f0(const Owner779070 *self, const Source779070 *src) /* derived name */
{
    self->target->rowB = src->a;
    self->target->rowA = src->b;
}
