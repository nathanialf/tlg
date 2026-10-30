/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hkSkinnedRefMeshShape's type info (0x57bcd70):
 * construct the object in place from a loaded image through its out-of-line
 * finish constructor. */
void FUN_00023380(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkSkinnedRefMeshShape(flag);
}

/* hkSkinnedRefMeshShape's cleanup callback: the virtual destructor (the shared body 0x2d0). */
void FUN_000002d0(void *object);
extern const hkClassMember D_16916c0[]; /* derived name: hkSkinnedRefMeshShape's records */

/* The address of hkSkinnedRefMeshShape's vtable, read from an object finished in a 16-byte
 * aligned buffer (the finish constructor is out of line, 0xaa660, so the object is built on
 * the stack, as hkcdStaticAabbTree's in func_0001ff50.cpp). */
static const void *vtableOfhkSkinnedRefMeshShape() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hkSkinnedRefMeshShape)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkSkinnedRefMeshShape(flag);
    return object.vtable;
}

/* This file's static initializer (0x233a0): hkSkinnedRefMeshShape's reflection over
 * hkMeshShape's (version 1), its four members, then its type info. */
const hkClass D_57bcd20("hkSkinnedRefMeshShape", &D_57bd7d0, sizeof(hkSkinnedRefMeshShape), 0, 0, 0,
                        0, D_16916c0, 4, 0, 0, 0, 1);
extern const hkTypeInfo D_57bcd70;
const hkTypeInfo D_57bcd70("hkSkinnedRefMeshShape", "!hkSkinnedRefMeshShape", FUN_00023380,
                           FUN_000002d0, vtableOfhkSkinnedRefMeshShape(),
                           sizeof(hkSkinnedRefMeshShape));
