/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_fade013d2490.h"
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_01249ca0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 5 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15c99df[38];
extern const char D_15c9a05[17];
extern const char D_15c9a16[39];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5ad7ae0(D_15cb5dd, false);
Name D_5ad7ae4(D_15cb5e6, false);
Name D_5ad79ac(D_15c99df, false);
Name D_5ad7ae8(D_15c9a05, false);
Name D_5ad79f0(D_15c9a16, false);

/* derived name: this file's fade entry (tlg_game_fade013d2490.h): one
 * element type per file, as the base holds one resize of them per file */
struct FadeEntry01249ca0 : FadeEntry013d2490 { /* derived name */
};

/* FUN_0147db50 */
template void Array05943280<FadeEntry01249ca0>::resize(unsigned);
