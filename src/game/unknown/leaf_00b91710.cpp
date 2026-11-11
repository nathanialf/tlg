/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 14 of the vtable at 0x16b7148 (stored by FUN_00b8c400
 * FUN_00b8e610): calls FUN_012fdf60 with 1 on the objects at +0x100b8 and
 * +0x100e8 of the record the pointer at +0x2c8 holds, and returns 1. The
 * types and the return type are not traced. Class and method unknown. */
struct Target012fdf60; /* derived name */

struct Record00b91710 { /* derived name */
    u8 unknown0[0x100b8];
    Target012fdf60 *unknown100b8; /* +0x100b8 */
    u8 unknown100c0[0x28];
    Target012fdf60 *unknown100e8; /* +0x100e8 */
};

struct Object00b91710 { /* derived name */
    u8 unknown0[0x2c8];
    Record00b91710 *unknown2c8; /* +0x2c8 */
};

void FUN_012fdf60(Target012fdf60 *target, int value); /* derived name */

int FUN_00b91710(Object00b91710 *self) /* derived name */
{
    Record00b91710 *record = self->unknown2c8;
    FUN_012fdf60(record->unknown100b8, 1);
    FUN_012fdf60(record->unknown100e8, 1);
    return 1;
}
