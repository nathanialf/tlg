/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores its byte argument at +0x130; slot 10 of the vtable at
 * 0x16be9a8 (its pointer at 0x16bea08), the vtable stored by FUN_00eb3c90
 * FUN_00eb3fb0; slot 9 (FUN_00ebe080) stores +0x131. The byte store of the
 * argument register (sil) is a bool's or a byte's; bool is written, as for a
 * flag beside its neighbour at +0x131. Class and method unknown. */
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

void FUN_00ebe090(Object00ebe080 *self, bool value) /* derived name */
{
    self->unknown130 = value;
}
