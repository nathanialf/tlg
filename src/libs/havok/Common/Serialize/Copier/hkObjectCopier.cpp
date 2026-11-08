/* src/libs/havok/Common/Serialize/Copier/hkObjectCopier.cpp: the file its
 * report names (config/homes.base.txt, FUN_001a0890). */
#include "tlg_lib_unknown.h"

/* A member of the target layout written as zeros (0x1a0890; the copy at
 * 0x1a0e97 asks it for each member the source class lacks): its size by
 * its type, a pointer the target's size, an array its pointer and count
 * (an hkArray's count and capacity written at once, the capacity not to be
 * freed), a struct its class's size, each times its C array size; the
 * buffer grown and cleared to that size first. derived name. */
void hkObjectCopier::FUN_001a0890(hkOArchive &out, const hkClassMember &member,
                                  hkArray<char> &zeros) const
{
    int size;
    switch (member.type) {
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
    case hkClassMember::TYPE_POINTER:
    case hkClassMember::TYPE_FUNCTIONPOINTER:
    case hkClassMember::TYPE_ULONG:
    case hkClassMember::TYPE_STRINGPTR:
        size = layoutOut.rules.bytesInPointer * (FUN_00007e00(&member) ? FUN_00007e00(&member) : 1);
        break;
    case hkClassMember::TYPE_ARRAY:
    case hkClassMember::TYPE_INPLACEARRAY:
    case hkClassMember::TYPE_SIMPLEARRAY:
    case hkClassMember::TYPE_HOMOGENEOUSARRAY: {
        const int pointerSize = layoutOut.rules.bytesInPointer;
        if (member.type == hkClassMember::TYPE_HOMOGENEOUSARRAY) {
            size = 2 * pointerSize + int(sizeof(int));
        } else {
            size = pointerSize + int(sizeof(int));
            if (member.type == hkClassMember::TYPE_ARRAY) {
                /* An empty array's pointer and count, then its capacity
                 * with the flag that it owns no storage. */
                char zeroArray[12] = {0};
                out.FUN_000089f0(zeroArray, size);
                out.FUN_0000a7a0(int(0x80000000));
                return;
            }
        }
        break;
    }
    case hkClassMember::TYPE_STRUCT:
        size = FUN_00004250(&member)->FUN_00004580() *
               (FUN_00007e00(&member) ? FUN_00007e00(&member) : 1);
        break;
    case hkClassMember::TYPE_VARIANT:
        size = 2 * layoutOut.rules.bytesInPointer *
               (FUN_00007e00(&member) ? FUN_00007e00(&member) : 1);
        break;
    default:
        HK_ERROR(0x5ef4e5a4, HK_OBJECT_COPIER_CPP, 178, "Unknown class member type found!");
        size = 0;
        break;
    }
    zeros.setSize(hkContainerHeapAllocator::get(), size, 0);
    out.FUN_000089f0(zeros.data, size);
}
