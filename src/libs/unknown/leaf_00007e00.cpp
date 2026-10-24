/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: a member record's C-style array size, 0 for a plain
 * member, read by 52 direct callers; the size computation at 0x18159a
 * multiplies the element size by it, or by 1 when it is 0. */
int FUN_00007e00(const hkClassMember *self) /* derived name */
{
    return self->cArraySize;
}
