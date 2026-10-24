/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_types.h"

/* derived names: a virtual getter of the int at +0x28, slot 5 of the vtable
 * at 0x16a6330, beside FUN_0000d2b0 (+0x18) and FUN_000ae6a0 (+0x38).
 * Class unknown. */
struct Object0017f0f0 {
    u8 unknown0[0x28];
    s32 value;
};

int FUN_0017f0f0(const Object0017f0f0 *self) /* derived name */
{
    return self->value;
}
