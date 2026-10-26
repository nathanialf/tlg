/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 6 of the object copier's vtable (address point
 * 0x16a75e0): two members are compatible when their types are equal and
 * their subtypes too, unless they are enums (an enum's subtype is its
 * storage size, which the copy converts). */
int hkObjectCopier::FUN_001a0b20(const hkClassMember &src, const hkClassMember &dst)
{
    return src.type == dst.type &&
           (src.subtype == dst.subtype || src.type == hkClassMember::TYPE_ENUM);
}
