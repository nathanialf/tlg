/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hknpVehicleDefaultBrake's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
static void finishLoadedObjecthknpVehicleDefaultBrake(void *object,
                                                      int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpVehicleDefaultBrake(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthknpVehicleDefaultBrake(void *object) /* derived name */
{
    static_cast<hknpVehicleDefaultBrake *>(object)->~hknpVehicleDefaultBrake();
}

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0x3b640. */
static void
cleanupLoadedObjecthknpVehicleDefaultBrakeWheelBrakingProperties(void *object) /* derived name */
{
    static_cast<hknpVehicleDefaultBrake::WheelBrakingProperties *>(object)
        ->~WheelBrakingProperties();
}

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
                           "!hknpVehicleDefaultBrake::WheelBrakingProperties", 0,
                           cleanupLoadedObjecthknpVehicleDefaultBrakeWheelBrakingProperties, 0,
                           sizeof(hknpVehicleDefaultBrake::WheelBrakingProperties));
const hkClass D_57c15e0("hknpVehicleDefaultBrake", &D_57c26f8, sizeof(hknpVehicleDefaultBrake), 0,
                        0, 0, 0, D_1699460, 2, 0, 0, 0, 0);
extern const hkTypeInfo D_57c1630;
const hkTypeInfo D_57c1630("hknpVehicleDefaultBrake", "!hknpVehicleDefaultBrake",
                           finishLoadedObjecthknpVehicleDefaultBrake,
                           cleanupLoadedObjecthknpVehicleDefaultBrake,
                           vtableOfhknpVehicleDefaultBrake(), sizeof(hknpVehicleDefaultBrake));
