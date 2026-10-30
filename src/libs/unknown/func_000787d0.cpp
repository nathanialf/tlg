/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkpPositionConstraintMotor's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
void FUN_000787d0(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpPositionConstraintMotor(flag);
}

/* hkpPositionConstraintMotor's cleanup callback: the virtual destructor (the shared body 0x2d0). */
void FUN_000002d0(void *object);
extern const hkClassMember D_169b830[]; /* derived name: hkpPositionConstraintMotor's records */
extern const hkClass D_57c59a8;         /* hkpLimitedForceConstraintMotor's hkClass */

/* The address of hkpPositionConstraintMotor's vtable, read from an object finished in a buffer
 * (folded to the address point). */
static const void *vtableOfhkpPositionConstraintMotor() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hkpPositionConstraintMotor)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hkpPositionConstraintMotor(flag);
    return object.vtable;
}

/* This file's static initializer (0x787f0): hkpPositionConstraintMotor's reflection over hkpLimitedForceConstraintMotor's, its 4 members, then its type info. */
const hkClass D_57c30e8("hkpPositionConstraintMotor", &D_57c59a8,
                        sizeof(hkpPositionConstraintMotor), 0, 0, 0, 0, D_169b830, 4, 0, 0, 0, 0);
extern const hkTypeInfo D_57c3138;
const hkTypeInfo D_57c3138("hkpPositionConstraintMotor", "!hkpPositionConstraintMotor",
                           FUN_000787d0, FUN_000002d0, vtableOfhkpPositionConstraintMotor(),
                           sizeof(hkpPositionConstraintMotor));
