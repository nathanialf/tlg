/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: the finish callback of hknpPhysicsSystemData's type info (0x57c0198):
 * construct the object in place from a loaded image through its out-of-line
 * finish constructor. */
static void finishLoadedObjecthknpPhysicsSystemData(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpPhysicsSystemData(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthknpPhysicsSystemData(void *object) /* derived name */
{
    static_cast<hknpPhysicsSystemData *>(object)->~hknpPhysicsSystemData();
}

extern const hkClassMember D_1696330[]; /* derived name: hknpPhysicsSystemData's records */

/* The class's vtable, read from an object its out-of-line finish
 * constructor builds on the stack. derived name. */
static const void *vtableOfhknpPhysicsSystemData() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hknpPhysicsSystemData)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpPhysicsSystemData(flag);
    return object.vtable;
}

/* This file's static initializer (0x3d090): hknpPhysicsSystemData's reflection,
 * hkReferencedObject's as the parent, seven members,
 * then its type info (its finish callback, the destructor, the vtable). */
const hkClass D_57c0148("hknpPhysicsSystemData", &D_57b8640, sizeof(hknpPhysicsSystemData), 0, 0, 0,
                        0, D_1696330, 7, 0, 0, 0, 0);
extern const hkTypeInfo D_57c0198;
const hkTypeInfo D_57c0198("hknpPhysicsSystemData", "!hknpPhysicsSystemData",
                           finishLoadedObjecthknpPhysicsSystemData,
                           cleanupLoadedObjecthknpPhysicsSystemData,
                           vtableOfhknpPhysicsSystemData(), sizeof(hknpPhysicsSystemData));
