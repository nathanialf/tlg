/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_entry009683f0.h"

void FUN_00d24260(Node0092d740 *node); /* derived name */
void FUN_00c5a160(Node0092d740 *node); /* derived name */

/* derived name: an entry not yet stopped (flag 0x20 clear) is stopped: its
 * low flags cleared and its node flagged, slot 1 of each of its objects
 * called last first, the int at +0xe0 set and the one at +0xf0 cleared,
 * its node emptied (FUN_00d24260), flagged again and handed to
 * FUN_00c5a160, then the entry marked stopped */
void FUN_0092d740(Entry009683f0 *entry) /* derived name */
{
    if (entry->flags & 0x20)
        return;
    entry->flags &= ~3u;
    entry->node->flags38 |= 1;
    entry->flags &= ~0xcu;
    for (int i = entry->count - 1; i != -1; --i)
        entry->items[i]->slot1();
    entry->unknowne0 = 1;
    entry->unknownf0 = 0;
    Node0092d740 *node = entry->node;
    FUN_00d24260(node);
    node->flags38 |= 1;
    FUN_00c5a160(entry->node);
    entry->flags |= 0x20;
}
