/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object012ada80.h"

/* derived names: FUN_011f4cb0 empties 11 pairs of tables (a table entry; no
 * direct caller; one of seven such functions, tlg_game_object012ada80.h):
 * with the thread set to destroy released objects itself (the flag saved,
 * set, and put back before the local list is released), the four arrays of
 * every object of the table at 0x5ad73f8 are emptied, then each pair's
 * tables are emptied and their ids given back. */
extern Tables00c1ac70 D_5ad73f0;
extern Tables00c1ac70 D_5ad7588;
extern Tables00c1ac70 D_5ad7758;
extern Tables00c1ac70 D_5ad7918;
extern Tables00c1ac70 D_5ad7af0;
extern Tables00c1ac70 D_5ad7c58;
extern Tables00c1ac70 D_5ad7e98;
extern Tables00c1ac70 D_5ad8008;
extern Tables00c1ac70 D_5ad8298;
extern Tables00c1ac70 D_5ad8408;
extern Tables00c1ac70 D_5ad8578;

void FUN_011f4cb0() /* derived name */
{
    bool previous = D_16dc088;
    D_16dc088 = true;
    Array01343a80<Object00cb8240 *> objects;
    unsigned count = FUN_00cb8240(D_5ad73f0.second, &objects);
    for (unsigned i = 0; i < count; ++i) {
        static_cast<Object012ada80 *>(objects.at(i))->array30.clear();
        static_cast<Object012ada80 *>(objects.at(i))->array48.clear();
        static_cast<Object012ada80 *>(objects.at(i))->array60.clear();
        static_cast<Object012ada80 *>(objects.at(i))->array78.clear();
    }
    empty(D_5ad8578);
    empty(D_5ad8008);
    empty(D_5ad8298);
    empty(D_5ad7c58);
    empty(D_5ad7588);
    empty(D_5ad7918);
    empty(D_5ad7758);
    empty(D_5ad8408);
    empty(D_5ad7e98);
    empty(D_5ad7af0);
    empty(D_5ad73f0);
    D_16dc088 = previous;
}
