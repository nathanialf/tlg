/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hknpVehicleDefaultTransmission's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
static void finishLoadedObjecthknpVehicleDefaultTransmission(void *object,
                                                             int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpVehicleDefaultTransmission(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthknpVehicleDefaultTransmission(void *object) /* derived name */
{
    static_cast<hknpVehicleDefaultTransmission *>(object)->~hknpVehicleDefaultTransmission();
}

extern const hkClassMember D_1693960[]; /* derived name: hknpVehicleDefaultTransmission's records */

/* The address of hknpVehicleDefaultTransmission's vtable, read from an object finished in a buffer
 * (folded to the address point). */
static const void *vtableOfhknpVehicleDefaultTransmission() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hknpVehicleDefaultTransmission)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hknpVehicleDefaultTransmission(flag);
    return object.vtable;
}

/* This file's static initializer (0x37ab0): hknpVehicleDefaultTransmission's reflection over hknpVehicleTransmission's, its 7 members, then its type info. */
const hkClass D_57bed28("hknpVehicleDefaultTransmission", &D_57bff10,
                        sizeof(hknpVehicleDefaultTransmission), 0, 0, 0, 0, D_1693960, 7, 0, 0, 0,
                        0);
extern const hkTypeInfo D_57bed78;
const hkTypeInfo D_57bed78("hknpVehicleDefaultTransmission", "!hknpVehicleDefaultTransmission",
                           finishLoadedObjecthknpVehicleDefaultTransmission,
                           cleanupLoadedObjecthknpVehicleDefaultTransmission,
                           vtableOfhknpVehicleDefaultTransmission(),
                           sizeof(hknpVehicleDefaultTransmission));
