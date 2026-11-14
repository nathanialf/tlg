/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: slot 3 of the vtable at 0x16b3960 (its pointer at 0x16b3988),
 * the vtable stored by FUN_00abf490, returns the address of the object at
 * 0x582c4c0: the int there holds the result of FUN_013baad0 for the string
 * "AIMODE_SOL_Waiting" (its hash from FUN_013bad90), stored by the file's
 * initializer at 0xacdb1a, which registers Name's destructor (0x1331800) for it
 * with __cxa_atexit: a Name (tlg_game_name.h), looked up without interning
 * (`xor ecx, ecx`). The file's initializer FUN_00acd9c0 builds the vector
 * constants of tlg_game_vector.h and the file's names, below. Class and method
 * unknown. */

extern const char D_15a800d[19];

Name D_582c4c0(D_15a800d, false);

struct Object00acd9b0;

const Name *FUN_00acd9b0(const Object00acd9b0 *self) /* derived name */
{
    return &D_582c4c0;
}
