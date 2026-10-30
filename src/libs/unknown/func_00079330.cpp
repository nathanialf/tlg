/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkpVelocityConstraintMotor's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
void FUN_00079330(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpVelocityConstraintMotor(flag);
}

/* hkpVelocityConstraintMotor's cleanup callback: the virtual destructor (the shared body 0x2d0). */
void FUN_000002d0(void *object);
extern const hkClassMember D_169bbc0[]; /* derived name: hkpVelocityConstraintMotor's records */
extern const hkClass D_57c59a8;         /* hkpLimitedForceConstraintMotor's hkClass */

/* The address of hkpVelocityConstraintMotor's vtable, read from an object finished in a buffer
 * (folded to the address point). */
static const void *vtableOfhkpVelocityConstraintMotor() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hkpVelocityConstraintMotor)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hkpVelocityConstraintMotor(flag);
    return object.vtable;
}

/* This file's static initializer (0x79350): hkpVelocityConstraintMotor's reflection over hkpLimitedForceConstraintMotor's, its 3 members, then its type info. */
const hkClass D_57c32e8("hkpVelocityConstraintMotor", &D_57c59a8,
                        sizeof(hkpVelocityConstraintMotor), 0, 0, 0, 0, D_169bbc0, 3, 0, 0, 0, 0);
extern const hkTypeInfo D_57c3338;
const hkTypeInfo D_57c3338("hkpVelocityConstraintMotor", "!hkpVelocityConstraintMotor",
                           FUN_00079330, FUN_000002d0, vtableOfhkpVelocityConstraintMotor(),
                           sizeof(hkpVelocityConstraintMotor));
