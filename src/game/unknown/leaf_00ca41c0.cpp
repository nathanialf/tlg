/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: a node of the table below: two ids, the counted object
 * and the next node of its bucket */
struct Node00ca41c0 /* derived name */
{
    unsigned id0;                             /* +0x0 */
    unsigned id4;                             /* +0x4 */
    AtomicRef0045c470<Object016b9108> value8; /* +0x8 */
    Node00ca41c0 *next10;                     /* +0x10 */
};

/* derived names: a table of 32 buckets of nodes chained at +0x10, by the
 * id's low five bits */
struct Table00ca41c0 /* derived name */
{
    /* 0xca41c0: the object of the node whose two ids are `id`, or null;
     * the found object is copied into a reference of its own, whose pointer
     * is answered as the reference is dropped */
    Object016b9108 *find(unsigned id) const; /* derived name */

    Node00ca41c0 *buckets[32];
};

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
