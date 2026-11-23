/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"

#include "tlg_game_object016a85e0.h"

/* FUN_003254b0: the names made empty and the data cleared, in the fields'
 * order */
void Object016a85e0::reset()
{
    name24 = Name();
    name28 = Name();
    memset(unknown30, 0, sizeof(unknown30));
    unknown50 = 0;
    name58 = Name();
    memset(unknown60, 0, sizeof(unknown60));
}
