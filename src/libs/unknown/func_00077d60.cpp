/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hknpVehicleDefaultSteering's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
void FUN_00077d60(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpVehicleDefaultSteering(flag);
}

/* hknpVehicleDefaultSteering's cleanup callback: the virtual destructor (the shared body 0x2d0). */
void FUN_000002d0(void *object);
extern const hkClassMember D_169b4a0[]; /* derived name: hknpVehicleDefaultSteering's records */

/* The address of hknpVehicleDefaultSteering's vtable, read from an object finished in a buffer
 * (folded to the address point). */
static const void *vtableOfhknpVehicleDefaultSteering() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hknpVehicleDefaultSteering)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hknpVehicleDefaultSteering(flag);
    return object.vtable;
}

/* This file's static initializer (0x77d80): hknpVehicleDefaultSteering's reflection over hknpVehicleSteering's, its 3 members, then its type info. */
const hkClass D_57c2df8("hknpVehicleDefaultSteering", &D_57c1988,
                        sizeof(hknpVehicleDefaultSteering), 0, 0, 0, 0, D_169b4a0, 3, 0, 0, 0, 0);
extern const hkTypeInfo D_57c2e48;
const hkTypeInfo D_57c2e48("hknpVehicleDefaultSteering", "!hknpVehicleDefaultSteering",
                           FUN_00077d60, FUN_000002d0, vtableOfhknpVehicleDefaultSteering(),
                           sizeof(hknpVehicleDefaultSteering));
