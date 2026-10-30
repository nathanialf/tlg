/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hknpVehicleDefaultEngine's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
void FUN_00046b70(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpVehicleDefaultEngine(flag);
}

/* hknpVehicleDefaultEngine's cleanup callback: the virtual destructor (the shared body 0x2d0). */
void FUN_000002d0(void *object);
extern const hkClassMember D_1698000[]; /* derived name: hknpVehicleDefaultEngine's records */

/* The address of hknpVehicleDefaultEngine's vtable, read from an object finished in a buffer
 * (folded to the address point). */
static const void *vtableOfhknpVehicleDefaultEngine() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hknpVehicleDefaultEngine)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hknpVehicleDefaultEngine(flag);
    return object.vtable;
}

/* This file's static initializer (0x46b90): hknpVehicleDefaultEngine's reflection over hknpVehicleEngine's, its 10 members, then its type info. */
const hkClass D_57c1310("hknpVehicleDefaultEngine", &D_57bff60, sizeof(hknpVehicleDefaultEngine), 0,
                        0, 0, 0, D_1698000, 10, 0, 0, 0, 0);
extern const hkTypeInfo D_57c1360;
const hkTypeInfo D_57c1360("hknpVehicleDefaultEngine", "!hknpVehicleDefaultEngine", FUN_00046b70,
                           FUN_000002d0, vtableOfhknpVehicleDefaultEngine(),
                           sizeof(hknpVehicleDefaultEngine));
