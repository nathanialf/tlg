/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hknpVehicleInstance's type info
 * (registered at 0x47b06): construct the vehicle in place from a loaded
 * image. */
static void finishLoadedObjecthknpVehicleInstance(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpVehicleInstance(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthknpVehicleInstance(void *object) /* derived name */
{
    static_cast<hknpVehicleInstance *>(object)->~hknpVehicleInstance();
}

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0x3b640. */
static void cleanupLoadedObjecthknpVehicleInstanceWheelInfo(void *object) /* derived name */
{
    static_cast<hknpVehicleInstance::WheelInfo *>(object)->~WheelInfo();
}

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
                           cleanupLoadedObjecthknpVehicleInstanceWheelInfo, 0,
                           sizeof(hknpVehicleInstance::WheelInfo));
const hkClass D_57c1490("hknpVehicleInstance", &D_57bfbc0, sizeof(hknpVehicleInstance), 0, 0, 0, 0,
                        D_1698a70, 27, 0, 0, 0, 0);
extern const hkTypeInfo D_57c14e0;
const hkTypeInfo D_57c14e0("hknpVehicleInstance", "!hknpVehicleInstance",
                           finishLoadedObjecthknpVehicleInstance,
                           cleanupLoadedObjecthknpVehicleInstance, vtableOfhknpVehicleInstance(),
                           sizeof(hknpVehicleInstance));
