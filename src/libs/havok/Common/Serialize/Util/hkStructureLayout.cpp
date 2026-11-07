/* src/libs/havok/Common/Serialize/Util/hkStructureLayout.cpp:
 * the file its report names (config/homes.base.txt, FUN_001814f0). */
#include "tlg_lib_unknown.h"

/* The file this one's report names (the string at 0x14cb93d). */
#define HK_STRUCTURE_LAYOUT_CPP                                                                    \
    "Y:\\NightlyJobs\\20141121-01\\Source\\Common\\Serialize\\Util\\hkStructureLayout.cpp"

/* The number of elements a member holds: its C array size, one when it is
 * not an array (read through the out-of-line accessor each time). derived
 * name. */
static inline int numElementsOf(const hkClassMember &member) /* derived name */
{
    return FUN_00007e00(&member) ? FUN_00007e00(&member) : 1;
}

/* derived name: a member's size under a layout's rules, as its type gives
 * it (the type passed apart so that a zero member is sized by its
 * subtype): a plain type's, an enum's or flags' or a half's own size;
 * pointer-sized types by the rules' pointer size; the arrays' headers; a
 * struct's object size; nothing for an inplace array; an error for a type
 * that has no size (0x1814f0; the layout's 0x180f50 calls it). */
int FUN_001814f0(const hkClassMember &member, const LayoutRules00180ef0 &rules,
                 hkClassMember::Type type)
{
    int size = 0;
    switch (type) {
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
        size = member.FUN_00007d60();
        break;
    case hkClassMember::TYPE_ZERO:
        size = FUN_001814f0(member, rules, hkClassMember::Type(member.subtype));
        break;
    case hkClassMember::TYPE_POINTER:
    case hkClassMember::TYPE_FUNCTIONPOINTER:
    case hkClassMember::TYPE_CSTRING:
    case hkClassMember::TYPE_ULONG:
    case hkClassMember::TYPE_STRINGPTR:
        size = rules.bytesInPointer * numElementsOf(member);
        break;
    case hkClassMember::TYPE_INPLACEARRAY:
        break;
    case hkClassMember::TYPE_STRUCT:
        size = FUN_00004250(&member)->FUN_00004580() * numElementsOf(member);
        break;
    case hkClassMember::TYPE_ARRAY:
        /* An array is a simple array with a capacity. */
        size = int(sizeof(int));
        /* fall through */
    case hkClassMember::TYPE_SIMPLEARRAY:
        size += rules.bytesInPointer + int(sizeof(int));
        break;
    case hkClassMember::TYPE_HOMOGENEOUSARRAY:
        size = 2 * rules.bytesInPointer + int(sizeof(int));
        break;
    case hkClassMember::TYPE_VARIANT:
        size = 2 * rules.bytesInPointer;
        break;
    case hkClassMember::TYPE_RELARRAY:
        size = int(sizeof(int));
        break;
    default:
        HK_ERROR(0x50a18b58, HK_STRUCTURE_LAYOUT_CPP, 201,
                 "Unknown class member type in structureLayout::getMemberSize().");
        break;
    }
    return size;
}
