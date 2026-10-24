/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_types.h"

/* derived names: a virtual getter of the int at +0x58, the body behind one
 * vtable slot in .data.rel.ro (0x168d950). Class unknown. */
struct Object0000e160 {
    u8 unknown0[0x58];
    s32 value;
};

int FUN_0000e160(const Object0000e160 *self) /* derived name */
{
    return self->value;
}
