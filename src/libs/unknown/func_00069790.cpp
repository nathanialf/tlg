/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

extern const hkClass D_57c4308;         /* hkpWrappedConstraintData's hkClass */
extern const hkClassMember D_169a740[]; /* derived name: hknpBreakableConstraintData's records */

void FUN_00069770(void *object, int finishing); /* derived name */
void FUN_000002d0(void *object);                /* derived name */

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
                           FUN_00069770, FUN_000002d0, vtableOfhknpBreakableConstraintData(),
                           sizeof(hknpBreakableConstraintData));
