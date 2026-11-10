/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores the two vectors its argument points to at +0x60 and
 * +0x70 (aligned 16-byte loads and stores); slot 0 of the vtable at 0x16d4ba0
 * (its pointer at 0x16d4bb0); slot 0 of the vtable at 0x16d4be0 (its pointer
 * at 0x16d4bf0); and 63 more pointers. The pair's meaning is not traced. Class
 * and method unknown. */
#include "tlg_simd.h"

struct Pair013e7660 { /* derived name */
    Vec4 unknown0;
    Vec4 unknown10;
};

struct Object013e7660 { /* derived name */
    u8 unknown0[0x60];
    Pair013e7660 unknown60;
};

void FUN_013e7660(Object013e7660 *self, const Pair013e7660 *value) /* derived name */
{
    self->unknown60.unknown0 = value->unknown0;
    self->unknown60.unknown10 = value->unknown10;
}
