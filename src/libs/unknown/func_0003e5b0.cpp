/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The spring parameters' cleanup callback: nothing to clean up (the
 * linker folded it into the empty body 0x3b640; D15's round 57 addendum). */
void FUN_0003b640(void *object) {}

/* hknpVehicleDefaultSuspension's finish callback (func_0003e590.cpp) and
 * cleanup callback (the virtual destructor, the shared body 0x2d0). */
void FUN_0003e590(void *object, int finishing);
void FUN_000002d0(void *object);

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
const hkTypeInfo D_57c0738("hknpVehicleDefaultSuspensionWheelSpringSuspensionParameters",
                           "!hknpVehicleDefaultSuspension::WheelSpringSuspensionParameters", 0,
                           FUN_0003b640, 0,
                           sizeof(hknpVehicleDefaultSuspension::WheelSpringSuspensionParameters));
const hkClass D_57c0768("hknpVehicleDefaultSuspension", &D_57c2f98,
                        sizeof(hknpVehicleDefaultSuspension), 0, 0, 0, 0, D_16969a0, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57c07b8;
const hkTypeInfo D_57c07b8("hknpVehicleDefaultSuspension", "!hknpVehicleDefaultSuspension",
                           FUN_0003e590, FUN_000002d0, vtableOfhknpVehicleDefaultSuspension(),
                           sizeof(hknpVehicleDefaultSuspension));
