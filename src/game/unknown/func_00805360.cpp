/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00805360 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt). Then, in declaration order, 6 names from
 * strings, each registered with Name's destructor (0x1331800), and a list,
 * destroyed by the array destructor the compiler writes for it (0x805940).
 * What reads them is not traced. */

extern const char D_1596ea2[7];
extern const char D_1596ea9[7];
extern const char D_1596eb0[7];
extern const char D_1596eb7[9];
extern const char D_159a153[6];
extern const char D_15a16ac[5];
extern const char D_15c97a7[16];
extern const char D_15c97b7[16];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_581a390(D_15cb5dd, false);
Name D_581a394(D_15cb5e6, false);

static Name D_581a250[] = {Name(D_1596ea2), Name(D_15c97b7), Name(D_1596ea9), Name(D_15c97a7)};

Name D_581a260(D_15a16ac);
Name D_5819a00(D_159a153);
Name D_5819a04(D_1596eb0);
Name D_5819a08(D_1596eb7);
