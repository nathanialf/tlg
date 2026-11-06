/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hknpVehicleDefaultSuspension's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
static void finishLoadedObjecthknpVehicleDefaultSuspension(void *object,
                                                           int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpVehicleDefaultSuspension(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthknpVehicleDefaultSuspension(void *object) /* derived name */
{
    static_cast<hknpVehicleDefaultSuspension *>(object)->~hknpVehicleDefaultSuspension();
}

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0x3b640. */
static void cleanupLoadedObjecthknpVehicleDefaultSuspensionWheelSpringSuspensionParameters(
    void *object) /* derived name */
{
    static_cast<hknpVehicleDefaultSuspension::WheelSpringSuspensionParameters *>(object)
        ->~WheelSpringSuspensionParameters();
}

extern const hkClass D_57c2f98;         /* hknpVehicleSuspension's hkClass (func_00077f80.cpp) */
extern const hkClassMember D_1696920[]; /* derived name: the spring parameters' records */
extern const hkClassMember D_16969a0[]; /* derived name: the default suspension's record */

/* The address of hknpVehicleDefaultSuspension's vtable, read from an object
 * finished in a buffer (folded to the address point). */
static const void *vtableOfhknpVehicleDefaultSuspension() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hknpVehicleDefaultSuspension)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hknpVehicleDefaultSuspension(flag);
    return object.vtable;
}

/* This file's static initializer (0x3e5b0): the spring parameters'
 * reflection (no parent, three members) and type info, then
 * hknpVehicleDefaultSuspension's over hknpVehicleSuspension's (its one
 * member) and type info with its vtable. The type infos' names are the
 * base's strings. */
const hkClass D_57c06e8("hknpVehicleDefaultSuspensionWheelSpringSuspensionParameters", 0,
                        sizeof(hknpVehicleDefaultSuspension::WheelSpringSuspensionParameters), 0, 0,
                        0, 0, D_1696920, 3, 0, 0, 0, 0);
extern const hkTypeInfo D_57c0738;
const hkTypeInfo
    D_57c0738("hknpVehicleDefaultSuspensionWheelSpringSuspensionParameters",
              "!hknpVehicleDefaultSuspension::WheelSpringSuspensionParameters", 0,
              cleanupLoadedObjecthknpVehicleDefaultSuspensionWheelSpringSuspensionParameters, 0,
              sizeof(hknpVehicleDefaultSuspension::WheelSpringSuspensionParameters));
const hkClass D_57c0768("hknpVehicleDefaultSuspension", &D_57c2f98,
                        sizeof(hknpVehicleDefaultSuspension), 0, 0, 0, 0, D_16969a0, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57c07b8;
const hkTypeInfo D_57c07b8("hknpVehicleDefaultSuspension", "!hknpVehicleDefaultSuspension",
                           finishLoadedObjecthknpVehicleDefaultSuspension,
                           cleanupLoadedObjecthknpVehicleDefaultSuspension,
                           vtableOfhknpVehicleDefaultSuspension(),
                           sizeof(hknpVehicleDefaultSuspension));
