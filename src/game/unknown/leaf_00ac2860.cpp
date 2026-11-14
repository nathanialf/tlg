/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: slot 3 of the vtable at 0x16b3640 (its pointer at 0x16b3668),
 * the vtable stored by FUN_00abf490, returns the address of the object at
 * 0x582b5b8: the int there holds the result of FUN_013baad0 for the string
 * "AIMODE_SOL_Collect" (its hash from FUN_013bad90), stored by the file's
 * initializer at 0xac2ac2, which registers Name's destructor (0x1331800) for it
 * with __cxa_atexit: a Name (tlg_game_name.h), looked up without interning
 * (`xor ecx, ecx`). The file's initializer FUN_00ac2870 builds the vector
 * constants of tlg_game_vector.h and the file's names, below. Class and method
 * unknown. */

extern const char D_15a7bc7[14];
extern const char D_15a7bd5[14];
extern const char D_15a7be3[14];
extern const char D_15a7bf1[14];
extern const char D_15a7bff[19];
extern const char D_15a7c12[19];
extern const char D_15a8a50[14];
extern const char D_15a8a97[29];

Name D_582b5a4(D_15a7bc7, false);
Name D_582b5a8(D_15a7bd5, false);
Name D_582b5ac(D_15a7be3, false);
Name D_582b5b0(D_15a7bf1, false);
Name D_582b5b8(D_15a7bff, false);
Name D_582b5b4(D_15a7c12, false);
Name D_582b6f0(D_15a8a50, false);
Name D_582b5a0(D_15a8a97, false);

struct Object00ac2860;

const Name *FUN_00ac2860(const Object00ac2860 *self) /* derived name */
{
    return &D_582b5b8;
}
