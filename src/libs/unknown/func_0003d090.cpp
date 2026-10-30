/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

extern const hkClassMember D_1696330[]; /* derived name: hknpPhysicsSystemData's records */

void FUN_0003d070(void *object, int finishing); /* derived name */
void FUN_000002d0(void *object);                /* derived name */

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
const hkTypeInfo D_57c0198("hknpPhysicsSystemData", "!hknpPhysicsSystemData", FUN_0003d070,
                           FUN_000002d0, vtableOfhknpPhysicsSystemData(),
                           sizeof(hknpPhysicsSystemData));
