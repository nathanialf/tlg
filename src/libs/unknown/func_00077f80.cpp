/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The wheel parameters' loaded-object cleanup: nothing to clean up (the
 * linker folded it into the shared empty body 0x3b640, FUN_0003b640). */
void FUN_0003b640(void *object) {}

extern const hkClassMember D_169b5c0[]; /* derived name: the wheel parameters' records */
extern const hkClassMember D_169b640[]; /* derived name: hknpVehicleSuspension's records */

/* This file's static initializer (0x77f80): the wheel parameters'
 * reflection (hkClass 0x57c2f18: no parent, three members) and type info
 * (no finish callback, no vtable; the name its hkClass spells, the scoped
 * name the base's string), then hknpVehicleSuspension's reflection over
 * hkReferencedObject's (hkClass 0x57c2f98: one member). */
const hkClass D_57c2f18("hknpVehicleSuspensionSuspensionWheelParameters", 0,
                        sizeof(hknpVehicleSuspension::SuspensionWheelParameters), 0, 0, 0, 0,
                        D_169b5c0, 3, 0, 0, 0, 0);
extern const hkTypeInfo D_57c2f68;
const hkTypeInfo D_57c2f68("hknpVehicleSuspensionSuspensionWheelParameters",
                           "!hknpVehicleSuspension::SuspensionWheelParameters", 0, FUN_0003b640, 0,
                           sizeof(hknpVehicleSuspension::SuspensionWheelParameters));
const hkClass D_57c2f98("hknpVehicleSuspension", &D_57b8640, sizeof(hknpVehicleSuspension), 0, 0, 0,
                        0, D_169b640, 1, 0, 0, 0, 0);
