/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_01015800 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 5 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15c627c[41];
extern const char D_15c62a5[40];
extern const char D_15c62cd[21];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5acfaf0(D_15cb5dd, false);
Name D_5acfaf4(D_15cb5e6, false);
Name D_5acfaf8(D_15c627c);
Name D_5acfafc(D_15c62a5);
Name D_5acf9b0(D_15c62cd, false);
