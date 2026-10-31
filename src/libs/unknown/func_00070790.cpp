/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The wheel state's cleanup callback: the empty body the linker folded
 * (func_0003e5b0.cpp). hknpVehicleLinearCastWheelCollide's finish callback
 * (func_00070750.cpp) and cleanup callback (the virtual destructor, the
 * shared body 0x2d0). */
void FUN_0003b640(void *object);
void FUN_00070750(void *object, int finishing);
void FUN_000002d0(void *object);

extern const hkClassMember D_169afc0[]; /* derived name: the wheel state's records */
extern const hkClassMember D_169b060[]; /* derived name: the linear cast's records */

/* The address of hknpVehicleLinearCastWheelCollide's vtable, read from an
 * object finished in a buffer (folded to the address point). */
static const void *vtableOfhknpVehicleLinearCastWheelCollide() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hknpVehicleLinearCastWheelCollide)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hknpVehicleLinearCastWheelCollide(flag);
    return object.vtable;
}

/* This file's static initializer (0x70790): the wheel state's reflection
 * (no parent, four members) and type info, then
 * hknpVehicleLinearCastWheelCollide's over hknpVehicleWheelCollide's (four
 * members) and type info with its vtable. The type infos' names are the
 * base's strings. */
const hkClass D_57c2bf8("hknpVehicleLinearCastWheelCollideWheelState", 0,
                        sizeof(hknpVehicleLinearCastWheelCollide::WheelState), 0, 0, 0, 0,
                        D_169afc0, 4, 0, 0, 0, 0);
extern const hkTypeInfo D_57c2c48;
const hkTypeInfo D_57c2c48("hknpVehicleLinearCastWheelCollideWheelState",
                           "!hknpVehicleLinearCastWheelCollide::WheelState", 0, FUN_0003b640, 0,
                           sizeof(hknpVehicleLinearCastWheelCollide::WheelState));
const hkClass D_57c2c78("hknpVehicleLinearCastWheelCollide", &D_57c1510,
                        sizeof(hknpVehicleLinearCastWheelCollide), 0, 0, 0, 0, D_169b060, 4, 0, 0,
                        0, 0);
extern const hkTypeInfo D_57c2cc8;
const hkTypeInfo D_57c2cc8("hknpVehicleLinearCastWheelCollide",
                           "!hknpVehicleLinearCastWheelCollide", FUN_00070750, FUN_000002d0,
                           vtableOfhknpVehicleLinearCastWheelCollide(),
                           sizeof(hknpVehicleLinearCastWheelCollide));
