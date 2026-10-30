/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hkcdDynamicAabbTree's type info (0x57bc8e0):
 * construct the object in place from a loaded image through its out-of-line
 * finish constructor. */
void FUN_000224f0(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkcdDynamicAabbTree(flag);
}

/* hkcdDynamicAabbTree's cleanup callback: the virtual destructor (the shared body 0x2d0). */
void FUN_000002d0(void *object);
extern const hkClassMember D_1690d90[]; /* derived name: hkcdDynamicAabbTree's records */

/* The address of hkcdDynamicAabbTree's vtable, read from an object finished in a 16-byte
 * aligned buffer (the finish constructor is out of line, 0x9fc10, so the object is built on
 * the stack, as hkcdStaticAabbTree's in func_0001ff50.cpp). */
static const void *vtableOfhkcdDynamicAabbTree() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hkcdDynamicAabbTree)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkcdDynamicAabbTree(flag);
    return object.vtable;
}

/* This file's static initializer (0x22510): hkcdDynamicAabbTree's reflection over
 * hkReferencedObject's (version 1), its two members, then its type info. */
const hkClass D_57bc890("hkcdDynamicAabbTree", &D_57b8640, sizeof(hkcdDynamicAabbTree), 0, 0, 0, 0,
                        D_1690d90, 2, 0, 0, 0, 1);
extern const hkTypeInfo D_57bc8e0;
const hkTypeInfo D_57bc8e0("hkcdDynamicAabbTree", "!hkcdDynamicAabbTree", FUN_000224f0,
                           FUN_000002d0, vtableOfhkcdDynamicAabbTree(),
                           sizeof(hkcdDynamicAabbTree));
