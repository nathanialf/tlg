/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_simd.h"
#include "tlg_types.h"

/* derived names: slot 4 of the vtable at 0x16a3e00 returns the address of
 * the vector at +0x10. FUN_00127a50 builds the object on its stack (the
 * vtable, an int at +8, a float at +0xc, the vector, an int at +0x20) and
 * hands it to FUN_00104000. Class unknown. */
struct Query00127a50 {
    void *vtable;
    s32 value8;
    float valueC;
    Vec4 vector; /* +0x10 */
    s32 value20;
};

Vec4 *FUN_00128640(Query00127a50 *self) /* derived name */
{
    return &self->vector;
}
