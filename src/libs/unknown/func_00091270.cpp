/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* An integer member's value at an address, widened to 64 bits by its storage
 * type, zero for any other type. derived name. */
static inline s64 readInteger(hkClassMember::Type type, const void *address) /* derived name */
{
    switch (type) {
    case hkClassMember::TYPE_BOOL:
    case hkClassMember::TYPE_CHAR:
    case hkClassMember::TYPE_INT8:
        return *static_cast<const s8 *>(address);
    case hkClassMember::TYPE_UINT8:
        return *static_cast<const u8 *>(address);
    case hkClassMember::TYPE_INT16:
        return *static_cast<const s16 *>(address);
    case hkClassMember::TYPE_UINT16:
        return *static_cast<const u16 *>(address);
    case hkClassMember::TYPE_INT32:
        return *static_cast<const s32 *>(address);
    case hkClassMember::TYPE_UINT32:
        return *static_cast<const u32 *>(address);
    case hkClassMember::TYPE_INT64:
    case hkClassMember::TYPE_UINT64:
    case hkClassMember::TYPE_ULONG:
        return *static_cast<const s64 *>(address);
    default:
        return 0;
    }
}

/* An enumeration's or a flags member's value is read through the storage
 * type its subtype names (both switches inlined, two tables). */
s64 FUN_00091270(hkClassMember::Type type, hkClassMember::Type subtype, const void *address)
{
    if (type == hkClassMember::TYPE_ENUM || type == hkClassMember::TYPE_FLAGS) {
        return readInteger(subtype, address);
    }
    return readInteger(type, address);
}
