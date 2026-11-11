/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_libc.h"

/* derived names: a character mapping that FUN_00de1650 (lea at 0xde1654) passes to
 * FUN_00de2e90: -1 for -1, else the entry of the C library's table (_Getptolower)
 * for the character as an unsigned char. */
int FUN_00de2e60(int c) /* derived name */
{
    if (c == -1) {
        return -1;
    }
    return _Getptolower()[static_cast<u8>(c)];
}
