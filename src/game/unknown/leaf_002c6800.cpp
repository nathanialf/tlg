/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object002c5780.h"

/* derived name: FUN_002c5780's body over the array at +0x310 */
void Object002c5780::addEntry(Entry002c6800 *entry)
{
    if (entry && !entries310.contains(entry))
        entries310.push(entry);
}
