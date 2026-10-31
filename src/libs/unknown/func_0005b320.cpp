/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The braking properties' cleanup callback: the empty body the linker
 * folded (func_0003e5b0.cpp). hknpVehicleDefaultBrake's finish callback
 * (func_0005b300.cpp) and cleanup callback (the virtual destructor, the
 * shared body 0x2d0). */
void FUN_0003b640(void *object);
void FUN_0005b300(void *object, int finishing);
void FUN_000002d0(void *object);

extern const hkClassMember D_16993e0[]; /* derived name: the braking properties' records */
extern const hkClassMember D_1699460[]; /* derived name: the default brake's records */

/* The address of hknpVehicleDefaultBrake's vtable, read from an object
 * finished in a buffer (folded to the address point). */
static const void *vtableOfhknpVehicleDefaultBrake() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hknpVehicleDefaultBrake)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hknpVehicleDefaultBrake(flag);
    return object.vtable;
}

/* This file's static initializer (0x5b320): the braking properties'
 * reflection (no parent, three members) and type info, then
 * hknpVehicleDefaultBrake's over hknpVehicleBrake's (two members) and type
 * info with its vtable. The type infos' names are the base's strings. */
const hkClass D_57c1560("hknpVehicleDefaultBrakeWheelBrakingProperties", 0,
                        sizeof(hknpVehicleDefaultBrake::WheelBrakingProperties), 0, 0, 0, 0,
                        D_16993e0, 3, 0, 0, 0, 0);
extern const hkTypeInfo D_57c15b0;
const hkTypeInfo D_57c15b0("hknpVehicleDefaultBrakeWheelBrakingProperties",
                           "!hknpVehicleDefaultBrake::WheelBrakingProperties", 0, FUN_0003b640, 0,
                           sizeof(hknpVehicleDefaultBrake::WheelBrakingProperties));
const hkClass D_57c15e0("hknpVehicleDefaultBrake", &D_57c26f8, sizeof(hknpVehicleDefaultBrake), 0,
                        0, 0, 0, D_1699460, 2, 0, 0, 0, 0);
extern const hkTypeInfo D_57c1630;
const hkTypeInfo D_57c1630("hknpVehicleDefaultBrake", "!hknpVehicleDefaultBrake", FUN_0005b300,
                           FUN_000002d0, vtableOfhknpVehicleDefaultBrake(),
                           sizeof(hknpVehicleDefaultBrake));
