/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object012ada80.h"

/* derived names: FUN_010749f0 empties 18 pairs of tables (a table entry; no
 * direct caller; one of seven such functions, tlg_game_object012ada80.h):
 * with the thread set to destroy released objects itself (the flag saved,
 * set, and put back before the local list is released), the four arrays of
 * every object of the table at 0x5ad0a50 are emptied, then each pair's
 * tables are emptied and their ids given back. */
extern Tables00c1ac70 D_5ad0a48;
extern Tables00c1ac70 D_5ad0be8;
extern Tables00c1ac70 D_5ad10c8;
extern Tables00c1ac70 D_5ad1250;
extern Tables00c1ac70 D_5ad13c8;
extern Tables00c1ac70 D_5ad18e8;
extern Tables00c1ac70 D_5ad1ef8;
extern Tables00c1ac70 D_5ad2858;
extern Tables00c1ac70 D_5ad2ae8;
extern Tables00c1ac70 D_5ad3be8;
extern Tables00c1ac70 D_5ad40d8;
extern Tables00c1ac70 D_5ad4780;
extern Tables00c1ac70 D_5ad4c68;
extern Tables00c1ac70 D_5ad5580;
extern Tables00c1ac70 D_5ad6210;
extern Tables00c1ac70 D_5ad6398;
extern Tables00c1ac70 D_5ad6b08;
extern Tables00c1ac70 D_5ad7270;

void FUN_010749f0() /* derived name */
{
    bool previous = D_16dc088;
    D_16dc088 = true;
    Array01343a80<Object016b9108 *> objects;
    unsigned count = FUN_00cb8240(D_5ad0a48.second, &objects);
    for (unsigned i = 0; i < count; ++i) {
        static_cast<Object012ada80 *>(objects.at(i))->array30.clear();
        static_cast<Object012ada80 *>(objects.at(i))->array48.clear();
        static_cast<Object012ada80 *>(objects.at(i))->array60.clear();
        static_cast<Object012ada80 *>(objects.at(i))->array78.clear();
    }
    empty(D_5ad7270);
    empty(D_5ad10c8);
    empty(D_5ad4c68);
    empty(D_5ad6210);
    empty(D_5ad1250);
    empty(D_5ad5580);
    empty(D_5ad1ef8);
    empty(D_5ad3be8);
    empty(D_5ad0be8);
    empty(D_5ad2ae8);
    empty(D_5ad40d8);
    empty(D_5ad2858);
    empty(D_5ad6b08);
    empty(D_5ad6398);
    empty(D_5ad13c8);
    empty(D_5ad18e8);
    empty(D_5ad4780);
    empty(D_5ad0a48);
    D_16dc088 = previous;
}
