/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object012ada80.h"

/* derived names: FUN_00f27820 empties 18 pairs of tables (a table entry; no
 * direct caller; one of seven such functions, tlg_game_object012ada80.h):
 * with the thread set to destroy released objects itself (the flag saved,
 * set, and put back before the local list is released), the four arrays of
 * every object of the table at 0x5ace520 are emptied, then each pair's
 * tables are emptied and their ids given back. */
extern Tables00c1ac70 D_5ace518;
extern Tables00c1ac70 D_5ace6b8;
extern Tables00c1ac70 D_5ace8d0;
extern Tables00c1ac70 D_5aceaa8;
extern Tables00c1ac70 D_5acec18;
extern Tables00c1ac70 D_5acedc0;
extern Tables00c1ac70 D_5acef48;
extern Tables00c1ac70 D_5acf128;
extern Tables00c1ac70 D_5acf298;
extern Tables00c1ac70 D_5acf5c8;
extern Tables00c1ac70 D_5acf738;
extern Tables00c1ac70 D_5acf978;
extern Tables00c1ac70 D_5acfb28;
extern Tables00c1ac70 D_5acfdb8;
extern Tables00c1ac70 D_5acff28;
extern Tables00c1ac70 D_5ad01b8;
extern Tables00c1ac70 D_5ad05d8;
extern Tables00c1ac70 D_5ad0788;

void FUN_00f27820() /* derived name */
{
    bool previous = D_16dc088;
    D_16dc088 = true;
    Array01343a80<Object016b9108 *> objects;
    unsigned count = FUN_00cb8240(D_5ace518.second, &objects);
    for (unsigned i = 0; i < count; ++i) {
        static_cast<Object012ada80 *>(objects.at(i))->array30.clear(0);
        static_cast<Object012ada80 *>(objects.at(i))->array48.clear(0);
        static_cast<Object012ada80 *>(objects.at(i))->array60.clear(0);
        static_cast<Object012ada80 *>(objects.at(i))->array78.clear(0);
    }
    empty(D_5ad0788);
    empty(D_5acff28);
    empty(D_5acfb28);
    empty(D_5ad01b8);
    empty(D_5acf298);
    empty(D_5acedc0);
    empty(D_5aceaa8);
    empty(D_5acf738);
    empty(D_5ad05d8);
    empty(D_5ace6b8);
    empty(D_5acec18);
    empty(D_5acef48);
    empty(D_5ace8d0);
    empty(D_5acf978);
    empty(D_5acfdb8);
    empty(D_5acf128);
    empty(D_5acf5c8);
    empty(D_5ace518);
    D_16dc088 = previous;
}
