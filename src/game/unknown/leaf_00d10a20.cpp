/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_indices00d10a20.h"

/* derived names: the indices the first table (+0x4b8) gives the names,
 * appended in the names' order (FUN_00786cb0 calls it) */
void FUN_00d10a20(const Indices00d10a20 *self, Array05943280<int> *indices,
                  const Array05943280<Name> *names) /* derived name */
{
    Indices00d10a20::collect(self->first, *indices, *names);
}
