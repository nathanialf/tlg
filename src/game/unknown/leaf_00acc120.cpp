/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: slot 3 of the vtable at 0x16b3870 (its pointer at 0x16b3898),
 * the vtable stored by FUN_00abf490, returns the address of the object at
 * 0x582c040: the int there holds the result of FUN_013baad0 for the string
 * "AIMODE_SOL_PullHelm" (its hash from FUN_013bad90), stored by the file's
 * initializer at 0xacc29c, which registers Name's destructor (0x1331800) for it
 * with __cxa_atexit: a Name (tlg_game_name.h), looked up without interning
 * (`xor ecx, ecx`). The file's initializer FUN_00acc130 builds the vector
 * constants of tlg_game_vector.h and the file's names, below. Class and method
 * unknown. */

extern const char D_14b31ee[5];
extern const char D_14b31f3[6];
extern const char D_15a7ed2[20];
extern const char D_15a7ee6[30];
extern const char D_15a7f04[18];
extern const char D_15a7f16[17];
extern const char D_15a7f27[15];

Name D_582c040(D_15a7ed2, false);
Name D_582c03c(D_14b31ee, false);
Name D_582c180(D_14b31f3, false);
Name D_582c038(D_15a7ee6, false);
Name D_582c030(D_15a7f04, false);
Name D_582c034(D_15a7f16, false);
Name D_582c184(D_15a7f27, false);

struct Object00acc120;

const Name *FUN_00acc120(const Object00acc120 *self) /* derived name */
{
    return &D_582c040;
}
