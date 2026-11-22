/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00685a40 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 3 names from strings, each
 * registered with Name's destructor (0x1331800), then a list of 3 names,
 * destroyed by the array destructor the compiler writes for it (0x685cd0),
 * in this order. The name at 0x58136b8 is read by FUN_0060dae0 and
 * FUN_00681b50; what reads the list is not traced. */

extern const char D_158c94e[13];
extern const char D_15ca12f[10];
extern const char D_15ca367[8];
extern const char D_15ca7dc[12];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5813f40(D_15cb5dd, false);
Name D_5813f44(D_15cb5e6, false);
Name D_58136b8(D_158c94e);

static Name D_5813e30[] = {Name(D_15ca7dc), Name(D_15ca367), Name(D_15ca12f)};
