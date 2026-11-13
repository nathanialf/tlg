/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object01476130.h"

/* derived names: the setter beside the getter FUN_014763a0: the counted
 * reference at +0x17a0 of the object takes the value of another one, by
 * compare-and-swap. */
void FUN_014762e0(Object01476130 *self,
                  const AtomicRef0045c470<Node00503fb0> &value) /* derived name */
{
    self->unknown17a0 = value;
}
