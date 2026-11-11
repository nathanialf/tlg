/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_libc.h"

/* derived names: a character mapping that FUN_00de1630 (lea at 0xde1634) passes to
 * FUN_00de2e90: -1 for -1, else the entry of the C library's table (_Getptoupper)
 * for the character as an unsigned char. */
int FUN_00de3000(int c) /* derived name */
{
    if (c == -1) {
        return -1;
    }
    return _Getptoupper()[static_cast<u8>(c)];
}
