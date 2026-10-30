/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the member's zero type and deprecated size flags replaced
 * by their current form. */
void FUN_0019f210(hkClassMember *member)
{
    if (member->type == hkClassMember::TYPE_ZERO) {
        member->type = member->subtype;
        member->subtype = hkClassMember::TYPE_VOID;
        member->flags.orWith(hkClassMember::SERIALIZE_IGNORED);
    }
    switch (member->type) {
    case hkClassMember::TYPE_ENUM:
    case hkClassMember::TYPE_FLAGS:
        if (member->flags.get(hkClassMember::DEPRECATED_ENUM_8)) {
            member->subtype = hkClassMember::TYPE_UINT8;
            member->flags.clear(hkClassMember::DEPRECATED_ENUM_8);
        }
        if (member->flags.get(hkClassMember::DEPRECATED_ENUM_16)) {
            member->subtype = hkClassMember::TYPE_UINT16;
            member->flags.clear(hkClassMember::DEPRECATED_ENUM_16);
        }
        if (member->flags.get(hkClassMember::DEPRECATED_ENUM_32)) {
            member->subtype = hkClassMember::TYPE_UINT32;
            member->flags.clear(hkClassMember::DEPRECATED_ENUM_32);
        }
        break;
    default:
        break;
    }
}
