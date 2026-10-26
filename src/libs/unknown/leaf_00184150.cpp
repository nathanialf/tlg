/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The accessor of one member of an object: the member's address is the
 * object's plus the record's offset. Built on the stack by the link
 * resolver at 0x17f6f3. */
hkClassMemberAccessor::hkClassMemberAccessor(void *object, const hkClassMember *member)
    : address(static_cast<char *>(object) + member->offset), member(member)
{
}
