/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: a member record fix-up that FUN_0019eee0 hands to the
 * member walk FUN_0019f110 (with 2): a member reflected as a pointer to
 * char becomes a C string. */
void FUN_0019f1f0(hkClassMember *member) /* derived name */
{
    if (member->type == hkClassMember::TYPE_POINTER &&
        member->subtype == hkClassMember::TYPE_CHAR) {
        member->type = hkClassMember::TYPE_CSTRING;
        member->subtype = hkClassMember::TYPE_VOID;
    }
}
