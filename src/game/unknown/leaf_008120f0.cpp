/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: copies the vector at +0xf0 of the record the pointer at +0x28
 * of its argument holds to +0x50 of the argument, null skipped; the object is
 * unused; slot 13 of the vtable at 0x16ae4d0 (its pointer at 0x16ae548). Class
 * and method unknown. */
#include "tlg_simd.h"

struct Object008120f0; /* derived name */

struct Record008120f0 { /* derived name */
    u8 unknown0[0xf0];
    Vec4 unknownf0;
};

struct Target008120f0 { /* derived name */
    u8 unknown0[0x28];
    Record008120f0 *unknown28;
    u8 unknown30[0x20];
    Vec4 unknown50;
};

void FUN_008120f0(Object008120f0 *, Target008120f0 *target) /* derived name */
{
    if (target->unknown28) {
        target->unknown50 = target->unknown28->unknownf0;
    }
}
