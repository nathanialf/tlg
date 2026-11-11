/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: slot 3 of the vtable at 0x16b35a0 (its pointer at 0x16b35c8),
 * the vtable stored by FUN_00abf490, returns the address of the object at
 * 0x582b328: the int there holds the result of FUN_013baad0 for the string
 * "AIMODE_SOL_Chant" (its hash from FUN_013bad90), stored by the file's
 * initializer at 0xac139a, which registers Name's destructor (0x1331800) for it
 * with __cxa_atexit: a Name (tlg_game_name.h), looked up without interning
 * (`xor ecx, ecx`). Declared extern: the initializer's direct store makes it
 * the file's own (D17), and that initializer is not written. Class and method
 * unknown. */

extern Name D_582b328;

struct Object00ac1230;

const Name *FUN_00ac1230(const Object00ac1230 *self) /* derived name */
{
    return &D_582b328;
}
