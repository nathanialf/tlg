/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hknpVehicleRayCastWheelCollide's type info (registered at
 * 0x7604a): construct the object in place from a loaded image through its
 * inline finish constructor. */
static void finishLoadedObjecthknpVehicleRayCastWheelCollide(void *object,
                                                             int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpVehicleRayCastWheelCollide(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthknpVehicleRayCastWheelCollide(void *object) /* derived name */
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
                           finishLoadedObjecthknpVehicleRayCastWheelCollide,
                           cleanupLoadedObjecthknpVehicleRayCastWheelCollide,
                           vtableOfhknpVehicleRayCastWheelCollide(),
                           sizeof(hknpVehicleRayCastWheelCollide));
