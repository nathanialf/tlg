/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the pointer at +0x168; slot 33 of the vtable at
 * 0x16ba8e0 (its pointer at 0x16ba9f8), the vtable stored by FUN_00d5f7d0
 * FUN_013b9d70; slot 33 of the vtable at 0x16be9a8 (its pointer at 0x16beac0),
 * the vtable stored by FUN_00eb3c90 FUN_00eb3fb0 (FUN_00ebe080 and
 * FUN_00ebe090 are slots 9 and 10 of the second). The pointer's target is not
 * traced. Class and method unknown. */
struct Target013ba270; /* derived name */
struct Target013cd130; /* derived name */

struct Object00ebe080 { /* derived name */
    u8 unknown0[0x130];
    bool unknown130; /* stored by FUN_00ebe090 */
    bool unknown131; /* stored by FUN_00ebe080 */
    u8 unknown132[0x168 - 0x132];
    Target013ba270 *unknown168; /* returned by FUN_013ba270 */
    u8 unknown170[0x2e0 - 0x170];
    Target013cd130 *unknown2e0; /* stored by FUN_013cd130 */
};

Target013ba270 *FUN_013ba270(const Object00ebe080 *self) /* derived name */
{
    return self->unknown168;
}
