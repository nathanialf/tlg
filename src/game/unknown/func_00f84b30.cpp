/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_fade013d2490.h"
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00f84b30 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 5 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15c5687[10];
extern const char D_15c5691[17];
extern const char D_15c56a2[22];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5aceda0(D_15cb5dd, false);
Name D_5aceda4(D_15cb5e6, false);
Name D_5acecb4(D_15c5687, false);
Name D_5acecb0(D_15c5691, false);
Name D_5acec50(D_15c56a2, false);

/* derived name: this file's fade entry (tlg_game_fade013d2490.h): one
 * element type per file, as the base holds one resize of them per file */
struct FadeEntry00f84b30 : FadeEntry013d2490 { /* derived name */
};

/* FUN_013d92a0 */
template void Array05943280<FadeEntry00f84b30>::resize(unsigned);
