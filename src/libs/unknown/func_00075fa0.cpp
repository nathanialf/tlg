/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hknpVehicleRayCastWheelCollide's loaded-object cleanup: the virtual
 * destructor (the linker folded it with the other classes' identical body,
 * 0x2d0, FUN_000002d0). */
void FUN_000002d0(void *object)
{
    static_cast<hknpVehicleRayCastWheelCollide *>(object)->~hknpVehicleRayCastWheelCollide();
}

/* The class's vtable, read from an object its finish constructor builds
 * (cookbook 166). derived name. */
static const void *vtableOfhknpVehicleRayCastWheelCollide() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hknpVehicleRayCastWheelCollide)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpVehicleRayCastWheelCollide(flag);
    return object.vtable;
}

/* This file's static initializer (0x75fa0): hknpVehicleRayCastWheelCollide's
 * reflection, hknpVehicleWheelCollide's as the parent, no members, version
 * 1, then its type info (its finish callback, the destructor, the
 * vtable). */
const hkClass D_57c2d78("hknpVehicleRayCastWheelCollide", &D_57c1510,
                        sizeof(hknpVehicleRayCastWheelCollide), 0, 0, 0, 0, 0, 0, 0, 0, 0, 1);
extern const hkTypeInfo D_57c2dc8;
const hkTypeInfo D_57c2dc8("hknpVehicleRayCastWheelCollide", "!hknpVehicleRayCastWheelCollide",
                           FUN_00075f60, FUN_000002d0, vtableOfhknpVehicleRayCastWheelCollide(),
                           sizeof(hknpVehicleRayCastWheelCollide));
