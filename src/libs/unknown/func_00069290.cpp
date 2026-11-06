/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the finish callback of hknpVehicleData's type info
 * (0x57c22f8): construct the data in place from a loaded image, its
 * friction description with it. */
static void finishLoadedObjecthknpVehicleData(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpVehicleData(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthknpVehicleData(void *object) /* derived name */
{
    static_cast<hknpVehicleData *>(object)->~hknpVehicleData();
}

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0x3b640. */
static void cleanupLoadedObjecthknpVehicleDataWheelComponentParams(void *object) /* derived name */
{
    static_cast<hknpVehicleDataWheelComponentParams *>(object)
        ->~hknpVehicleDataWheelComponentParams();
}

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
                           "!hknpVehicleData::WheelComponentParams", 0,
                           cleanupLoadedObjecthknpVehicleDataWheelComponentParams, 0,
                           sizeof(hknpVehicleDataWheelComponentParams));
const hkClass D_57c22a8("hknpVehicleData", &D_57b8640, sizeof(hknpVehicleData), 0, 0, 0, 0,
                        D_169a2a0, 19, D_14bebb8, 0, 0, 0);
extern const hkTypeInfo D_57c22f8;
const hkTypeInfo D_57c22f8("hknpVehicleData", "!hknpVehicleData", finishLoadedObjecthknpVehicleData,
                           cleanupLoadedObjecthknpVehicleData, vtableOfhknpVehicleData(),
                           sizeof(hknpVehicleData));
