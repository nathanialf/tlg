/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object0092cba0.h"

/* derived names: sets the counted reference at +0x260 of the object to
 * another object, by compare-and-swap. The referenced object's class is not
 * traced. */
void FUN_0092cba0(Object0092cba0 *self, Value0092cba0 *value) /* derived name */
{
    self->unknown260.set(value);
}
