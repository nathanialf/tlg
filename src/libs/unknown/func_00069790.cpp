/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: the finish callback of hknpBreakableConstraintData's type info (0x57c23f8):
 * construct the object in place from a loaded image through its out-of-line
 * finish constructor. */
static void finishLoadedObjecthknpBreakableConstraintData(void *object,
                                                          int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpBreakableConstraintData(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthknpBreakableConstraintData(void *object) /* derived name */
{
    static_cast<hknpBreakableConstraintData *>(object)->~hknpBreakableConstraintData();
}

extern const hkClass D_57c4308;         /* hkpWrappedConstraintData's hkClass */
extern const hkClassMember D_169a740[]; /* derived name: hknpBreakableConstraintData's records */

/* The class's vtable, read from an object its out-of-line finish
 * constructor builds on the stack. derived name. */
static const void *vtableOfhknpBreakableConstraintData() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hknpBreakableConstraintData)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpBreakableConstraintData(flag);
    return object.vtable;
}

/* This file's static initializer (0x69790): hknpBreakableConstraintData's reflection,
 * hkpWrappedConstraintData's as the parent, its one member, then its type info (its
 * finish callback, the destructor, the vtable). */
const hkClass D_57c23a8("hknpBreakableConstraintData", &D_57c4308,
                        sizeof(hknpBreakableConstraintData), 0, 0, 0, 0, D_169a740, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57c23f8;
const hkTypeInfo D_57c23f8("hknpBreakableConstraintData", "!hknpBreakableConstraintData",
                           finishLoadedObjecthknpBreakableConstraintData,
                           cleanupLoadedObjecthknpBreakableConstraintData,
                           vtableOfhknpBreakableConstraintData(),
                           sizeof(hknpBreakableConstraintData));
