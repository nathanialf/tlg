/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The wheel information's cleanup callback: nothing to clean up (the
 * linker folded it into the empty body 0x3b640; D15's round 57 addendum). */
void FUN_0003b640(void *object) {}

/* hknpVehicleInstance's finish callback (func_00047990.cpp) and cleanup
 * callback (the virtual destructor, the shared body 0x2d0). */
void FUN_00047990(void *object, int finishing);
void FUN_000002d0(void *object);

extern const hkClass D_57bfbc0;         /* hknpUnaryAction's hkClass */
extern const hkClassMember D_16987a0[]; /* derived name: the wheel information's records */
extern const hkClassMember D_1698a70[]; /* derived name: hknpVehicleInstance's records */

/* The address of hknpVehicleInstance's vtable, read from an object finished
 * in a buffer (folded to the address point). */
static const void *vtableOfhknpVehicleInstance() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hknpVehicleInstance)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hknpVehicleInstance(flag);
    return object.vtable;
}

/* This file's static initializer (0x479c0): hknpVehicleInstance::
 * WheelInfo's reflection (no parent, eighteen members) and type info, then
 * hknpVehicleInstance's over hknpUnaryAction's (27 members) and type info
 * with its vtable. The type infos' names are the base's strings. */
const hkClass D_57c1410("hknpVehicleInstanceWheelInfo", 0, sizeof(hknpVehicleInstance::WheelInfo),
                        0, 0, 0, 0, D_16987a0, 18, 0, 0, 0, 0);
extern const hkTypeInfo D_57c1460;
const hkTypeInfo D_57c1460("hknpVehicleInstanceWheelInfo", "!hknpVehicleInstance::WheelInfo", 0,
                           FUN_0003b640, 0, sizeof(hknpVehicleInstance::WheelInfo));
const hkClass D_57c1490("hknpVehicleInstance", &D_57bfbc0, sizeof(hknpVehicleInstance), 0, 0, 0, 0,
                        D_1698a70, 27, 0, 0, 0, 0);
extern const hkTypeInfo D_57c14e0;
const hkTypeInfo D_57c14e0("hknpVehicleInstance", "!hknpVehicleInstance", FUN_00047990,
                           FUN_000002d0, vtableOfhknpVehicleInstance(),
                           sizeof(hknpVehicleInstance));
