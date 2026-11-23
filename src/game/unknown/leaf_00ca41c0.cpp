/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_table00ca41c0.h"

Object016b9108 *Table00ca41c0::find(unsigned id) const
{
    AtomicRef0045c470<Object016b9108> found;
    for (const Node00ca41c0 *node = buckets[id & 31]; node; node = node->next10) {
        if (node->id0 == id && node->id4 == id) {
            found = node->value8;
            break;
        }
    }
    return found.get();
}
