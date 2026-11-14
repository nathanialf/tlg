/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: slot 3 of the vtable at 0x16b3550 (its pointer at 0x16b3578),
 * the vtable stored by FUN_00abf490, returns the address of the object at
 * 0x582b200: the int there holds the result of FUN_013baad0 for the string
 * "AIMODE_SOL_Battle" (its hash from FUN_013bad90), stored by the file's
 * initializer at 0xac0f75, which registers Name's destructor (0x1331800) for it
 * with __cxa_atexit: a Name (tlg_game_name.h), looked up without interning
 * (`xor ecx, ecx`). The file's initializer FUN_00ac0da0 builds the vector
 * constants of tlg_game_vector.h and the file's names, below. Class and method
 * unknown. */

extern const char D_15a7b93[18];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_582b320(D_15cb5dd, false);
Name D_582b324(D_15cb5e6, false);
Name D_582b200(D_15a7b93, false);

struct Object00ac0d90;

const Name *FUN_00ac0d90(const Object00ac0d90 *self) /* derived name */
{
    return &D_582b200;
}
