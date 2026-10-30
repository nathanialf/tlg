/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hkcdStaticAabbTree's type info (0x57bba60):
 * construct the object in place from a loaded image through its out-of-line
 * finish constructor. */
void FUN_0001ff50(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkcdStaticAabbTree(flag);
}

/* hkcdStaticAabbTree's cleanup callback: the virtual destructor (the shared body 0x2d0). */
void FUN_000002d0(void *object);
extern const hkClassMember D_16903e0[]; /* derived name: hkcdStaticAabbTree's records */

/* The address of hkcdStaticAabbTree's vtable, read from an object finished in a 16-byte
 * aligned buffer (the finish constructor is out of line, 0x22700, so the object is built on
 * the stack, at -0x40 below the guard's -0x18: a 0x20-byte slot). */
static const void *vtableOfhkcdStaticAabbTree() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hkcdStaticAabbTree)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkcdStaticAabbTree(flag);
    return object.vtable;
}

/* This file's static initializer (0x1ff70): hkcdStaticAabbTree's reflection over
 * hkReferencedObject's (version 1), its two members, then its type info. */
const hkClass D_57bba10("hkcdStaticAabbTree", &D_57b8640, sizeof(hkcdStaticAabbTree), 0, 0, 0, 0,
                        D_16903e0, 2, 0, 0, 0, 1);
extern const hkTypeInfo D_57bba60;
const hkTypeInfo D_57bba60("hkcdStaticAabbTree", "!hkcdStaticAabbTree", FUN_0001ff50, FUN_000002d0,
                           vtableOfhkcdStaticAabbTree(), sizeof(hkcdStaticAabbTree));
