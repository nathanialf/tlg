/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hknpDisableCollisionFilter's loaded-object cleanup: the virtual destructor
 * (the linker folded it with the other classes' identical body, 0x2d0,
 * FUN_000002d0). */
void FUN_000002d0(void *object)
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
                           FUN_0003e340, FUN_000002d0, vtableOfhknpDisableCollisionFilter(),
                           sizeof(hknpDisableCollisionFilter));
