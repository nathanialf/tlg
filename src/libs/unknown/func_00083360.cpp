/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkpSpringDamperConstraintMotor's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
void FUN_00083360(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpSpringDamperConstraintMotor(flag);
}

/* hkpSpringDamperConstraintMotor's cleanup callback: the virtual destructor (the shared body 0x2d0). */
void FUN_000002d0(void *object);
extern const hkClassMember D_16a00c0[]; /* derived name: hkpSpringDamperConstraintMotor's records */
extern const hkClass D_57c59a8;         /* hkpLimitedForceConstraintMotor's hkClass */

/* The address of hkpSpringDamperConstraintMotor's vtable, read from an object finished in a buffer
 * (folded to the address point). */
static const void *vtableOfhkpSpringDamperConstraintMotor() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hkpSpringDamperConstraintMotor)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hkpSpringDamperConstraintMotor(flag);
    return object.vtable;
}

/* This file's static initializer (0x83380): hkpSpringDamperConstraintMotor's reflection over hkpLimitedForceConstraintMotor's, its 2 members, then its type info. */
const hkClass D_57c5bf8("hkpSpringDamperConstraintMotor", &D_57c59a8,
                        sizeof(hkpSpringDamperConstraintMotor), 0, 0, 0, 0, D_16a00c0, 2, 0, 0, 0,
                        0);
extern const hkTypeInfo D_57c5c48;
const hkTypeInfo D_57c5c48("hkpSpringDamperConstraintMotor", "!hkpSpringDamperConstraintMotor",
                           FUN_00083360, FUN_000002d0, vtableOfhkpSpringDamperConstraintMotor(),
                           sizeof(hkpSpringDamperConstraintMotor));
