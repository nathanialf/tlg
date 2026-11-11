/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: whether either of bits 4 and 5 of the byte at +0xe7c of the
 * record the pointer at 0x5938c40 holds is set. The pointer is the game's
 * object (config/modules.base.txt): the base loads it PC-relative, as the
 * game module's stand-in for it compiles. Class and method unknown. */
struct Object05938c40 /* derived name */
{
    u8 unknown0[0xe7c];
    u8 unknownE7c;
};

extern Object05938c40 *D_5938c40;

bool FUN_00b10d80() /* derived name */
{
    return (D_5938c40->unknownE7c & 0x30) != 0;
}
