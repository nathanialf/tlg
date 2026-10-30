/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hknpSphereShape's type info (0x57c2798):
 * construct the object in place from a loaded image through its out-of-line
 * finish constructor. */
void FUN_0006b6b0(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpSphereShape(flag);
}

/* hknpSphereShape's cleanup callback: the virtual destructor (the shared body 0x2d0). */
void FUN_000002d0(void *object);

/* The address of hknpSphereShape's vtable, read from an object finished in a 16-byte aligned
 * buffer (the finish constructor is out of line, 0x3c540, so the object is built on the stack,
 * as hkcdStaticAabbTree's in func_0001ff50.cpp). */
static const void *vtableOfhknpSphereShape() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hknpSphereShape)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpSphereShape(flag);
    return object.vtable;
}

/* This file's static initializer (0x6b6d0): hknpSphereShape's reflection over
 * hknpConvexShape's (version 0), no members of its own, then its type info. */
const hkClass D_57c2748("hknpSphereShape", &D_57c1908, sizeof(hknpSphereShape), 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0);
extern const hkTypeInfo D_57c2798;
const hkTypeInfo D_57c2798("hknpSphereShape", "!hknpSphereShape", FUN_0006b6b0, FUN_000002d0,
                           vtableOfhknpSphereShape(), sizeof(hknpSphereShape));
