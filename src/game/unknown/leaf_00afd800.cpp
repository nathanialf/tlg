/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: copies the 16-byte vector at +0x140 of the object its second
 * argument points to into the one at +0x220 of the record at +0x40 of the
 * object the pointer at 0x57c9390 holds (aligned moves); slot 9 of the vtables
 * at 0x16abef8 (its pointer at 0x16abf50, stored by FUN_0061ab50) and
 * 0x16abf70 (0x16abfc8, stored by FUN_0061c160). The first argument is not
 * read; the classes are not traced. */
#include "tlg_simd.h"

struct Object00afd800; /* derived name */

struct Argument00afd800 { /* derived name */
    u8 unknown0[0x140];
    Vec4 unknown140;
};

struct Member057c9390_40 { /* derived name */
    u8 unknown0[0x220];
    Vec4 unknown220;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x40];
    Member057c9390_40 *unknown40;
};

extern Object057c9390 *D_57c9390;

void FUN_00afd800(Object00afd800 *, const Argument00afd800 *object) /* derived name */
{
    D_57c9390->unknown40->unknown220 = object->unknown140;
}
