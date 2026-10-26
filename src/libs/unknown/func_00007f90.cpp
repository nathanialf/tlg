/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the integer value of a member at an address (its
 * callers at 0x1a0bf3, 0x1a1266, 0x1a15cb): read by the member's
 * type and subtype. */
s64 hkClassMember::FUN_00007f90(const void *address) const /* derived name */
{
    return FUN_00091270(static_cast<Type>(type), static_cast<Type>(subtype), address);
}
