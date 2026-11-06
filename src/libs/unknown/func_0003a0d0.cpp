/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hknpVehicleDefaultAerodynamics's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
static void finishLoadedObjecthknpVehicleDefaultAerodynamics(void *object,
                                                             int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpVehicleDefaultAerodynamics(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthknpVehicleDefaultAerodynamics(void *object) /* derived name */
{
    static_cast<hknpVehicleDefaultAerodynamics *>(object)->~hknpVehicleDefaultAerodynamics();
}

extern const hkClassMember D_1695170[]; /* derived name: hknpVehicleDefaultAerodynamics's records */

/* The address of hknpVehicleDefaultAerodynamics's vtable, read from an object finished in a buffer
 * (folded to the address point). */
static const void *vtableOfhknpVehicleDefaultAerodynamics() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hknpVehicleDefaultAerodynamics)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hknpVehicleDefaultAerodynamics(flag);
    return object.vtable;
}

/* This file's static initializer (0x3a0f0): hknpVehicleDefaultAerodynamics's reflection over hknpVehicleAerodynamics's, its 5 members, then its type info. */
const hkClass D_57bf8d0("hknpVehicleDefaultAerodynamics", &D_57bf880,
                        sizeof(hknpVehicleDefaultAerodynamics), 0, 0, 0, 0, D_1695170, 5, 0, 0, 0,
                        0);
extern const hkTypeInfo D_57bf920;
const hkTypeInfo D_57bf920("hknpVehicleDefaultAerodynamics", "!hknpVehicleDefaultAerodynamics",
                           finishLoadedObjecthknpVehicleDefaultAerodynamics,
                           cleanupLoadedObjecthknpVehicleDefaultAerodynamics,
                           vtableOfhknpVehicleDefaultAerodynamics(),
                           sizeof(hknpVehicleDefaultAerodynamics));
