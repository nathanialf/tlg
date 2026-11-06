/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: the finish callback of hknpConstraintCollisionFilter's type info (0x57c0368):
 * construct the object in place from a loaded image through its out-of-line
 * finish constructor. */
static void finishLoadedObjecthknpConstraintCollisionFilter(void *object,
                                                            int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpConstraintCollisionFilter(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthknpConstraintCollisionFilter(void *object) /* derived name */
{
    static_cast<hknpConstraintCollisionFilter *>(object)->~hknpConstraintCollisionFilter();
}

extern const hkClass D_57c1110;         /* hknpPairCollisionFilter's hkClass */
extern const hkClassMember D_16964d0[]; /* derived name: hknpConstraintCollisionFilter's records */

/* The class's vtable, read from an object its out-of-line finish
 * constructor builds on the stack. derived name. */
static const void *vtableOfhknpConstraintCollisionFilter() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hknpConstraintCollisionFilter)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpConstraintCollisionFilter(flag);
    return object.vtable;
}

/* This file's static initializer (0x3d420): hknpConstraintCollisionFilter's reflection,
 * hknpPairCollisionFilter's as the parent, its one member, then its type info (its
 * finish callback, the destructor, the vtable). */
const hkClass D_57c0318("hknpConstraintCollisionFilter", &D_57c1110,
                        sizeof(hknpConstraintCollisionFilter), 0, 0, 0, 0, D_16964d0, 1, 0, 0, 0,
                        0);
extern const hkTypeInfo D_57c0368;
const hkTypeInfo D_57c0368("hknpConstraintCollisionFilter", "!hknpConstraintCollisionFilter",
                           finishLoadedObjecthknpConstraintCollisionFilter,
                           cleanupLoadedObjecthknpConstraintCollisionFilter,
                           vtableOfhknpConstraintCollisionFilter(),
                           sizeof(hknpConstraintCollisionFilter));
