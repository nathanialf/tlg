/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: a member record's enum class, at +0x10. The body sits
 * among the member-record accessors (FUN_00007e00, 0x7f60, 0x7f90) and is
 * the one every reference to an 8-byte load from +0x10 reaches: 27 direct
 * callers, among them 0x481b on &members[i] of an hkClass, and seven
 * vtable slots of other classes (0x16a61a8 onward). The identical body at
 * 0x7f70 has no reference at all (docs/NOTES.md, folded bodies). */
const hkClassEnum *FUN_00007f80(const hkClassMember *self) /* derived name */
{
    return self->enumClass;
}
