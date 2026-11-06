/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hknpVehicleLinearCastWheelCollide's type info (registered at
 * 0x708de): construct the object in place from a loaded image through its
 * inline finish constructor. */
static void finishLoadedObjecthknpVehicleLinearCastWheelCollide(void *object,
                                                                int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpVehicleLinearCastWheelCollide(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthknpVehicleLinearCastWheelCollide(void *object) /* derived name */
{
    static_cast<hknpVehicleLinearCastWheelCollide *>(object)->~hknpVehicleLinearCastWheelCollide();
}

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0x3b640. */
static void
cleanupLoadedObjecthknpVehicleLinearCastWheelCollideWheelState(void *object) /* derived name */
{
    static_cast<hknpVehicleLinearCastWheelCollide::WheelState *>(object)->~WheelState();
}

extern const hkClassMember D_169afc0[]; /* derived name: the wheel state's records */
extern const hkClassMember D_169b060[]; /* derived name: the linear cast's records */

/* The address of hknpVehicleLinearCastWheelCollide's vtable, read from an
 * object finished in a buffer (folded to the address point). */
static const void *vtableOfhknpVehicleLinearCastWheelCollide() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hknpVehicleLinearCastWheelCollide)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hknpVehicleLinearCastWheelCollide(flag);
    return object.vtable;
}

/* This file's static initializer (0x70790): the wheel state's reflection
 * (no parent, four members) and type info, then
 * hknpVehicleLinearCastWheelCollide's over hknpVehicleWheelCollide's (four
 * members) and type info with its vtable. The type infos' names are the
 * base's strings. */
const hkClass D_57c2bf8("hknpVehicleLinearCastWheelCollideWheelState", 0,
                        sizeof(hknpVehicleLinearCastWheelCollide::WheelState), 0, 0, 0, 0,
                        D_169afc0, 4, 0, 0, 0, 0);
extern const hkTypeInfo D_57c2c48;
const hkTypeInfo D_57c2c48("hknpVehicleLinearCastWheelCollideWheelState",
                           "!hknpVehicleLinearCastWheelCollide::WheelState", 0,
                           cleanupLoadedObjecthknpVehicleLinearCastWheelCollideWheelState, 0,
                           sizeof(hknpVehicleLinearCastWheelCollide::WheelState));
const hkClass D_57c2c78("hknpVehicleLinearCastWheelCollide", &D_57c1510,
                        sizeof(hknpVehicleLinearCastWheelCollide), 0, 0, 0, 0, D_169b060, 4, 0, 0,
                        0, 0);
extern const hkTypeInfo D_57c2cc8;
const hkTypeInfo D_57c2cc8("hknpVehicleLinearCastWheelCollide",
                           "!hknpVehicleLinearCastWheelCollide",
                           finishLoadedObjecthknpVehicleLinearCastWheelCollide,
                           cleanupLoadedObjecthknpVehicleLinearCastWheelCollide,
                           vtableOfhknpVehicleLinearCastWheelCollide(),
                           sizeof(hknpVehicleLinearCastWheelCollide));
