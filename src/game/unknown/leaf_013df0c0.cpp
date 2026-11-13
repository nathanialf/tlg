/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013cfb60.h"

/* derived names: the setter beside the getter FUN_013dd790: the counted
 * reference at +0x1d38 of the object takes the value of another one, by
 * compare-and-swap. */
void FUN_013df0c0(Object013cfb60 *self,
                  const AtomicRef0045c470<Node00503fb0> &value) /* derived name */
{
    self->unknown1d38 = value;
}
