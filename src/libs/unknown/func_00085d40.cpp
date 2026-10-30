/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkxBlobMeshShape's finish constructor: the mesh shape and the blob need
 * only their vtables; the name finishes. */
hkxBlobMeshShape::hkxBlobMeshShape(hkFinishLoadedObjectFlag flag)
    : hkMeshShape(flag), blob(flag), name(flag)
{
}

/* The finish callback of hkxBlobMeshShape's type info: the object finished
 * in place. The linker folded it onto the finish constructor, whose row
 * it shares (0x85d40, D15's addendum: spelled by the address). */
void FUN_00085d40(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxBlobMeshShape(flag);
}

/* hkxBlobMeshShape's cleanup callback: the virtual destructor (the shared
 * body 0x2d0). */
void FUN_000002d0(void *object);
extern const hkClassMember D_16a0830[]; /* derived name: hkxBlobMeshShape's records */

/* The address of hkxBlobMeshShape's vtable, read from an object finished
 * in a 16-byte aligned buffer: the finish constructor is this file's, but
 * the name's finish constructor in it is out of line (0xe5c0), so the
 * object is built on the stack, as in func_000224f0.cpp. */
static const void *vtableOfhkxBlobMeshShape() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hkxBlobMeshShape)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkxBlobMeshShape(flag);
    return object.vtable;
}

/* This file's static initializer (0x85d80): hkxBlobMeshShape's reflection
 * over hkMeshShape's, its two members, then its type info. */
const hkClass D_57c5e78("hkxBlobMeshShape", &D_57bd7d0, sizeof(hkxBlobMeshShape), 0, 0, 0, 0,
                        D_16a0830, 2, 0, 0, 0, 0);
extern const hkTypeInfo D_57c5ec8;
const hkTypeInfo D_57c5ec8("hkxBlobMeshShape", "!hkxBlobMeshShape", FUN_00085d40, FUN_000002d0,
                           vtableOfhkxBlobMeshShape(), sizeof(hkxBlobMeshShape));
