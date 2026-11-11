/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns bit 0 of the 32-bit word at +0x4c of the record at
 * +0x100 of the object the pointer at 0x57c9390 holds; slot 2 of the vtable at
 * 0x16afd20 (its pointer at 0x16afd40), stored by FUN_0088b4e0, its slots 0
 * and 1 FUN_008b1a60 and FUN_008b1aa0. The object itself is not read. */
struct Object008b1ae0; /* derived name */

struct Member057c9390_100 { /* derived name */
    u8 unknown0[0x4c];
    unsigned unknown4c;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x100];
    Member057c9390_100 *unknown100;
};

extern Object057c9390 *D_57c9390;

unsigned FUN_008b1ae0(Object008b1ae0 *) /* derived name */
{
    return D_57c9390->unknown100->unknown4c & 1;
}
