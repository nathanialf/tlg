/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_types.h"

/* derived names: a virtual getter of the int at +0x18, the body behind 15
 * vtable slots in .data.rel.ro (from 0x1692568). Class unknown. */
struct Object0002abc0 {
    u8 unknown0[0x18];
    s32 value;
};

int FUN_0002abc0(const Object0002abc0 *self) /* derived name */
{
    return self->value;
}
