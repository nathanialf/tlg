/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object01499f30.h"

/* slot 3 of the vtables at 0x16c3b40 and 0x16c3b90 (their pointers at
 * 0x16c3b68 and 0x16c3bb8), a tail call. The class's key function, so this
 * file emits Object01499f30's vtable. */
void Object01499f30::Begin(Context01499f30 *context)
{
    if (desc.Query == 1 || desc.Query == 5) {
        context->slot29(block);
    }
}
