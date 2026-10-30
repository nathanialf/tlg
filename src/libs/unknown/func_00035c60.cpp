/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hknpVehicleDefaultVelocityDamper's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
void FUN_00035c60(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpVehicleDefaultVelocityDamper(flag);
}

/* hknpVehicleDefaultVelocityDamper's cleanup callback: the virtual destructor (the shared body 0x2d0). */
void FUN_000002d0(void *object);
extern const hkClassMember
    D_1692ef0[]; /* derived name: hknpVehicleDefaultVelocityDamper's records */

/* The address of hknpVehicleDefaultVelocityDamper's vtable, read from an object finished in a buffer
 * (folded to the address point). */
static const void *vtableOfhknpVehicleDefaultVelocityDamper() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hknpVehicleDefaultVelocityDamper)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hknpVehicleDefaultVelocityDamper(flag);
    return object.vtable;
}

/* This file's static initializer (0x35c80): hknpVehicleDefaultVelocityDamper's reflection over hknpVehicleVelocityDamper's, its 3 members, then its type info. */
const hkClass D_57be6c0("hknpVehicleDefaultVelocityDamper", &D_57c2428,
                        sizeof(hknpVehicleDefaultVelocityDamper), 0, 0, 0, 0, D_1692ef0, 3, 0, 0, 0,
                        0);
extern const hkTypeInfo D_57be710;
const hkTypeInfo D_57be710("hknpVehicleDefaultVelocityDamper", "!hknpVehicleDefaultVelocityDamper",
                           FUN_00035c60, FUN_000002d0, vtableOfhknpVehicleDefaultVelocityDamper(),
                           sizeof(hknpVehicleDefaultVelocityDamper));
