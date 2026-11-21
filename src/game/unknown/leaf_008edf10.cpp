/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b0468.h"

void FUN_008e1020(Manager008e1020 *manager, Object016b0468 *object); /* derived name */

/* derived name: the complete destructor (tlg_game_object016b0468.h). The
 * destructor is the class's key function, so this file emits the vtable and
 * the deleting destructor 0x8ee0d0, which calls this one. */
Object016b0468::~Object016b0468()
{
    if (registered) {
        if (Manager008e1020 *manager = D_57c9390->unknown80) {
            FUN_008e1020(manager, this);
            registered = 0;
            unknown5c = 0;
        }
        unknown58 = 1;
    }
}
