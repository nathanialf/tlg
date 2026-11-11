/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the float at +0x50 times 100 of the record at +0x100
 * of the object the pointer at 0x57c9390 holds; slot 2 of the vtable at
 * 0x16afa50 (its pointer at 0x16afa70), stored by FUN_0088b4e0, its slots 0
 * and 1 FUN_008b0bf0 and FUN_008b0c30. The object itself is not read. */
struct Object008b0c70; /* derived name */

struct Member057c9390_100 { /* derived name */
    u8 unknown0[0x50];
    float unknown50;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x100];
    Member057c9390_100 *unknown100;
};

extern Object057c9390 *D_57c9390;

float FUN_008b0c70(Object008b0c70 *) /* derived name */
{
    return D_57c9390->unknown100->unknown50 * 100.0f;
}
