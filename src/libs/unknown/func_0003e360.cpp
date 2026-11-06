/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hknpDisableCollisionFilter's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
static void finishLoadedObjecthknpDisableCollisionFilter(void *object,
                                                         int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpDisableCollisionFilter(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthknpDisableCollisionFilter(void *object) /* derived name */
{
    static_cast<hknpDisableCollisionFilter *>(object)->~hknpDisableCollisionFilter();
}

/* The class's vtable, read from an object its finish constructor builds
 * (cookbook 166). derived name. */
static const void *vtableOfhknpDisableCollisionFilter() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hknpDisableCollisionFilter)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hknpDisableCollisionFilter(flag);
    return object.vtable;
}

/* This file's static initializer (0x3e360): hknpDisableCollisionFilter's
 * reflection, hknpCollisionFilter's as the parent, no members, then its type
 * info (its finish callback, the destructor, the vtable). */
const hkClass D_57c0668("hknpDisableCollisionFilter", &D_57c0cb0,
                        sizeof(hknpDisableCollisionFilter), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
extern const hkTypeInfo D_57c06b8;
const hkTypeInfo D_57c06b8("hknpDisableCollisionFilter", "!hknpDisableCollisionFilter",
                           finishLoadedObjecthknpDisableCollisionFilter,
                           cleanupLoadedObjecthknpDisableCollisionFilter,
                           vtableOfhknpDisableCollisionFilter(),
                           sizeof(hknpDisableCollisionFilter));
