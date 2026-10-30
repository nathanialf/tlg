/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hknpCircularSurfaceVelocity's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
void FUN_0003af50(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpCircularSurfaceVelocity(flag);
}

/* hknpCircularSurfaceVelocity's cleanup callback: the virtual destructor (the shared body 0x2d0). */
void FUN_000002d0(void *object);
extern const hkClassMember D_1695810[]; /* derived name: hknpCircularSurfaceVelocity's records */
extern const hkClass D_57c19d8;         /* hknpSurfaceVelocity's hkClass */

/* The address of hknpCircularSurfaceVelocity's vtable, read from an object finished in a buffer
 * (folded to the address point). */
static const void *vtableOfhknpCircularSurfaceVelocity() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hknpCircularSurfaceVelocity)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hknpCircularSurfaceVelocity(flag);
    return object.vtable;
}

/* This file's static initializer (0x3af70): hknpCircularSurfaceVelocity's reflection over hknpSurfaceVelocity's, its 3 members, then its type info. */
const hkClass D_57bfc10("hknpCircularSurfaceVelocity", &D_57c19d8,
                        sizeof(hknpCircularSurfaceVelocity), 0, 0, 0, 0, D_1695810, 3, 0, 0, 0, 0);
extern const hkTypeInfo D_57bfc60;
const hkTypeInfo D_57bfc60("hknpCircularSurfaceVelocity", "!hknpCircularSurfaceVelocity",
                           FUN_0003af50, FUN_000002d0, vtableOfhknpCircularSurfaceVelocity(),
                           sizeof(hknpCircularSurfaceVelocity));
