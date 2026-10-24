/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_types.h"

/* derived names: a setter of the int at +0xc; the game code at 0xeaa625
 * calls it with 1 on the object it has just passed to FUN_0003e840. Class
 * unknown. */
struct Object0003ea60 {
    u8 unknown0[0xc];
    s32 value;
};

void FUN_0003ea60(Object0003ea60 *self, int value) /* derived name */
{
    self->value = value;
}
