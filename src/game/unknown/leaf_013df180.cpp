/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013cfb60.h"

/* derived names: the setter beside the getter FUN_013dd7a0: the counted
 * reference at +0x1d40 of the object takes the value of another one, by
 * compare-and-swap. */
void FUN_013df180(Object013cfb60 *self,
                  const AtomicRef0045c470<Node00503fb0> &value) /* derived name */
{
    self->unknown1d40 = value;
}
