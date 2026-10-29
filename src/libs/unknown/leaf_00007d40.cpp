/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The member type table (derived name), one row per hkClassMember::Type
 * including TYPE_MAX. The base reaches it with a direct `lea`, so it is local
 * to this TU (docs/DECISIONS.md D17); its rows are written at build time from
 * the user's executable (D18, config/data_schema.base.txt). */
static const hkClassMember::TypeProperties D_16dc150[36] = {
#include "gen/D_16dc150.inc"
};

/* derived name: the properties of a member type, its row of the table at
 * 0x16dc150 (0x4768 reads the size of an enum's or a flags member's
 * storage type through it). The type is the enum, indexed unsigned. */
const hkClassMember::TypeProperties &hkClassMember::FUN_00007d40(Type type) /* derived name */
{
    return D_16dc150[type];
}

/* derived name: an array member's element size, read from its subtype. */
int hkClassMember::FUN_00007f20() const
{
    switch (subtype) {
    default:
        return D_16dc150[subtype].size;
    case TYPE_STRUCT:
        return structClass->FUN_00004580();
    case TYPE_ENUM:
    case TYPE_FLAGS:
        return -1;
    }
}

/* The member's count of elements: its C array size, or one for a member
 * that is not a C array. derived name. */
static inline int numElementsOf(const hkClassMember &member) /* derived name */
{
    return member.cArraySize ? member.cArraySize : 1;
}

/* derived name: the member's size in bytes: its type's size, an enum's or
 * flags' storage size, or a struct's object size, times its C array size
 * (or one); -1 for a type with no size of its own. */
int hkClassMember::FUN_00007d60() const
{
    switch (type) {
    case TYPE_BOOL:
    case TYPE_CHAR:
    case TYPE_INT8:
    case TYPE_UINT8:
    case TYPE_INT16:
    case TYPE_UINT16:
    case TYPE_INT32:
    case TYPE_UINT32:
    case TYPE_INT64:
    case TYPE_UINT64:
    case TYPE_REAL:
    case TYPE_VECTOR4:
    case TYPE_QUATERNION:
    case TYPE_MATRIX3:
    case TYPE_ROTATION:
    case TYPE_QSTRANSFORM:
    case TYPE_MATRIX4:
    case TYPE_TRANSFORM:
    case TYPE_POINTER:
    case TYPE_FUNCTIONPOINTER:
    case TYPE_ARRAY:
    case TYPE_SIMPLEARRAY:
    case TYPE_HOMOGENEOUSARRAY:
    case TYPE_VARIANT:
    case TYPE_CSTRING:
    case TYPE_ULONG:
    case TYPE_HALF:
    case TYPE_STRINGPTR:
    case TYPE_RELARRAY:
        return numElementsOf(*this) * D_16dc150[type].size;
    case TYPE_ENUM:
    case TYPE_FLAGS:
        return numElementsOf(*this) * D_16dc150[subtype].size;
    case TYPE_STRUCT:
        return numElementsOf(*this) * structClass->FUN_00004580();
    default:
        return -1;
    }
}
