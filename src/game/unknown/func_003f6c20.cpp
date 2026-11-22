/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_003f6c20 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt). Then, in declaration order, 4 names from
 * strings, each registered with Name's destructor (0x1331800), and a list,
 * destroyed by the array destructor the compiler writes for it (0x3f6f60).
 * What reads them is not traced. */

extern const char D_15691f5[16];
extern const char D_1569205[16];
extern const char D_1569215[15];
extern const char D_1569224[15];
extern const char D_1569233[20];
extern const char D_1569247[20];
extern const char D_156925b[11];
extern const char D_1569266[23];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_57d3478(D_15cb5dd, false);
Name D_57d35a0(D_15cb5e6, false);

static Name D_57d3430[] = {Name(D_15691f5), Name(D_1569205), Name(D_1569215),
                           Name(D_1569224), Name(D_1569233), Name(D_1569247)};

Name D_57d3470(D_156925b, false);
Name D_57d3474(D_1569266, false);
