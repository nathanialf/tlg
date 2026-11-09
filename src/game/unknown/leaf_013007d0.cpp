/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores its pointer argument at +0x1d10; slot 7 of the vtable
 * at 0x16c3808 (its pointer at 0x16c3850), the vtable stored by FUN_012ffc30
 * FUN_013001f0 FUN_013002e0. The pointer's target is not traced. Class and
 * method unknown. */
struct Target013007d0; /* derived name */
struct Target01496ad0; /* derived name */

struct Object013007d0 { /* derived name */
    u8 unknown0[0x1d10];
    Target013007d0 *unknown1d10; /* stored by FUN_013007d0 */
    u8 unknown1d18[0x2318 - 0x1d18];
    Target01496ad0 *unknown2318; /* stored by FUN_01496ad0, returned by FUN_01496ae0 */
};

void FUN_013007d0(Object013007d0 *self, Target013007d0 *value) /* derived name */
{
    self->unknown1d10 = value;
}
