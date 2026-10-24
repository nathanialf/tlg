/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_render_target.h"

void FUN_00779070(const Owner779070 *self, const Source779070 *src) /* derived name */
{
    self->target->rowB = src->a;
    self->target->rowA = src->b;
}
