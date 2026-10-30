/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING (NOTES Round 64B): both switches and every case are the base's but the unsigned
// 32-bit one: the base has one block for it that both tables share (0x912af, `mov eax,
// [rdx]; jmp` to the shared return), where this compile gives each switch its own block with
// its own return.
s64 FUN_00091270(hkClassMember::Type type, hkClassMember::Type subtype, const void *address)
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
    case hkClassMember::TYPE_ENUM:
    case hkClassMember::TYPE_FLAGS:
        /* The storage the subtype names. */
        switch (subtype) {
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
    default:
        return 0;
    }
}
