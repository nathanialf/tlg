/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_fade013d2490.h"
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_01061fe0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 8 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15c6a4c[18];
extern const char D_15c6a5e[21];
extern const char D_15c6a73[27];
extern const char D_15c6a8e[20];
extern const char D_15c6aa2[27];
extern const char D_15c6abd[23];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5ad0760(D_15cb5dd, false);
Name D_5ad0764(D_15cb5e6, false);
Name D_5ad0640(D_15c6a4c, false);
Name D_5ad0644(D_15c6a5e, false);
Name D_5ad0648(D_15c6a73, false);
Name D_5ad0670(D_15c6a8e, false);
Name D_5ad0768(D_15c6aa2, false);
Name D_5ad061c(D_15c6abd, false);

/* derived name: this file's fade entry (tlg_game_fade013d2490.h): one
 * element type per file, as the base holds one resize of them per file */
struct FadeEntry01061fe0 : FadeEntry013d2490 { /* derived name */
};

/* FUN_013f9800 */
template void Array05943280<FadeEntry01061fe0>::resize(unsigned);
