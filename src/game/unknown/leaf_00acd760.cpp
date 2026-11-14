/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: slot 3 of the vtable at 0x16b3910 (its pointer at 0x16b3938),
 * the vtable stored by FUN_00abf490, returns the address of the object at
 * 0x582c384: the int there holds the result of FUN_013baad0 for the string
 * "AIMODE_SOL_Stagger" (its hash from FUN_013bad90), stored by the file's
 * initializer FUN_00acd770 (the store at 0xacd8dc), which registers Name's
 * destructor (0x1331800) for it with __cxa_atexit: a Name (tlg_game_name.h)
 * looked up without interning (`xor ecx, ecx`, length 0x12). The
 * initializer then builds the Name at 0x582c380 ("s_Cling_Start", length
 * 0xd) and registers it the same way. Class and method unknown. */

extern const char D_15a7fec[19];
extern const char D_15a7fff[14];

Name D_582c384(D_15a7fec, false);
Name D_582c380(D_15a7fff, false);

struct Object00acd760;

const Name *FUN_00acd760(const Object00acd760 *self) /* derived name */
{
    return &D_582c384;
}
