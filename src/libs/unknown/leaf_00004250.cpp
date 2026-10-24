/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: an hkClass's parent class. The body sits beside the hkClass
 * constructor (FUN_000041a0) and FUN_00004200, and is the one every
 * reference to an 8-byte load from +8 reaches: 31 direct callers, some
 * walking the parent chain (0x19f050), some passing a member record and
 * getting its class (0x47da, 0x19f0c5). The identical body among the
 * member-record accessors at 0x7f60 has no reference at all (docs/NOTES.md,
 * folded bodies). */
const hkClass *FUN_00004250(const hkClass *self) /* derived name */
{
    return self->parent;
}
