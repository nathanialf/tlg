/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_003243b0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 6 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_1564ba3[14];
extern const char D_1564bb1[15];
extern const char D_1564bc0[15];
extern const char D_15ca420[7];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_57cd500(D_15ca420, false);
Name D_57cd504(D_15cb5dd, false);
Name D_57cd508(D_15cb5e6, false);
/* derived name: a vector of the file's own (pool 0x1528d60) */
static const Vector4 D_57cd3c0(12.0f, 1e+01f, 12.0f, 1.0f);
/* derived name: a vector of the file's own (pool 0x1528d70) */
static const Vector4 D_57cd380(0.01f, 1e+01f, 0.01f, 1.0f);
Name D_57cd394(D_1564ba3);
Name D_57cd390(D_1564bb1);
Name D_57cd398(D_1564bc0);
