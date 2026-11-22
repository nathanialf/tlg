/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_011ed600 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then, in declaration order, 4 names,
 * each registered with Name's destructor (0x1331800), and a list, destroyed
 * by the array destructor the compiler writes (0x11edad0). What reads them
 * is not traced. */

extern const char D_15c8db4[7];
extern const char D_15c8dbb[4];
extern const char D_15c8dbf[11];
extern const char D_15c8dca[11];
extern const char D_15c8dd5[11];
extern const char D_15c8de0[11];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5ad73e0(D_15cb5dd, false);
Name D_5ad73e4(D_15cb5e6, false);
Name D_5ad73e8(D_15c8db4, false);
Name D_5ad72cc(D_15c8dbb, false);

static Name D_5ad72d0[] = {Name(D_15c8dbf), Name(D_15c8dca), Name(D_15c8dd5), Name(D_15c8de0)};
