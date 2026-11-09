/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores 0 in the int at +0x40c of the record its second
 * argument points to; slot 2 of the vtable at 0x16ae178 (its pointer at
 * 0x16ae198), no storing constructor listed. The first argument (the object)
 * is not used. Class and method unknown. */
struct Object00805320; /* derived name */

struct Target00805320 { /* derived name */
    u8 unknown0[0x40c];
    int unknown40c;
};

void FUN_00805320(Object00805320 *, Target00805320 *target) /* derived name */
{
    target->unknown40c = 0;
}
