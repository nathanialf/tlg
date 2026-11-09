/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: seeds the C library's generator (srand) with the value
 * FUN_00dbf960 returns for the object and 1, and returns 0; the pointer at
 * 0x16bcc98 holds it. The types are not traced. Class and method unknown. */
#include "tlg_libc.h"

struct Object00dc0190; /* derived name */

unsigned int FUN_00dbf960(Object00dc0190 *self, int); /* derived name */

int FUN_00dc0190(Object00dc0190 *self) /* derived name */
{
    srand(FUN_00dbf960(self, 1));
    return 0;
}
