/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type infos' own callbacks, this file's (static, docs/DECISIONS.md
 * D39): each class constructed in place from a loaded image through its
 * inline finish constructor, which has nothing to fix up but the vtable
 * (the finish callbacks kept at 0x378b0 and 0x378e0), and destroyed
 * through its virtual destructor (the body the linker folded, 0x2d0). */
static void finishLoadedObjecthknpVehicleDefaultAnalogDriverInput(void *object,
                                                                  int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpVehicleDefaultAnalogDriverInput(flag);
}

static void cleanupLoadedObjecthknpVehicleDefaultAnalogDriverInput(void *object) /* derived name */
{
    static_cast<hknpVehicleDefaultAnalogDriverInput *>(object)
        ->~hknpVehicleDefaultAnalogDriverInput();
}

static void finishLoadedObjecthknpVehicleDriverInputAnalogStatus(void *object,
                                                                 int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpVehicleDriverInputAnalogStatus(flag);
}

static void cleanupLoadedObjecthknpVehicleDriverInputAnalogStatus(void *object) /* derived name */
{
    static_cast<hknpVehicleDriverInputAnalogStatus *>(object)
        ->~hknpVehicleDriverInputAnalogStatus();
}

extern const hkClassMember D_1693820[]; /* derived name: the analog driver input's records */
extern const hkClassMember D_16938c0[]; /* derived name: the analog status's records */

/* The addresses of the two vtables, read from objects finished in a buffer
 * (folded to the address points). derived names. */
static const void *vtableOfhknpVehicleDefaultAnalogDriverInput() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hknpVehicleDefaultAnalogDriverInput)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hknpVehicleDefaultAnalogDriverInput(flag);
    return object.vtable;
}

static const void *vtableOfhknpVehicleDriverInputAnalogStatus() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hknpVehicleDriverInputAnalogStatus)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hknpVehicleDriverInputAnalogStatus(flag);
    return object.vtable;
}

/* This file's static initializer (0x37900): hknpVehicleDefaultAnalogDriverInput's
 * reflection over hknpVehicleDriverInput's (its four members) and type info,
 * then hknpVehicleDriverInputAnalogStatus's over hknpVehicleDriverInputStatus's
 * (its four members), each with its vtable. The type infos' names are the
 * base's strings. */
const hkClass D_57bec28("hknpVehicleDefaultAnalogDriverInput", &D_57be5a0,
                        sizeof(hknpVehicleDefaultAnalogDriverInput), 0, 0, 0, 0, D_1693820, 4, 0, 0,
                        0, 0);
extern const hkTypeInfo D_57bec78;
const hkTypeInfo D_57bec78("hknpVehicleDefaultAnalogDriverInput",
                           "!hknpVehicleDefaultAnalogDriverInput",
                           finishLoadedObjecthknpVehicleDefaultAnalogDriverInput,
                           cleanupLoadedObjecthknpVehicleDefaultAnalogDriverInput,
                           vtableOfhknpVehicleDefaultAnalogDriverInput(),
                           sizeof(hknpVehicleDefaultAnalogDriverInput));
const hkClass D_57beca8("hknpVehicleDriverInputAnalogStatus", &D_57be5f0,
                        sizeof(hknpVehicleDriverInputAnalogStatus), 0, 0, 0, 0, D_16938c0, 4, 0, 0,
                        0, 0);
extern const hkTypeInfo D_57becf8;
const hkTypeInfo D_57becf8("hknpVehicleDriverInputAnalogStatus",
                           "!hknpVehicleDriverInputAnalogStatus",
                           finishLoadedObjecthknpVehicleDriverInputAnalogStatus,
                           cleanupLoadedObjecthknpVehicleDriverInputAnalogStatus,
                           vtableOfhknpVehicleDriverInputAnalogStatus(),
                           sizeof(hknpVehicleDriverInputAnalogStatus));
