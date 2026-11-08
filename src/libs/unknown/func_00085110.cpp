/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type infos' own callbacks, this file's (static, docs/DECISIONS.md
 * D39): the friction description constructed in place from a loaded image
 * through its inline finish constructor, which has nothing to fix up but
 * the vtable (the finish callback kept at 0x85110), and destroyed through
 * its virtual destructor (the body the linker folded, 0x2d0); the others'
 * callbacks have nothing to do and the linker folded them into the shared
 * empty body 0x83250. derived names. */
static void cleanupLoadedObjecthkpVehicleFrictionDescriptionAxisDescription(void *object)
{
    static_cast<hkpVehicleFrictionDescription::AxisDescription *>(object)->~AxisDescription();
}

static void finishLoadedObjecthkpVehicleFrictionDescription(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpVehicleFrictionDescription(flag);
}

static void cleanupLoadedObjecthkpVehicleFrictionDescription(void *object)
{
    static_cast<hkpVehicleFrictionDescription *>(object)->~hkpVehicleFrictionDescription();
}

static void finishLoadedObjecthkpVehicleFrictionStatusAxisStatus(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpVehicleFrictionStatus::AxisStatus(flag);
}

static void cleanupLoadedObjecthkpVehicleFrictionStatusAxisStatus(void *object)
{
    static_cast<hkpVehicleFrictionStatus::AxisStatus *>(object)->~AxisStatus();
}

static void finishLoadedObjecthkpVehicleFrictionStatus(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpVehicleFrictionStatus(flag);
}

static void cleanupLoadedObjecthkpVehicleFrictionStatus(void *object)
{
    static_cast<hkpVehicleFrictionStatus *>(object)->~hkpVehicleFrictionStatus();
}

/* The address of the friction description's vtable, read from an object
 * finished in a buffer (folded to the address point). derived name. */
static const void *vtableOfhkpVehicleFrictionDescription()
{
    union {
        void *vtable;
        char buffer[sizeof(hkpVehicleFrictionDescription)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkpVehicleFrictionDescription(flag);
    return object.vtable;
}

extern const hkClass D_57b8640; /* hkReferencedObject's hkClass */

extern const hkClassMember D_16a03e0[]; /* derived name: the axle description's records */
extern const hkClassMember D_16a06e0[]; /* derived name: the friction description's records */
extern const hkClassMember D_16a0570[]; /* derived name: the axle status's records */
extern const hkClassMember D_16a0760[]; /* derived name: the friction status's records */

/* This file's static initializer (0x85190): the friction description's
 * axle and the description over hkReferencedObject's (version 1), then the
 * friction status's axle and the status, each with its type info. The type
 * infos' names are the base's strings. */
const hkClass D_57c5c78("hkpVehicleFrictionDescriptionAxisDescription", 0,
                        sizeof(hkpVehicleFrictionDescription::AxisDescription), 0, 0, 0, 0,
                        D_16a03e0, 10, 0, 0, 0, 0);
extern const hkTypeInfo D_57c5cc8;
const hkTypeInfo D_57c5cc8("hkpVehicleFrictionDescriptionAxisDescription",
                           "!hkpVehicleFrictionDescription::AxisDescription", 0,
                           cleanupLoadedObjecthkpVehicleFrictionDescriptionAxisDescription, 0,
                           sizeof(hkpVehicleFrictionDescription::AxisDescription));
const hkClass D_57c5cf8("hkpVehicleFrictionDescription", &D_57b8640,
                        sizeof(hkpVehicleFrictionDescription), 0, 0, 0, 0, D_16a06e0, 3, 0, 0, 0,
                        1);
extern const hkTypeInfo D_57c5d48;
const hkTypeInfo D_57c5d48("hkpVehicleFrictionDescription", "!hkpVehicleFrictionDescription",
                           finishLoadedObjecthkpVehicleFrictionDescription,
                           cleanupLoadedObjecthkpVehicleFrictionDescription,
                           vtableOfhkpVehicleFrictionDescription(),
                           sizeof(hkpVehicleFrictionDescription));
const hkClass D_57c5d78("hkpVehicleFrictionStatusAxisStatus", 0,
                        sizeof(hkpVehicleFrictionStatus::AxisStatus), 0, 0, 0, 0, D_16a0570, 9, 0,
                        0, 0, 0);
extern const hkTypeInfo D_57c5dc8;
const hkTypeInfo D_57c5dc8("hkpVehicleFrictionStatusAxisStatus",
                           "!hkpVehicleFrictionStatus::AxisStatus",
                           finishLoadedObjecthkpVehicleFrictionStatusAxisStatus,
                           cleanupLoadedObjecthkpVehicleFrictionStatusAxisStatus, 0,
                           sizeof(hkpVehicleFrictionStatus::AxisStatus));
const hkClass D_57c5df8("hkpVehicleFrictionStatus", 0, sizeof(hkpVehicleFrictionStatus), 0, 0, 0, 0,
                        D_16a0760, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57c5e48;
const hkTypeInfo D_57c5e48("hkpVehicleFrictionStatus", "!hkpVehicleFrictionStatus",
                           finishLoadedObjecthkpVehicleFrictionStatus,
                           cleanupLoadedObjecthkpVehicleFrictionStatus, 0,
                           sizeof(hkpVehicleFrictionStatus));
