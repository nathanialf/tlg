/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

int FUN_00181360(const hkClassMember &member, hkClassMember::Type type, int pointerAlignment)
{
    int alignment = -1;
    switch (type) {
    case hkClassMember::TYPE_VOID:
    case hkClassMember::TYPE_BOOL:
    case hkClassMember::TYPE_CHAR:
    case hkClassMember::TYPE_INT8:
    case hkClassMember::TYPE_UINT8:
    case hkClassMember::TYPE_INT16:
    case hkClassMember::TYPE_UINT16:
    case hkClassMember::TYPE_INT32:
    case hkClassMember::TYPE_UINT32:
    case hkClassMember::TYPE_INT64:
    case hkClassMember::TYPE_UINT64:
    case hkClassMember::TYPE_REAL:
    case hkClassMember::TYPE_VECTOR4:
    case hkClassMember::TYPE_QUATERNION:
    case hkClassMember::TYPE_MATRIX3:
    case hkClassMember::TYPE_ROTATION:
    case hkClassMember::TYPE_QSTRANSFORM:
    case hkClassMember::TYPE_MATRIX4:
    case hkClassMember::TYPE_TRANSFORM:
    case hkClassMember::TYPE_ENUM:
    case hkClassMember::TYPE_FLAGS:
    case hkClassMember::TYPE_HALF:
    case hkClassMember::TYPE_RELARRAY:
        alignment = member.FUN_00007e30();
        break;
    case hkClassMember::TYPE_ZERO:
        alignment = FUN_00181360(member, hkClassMember::Type(member.subtype), pointerAlignment);
        break;
    case hkClassMember::TYPE_POINTER:
    case hkClassMember::TYPE_FUNCTIONPOINTER:
    case hkClassMember::TYPE_ARRAY:
    case hkClassMember::TYPE_SIMPLEARRAY:
    case hkClassMember::TYPE_HOMOGENEOUSARRAY:
    case hkClassMember::TYPE_VARIANT:
    case hkClassMember::TYPE_CSTRING:
    case hkClassMember::TYPE_ULONG:
    case hkClassMember::TYPE_STRINGPTR:
        alignment = pointerAlignment;
        break;
    case hkClassMember::TYPE_STRUCT: {
        const hkClass *klass = FUN_00004250(&member);
        alignment = 1;
        for (int i = 0; i < klass->FUN_00004350(); i++) {
            const hkClassMember &m = klass->FUN_00004370(i);
            const int memberAlignment =
                FUN_00181360(m, hkClassMember::Type(m.type), pointerAlignment);
            alignment = memberAlignment >= alignment ? memberAlignment : alignment;
        }
        break;
    }
    default:
        break;
    }
    const u16 alignFlags = member.flags.get(hkClassMember::ALIGN_8 | hkClassMember::ALIGN_16 |
                                            hkClassMember::ALIGN_32);
    if (alignFlags) {
        const int forced = alignFlags == hkClassMember::ALIGN_32
                               ? 32
                               : (alignFlags == hkClassMember::ALIGN_16 ? 16 : 8);
        alignment = hkMath::max2(forced, alignment);
    }
    return alignment;
}
