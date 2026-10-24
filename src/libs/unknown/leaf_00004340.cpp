/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_types.h"

/* derived names: a virtual getter of the int at +0x20, the body behind 21
 * vtable slots in .data.rel.ro (from 0x16a3350). Class unknown. */
struct Object00004340 {
    u8 unknown0[0x20];
    s32 value;
};

int FUN_00004340(const Object00004340 *self) /* derived name */
{
    return self->value;
}
