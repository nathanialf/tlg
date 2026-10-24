/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: a non-virtual getter returning the address of the vector
 * at +0x30, beside the setter FUN_0003ea60 of the same class. No direct
 * call reaches it; a game class's identical body was folded onto it, so it
 * also fills slot 4 of the vtable at 0x16b1508. */
Vec4 *FUN_0003ea80(Object0003ea60 *self) /* derived name */
{
    return &self->vector;
}
