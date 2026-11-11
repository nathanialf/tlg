/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback FUN_0094db10 passes to FUN_01370670 (lea at
 * 0x95005d) with the address of a local pointer as its context: for an object
 * whose pointer at +0x18 is not the one the pointer at 0x59385b8 holds and
 * whose pointer at +0x98 is not null, stores that pointer through the context.
 * The objects' types are not traced. */
struct Object00b43eb0 { /* derived name */
    u8 unknown0[0x18];
    void *unknown18;
    u8 unknown20[0x78];
    void *unknown98;
};

extern void *D_59385b8;

void FUN_00b43eb0(Object00b43eb0 *object, void **result) /* derived name */
{
    if (object && object->unknown18 != D_59385b8 && object->unknown98)
        *result = object->unknown98;
}
