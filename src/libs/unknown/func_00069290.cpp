/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The wheel parameters' cleanup callback: the empty body the linker folded
 * (func_0003e5b0.cpp). hknpVehicleData's finish callback
 * (func_00069250.cpp) and cleanup callback (the virtual destructor, the
 * shared body 0x2d0). */
void FUN_0003b640(void *object);
void FUN_000002d0(void *object);

extern const hkClassMember D_169a110[]; /* derived name: the wheel parameters' records */
extern const hkClassMember D_169a2a0[]; /* derived name: hknpVehicleData's records */

/* hknpVehicleData's members' defaults, file-local (D17); the rows are
 * written at build time from the user's executable (D18,
 * config/data_schema.base.txt). */
static const hknpVehicleDataDefaults D_14bebb8[1] = {
#include "gen/D_14bebb8.inc"
};

/* The address of hknpVehicleData's vtable, read from an object finished in
 * a buffer (folded to the address point). */
static const void *vtableOfhknpVehicleData() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hknpVehicleData)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hknpVehicleData(flag);
    return object.vtable;
}

/* This file's static initializer (0x69290): the wheel parameters'
 * reflection (no parent, ten members) and type info, then hknpVehicleData's
 * over hkReferencedObject's (nineteen members and their defaults) and type
 * info with its vtable. The type infos' names are the base's strings. */
const hkClass D_57c2228("hknpVehicleDataWheelComponentParams", 0,
                        sizeof(hknpVehicleDataWheelComponentParams), 0, 0, 0, 0, D_169a110, 10, 0,
                        0, 0, 0);
extern const hkTypeInfo D_57c2278;
const hkTypeInfo D_57c2278("hknpVehicleDataWheelComponentParams",
                           "!hknpVehicleData::WheelComponentParams", 0, FUN_0003b640, 0,
                           sizeof(hknpVehicleDataWheelComponentParams));
const hkClass D_57c22a8("hknpVehicleData", &D_57b8640, sizeof(hknpVehicleData), 0, 0, 0, 0,
                        D_169a2a0, 19, D_14bebb8, 0, 0, 0);
extern const hkTypeInfo D_57c22f8;
const hkTypeInfo D_57c22f8("hknpVehicleData", "!hknpVehicleData", FUN_00069250, FUN_000002d0,
                           vtableOfhknpVehicleData(), sizeof(hknpVehicleData));
