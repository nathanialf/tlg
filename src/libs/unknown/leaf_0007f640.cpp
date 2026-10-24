/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_types.h"

/* derived names: a virtual getter of the flag byte at +0x10, slot 8 of two
 * vtables in .data.rel.ro (0x169d900, 0x16a3588). Class unknown. */
struct Object0007f640 {
    u8 unknown0[0x10];
    bool flag;
};

bool FUN_0007f640(const Object0007f640 *self) /* derived name */
{
    return self->flag;
}
