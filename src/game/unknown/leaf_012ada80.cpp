/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object012ada80.h"

/* derived names: FUN_012ada80 empties 2 pairs of tables (a table entry; no
 * direct caller; one of seven such functions, tlg_game_object012ada80.h):
 * with the thread set to destroy released objects itself (the flag saved,
 * set, and put back before the local list is released), the four arrays of
 * every object of the table at 0x5ad8f10 are emptied, then each pair's
 * tables are emptied and their ids given back. */
extern Tables00c1ac70 D_5ad8f08;
extern Tables00c1ac70 D_5ad90a8;

void FUN_012ada80() /* derived name */
{
    bool previous = D_16dc088;
    D_16dc088 = true;
    Array01343a80<Object00cb8240 *> objects;
    unsigned count = FUN_00cb8240(D_5ad8f08.second, &objects);
    for (unsigned i = 0; i < count; ++i) {
        static_cast<Object012ada80 *>(objects.at(i))->array30.clear();
        static_cast<Object012ada80 *>(objects.at(i))->array48.clear();
        static_cast<Object012ada80 *>(objects.at(i))->array60.clear();
        static_cast<Object012ada80 *>(objects.at(i))->array78.clear();
    }
    empty(D_5ad90a8);
    empty(D_5ad8f08);
    D_16dc088 = previous;
}
