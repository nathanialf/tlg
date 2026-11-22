/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_0067f1e0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt). Then, in declaration order, 2 names from
 * strings, each registered with Name's destructor (0x1331800), and a list,
 * destroyed by the array destructor the compiler writes for it (0x67f4d0).
 * What reads them is not traced. */

extern const char D_15ca27a[9];
extern const char D_15ca283[10];
extern const char D_15ca28d[10];
extern const char D_15cb0f3[13];
extern const char D_15cb254[8];
extern const char D_15cb25c[10];
extern const char D_15cb266[10];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5813570(D_15cb5dd, false);
Name D_5813574(D_15cb5e6, false);

static Name D_5813450[] = {Name(D_15cb254), Name(D_15cb25c), Name(D_15cb266), Name(D_15ca28d),
                           Name(D_15ca283), Name(D_15ca27a), Name(D_15cb0f3)};
