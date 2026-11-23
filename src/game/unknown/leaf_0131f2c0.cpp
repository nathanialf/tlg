/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object01499f30.h"

/* slot 4 of the vtables at 0x16c3b40 and 0x16c3b90 (+0x30 from each), a
 * tail call; any other kind does nothing. */
void Object01499f30::End(Context01499f30 *context)
{
    switch (desc.Query) {
    case 2:
        context->slot28(block);
        break;
    case 1:
    case 5:
        context->slot30(block);
        break;
    }
}
