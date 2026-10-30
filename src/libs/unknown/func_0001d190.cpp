/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the finish callback of hkcdPlanarEntity's type info
 * (registered at 0x1d253): construct the object in place from a loaded image. */
void FUN_0001d190(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkcdPlanarEntity(flag);
}

/* hkcdPlanarEntity's cleanup callback: the virtual destructor (the shared body 0x2d0). */
void FUN_000002d0(void *object);
extern const hkClassMember D_168f3f0[]; /* derived name: hkcdPlanarEntity's records */

/* The address of hkcdPlanarEntity's vtable, read from an object finished in a buffer
 * (folded to the address point). */
static const void *vtableOfhkcdPlanarEntity() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hkcdPlanarEntity)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hkcdPlanarEntity(flag);
    return object.vtable;
}

/* This file's static initializer (0x1d1c0): hkcdPlanarEntity's reflection over hkReferencedObject's, its one member, then its type info. */
const hkClass D_57ba190("hkcdPlanarEntity", &D_57b8640, sizeof(hkcdPlanarEntity), 0, 0, 0, 0,
                        D_168f3f0, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57ba1e0;
const hkTypeInfo D_57ba1e0("hkcdPlanarEntity", "!hkcdPlanarEntity", FUN_0001d190, FUN_000002d0,
                           vtableOfhkcdPlanarEntity(), sizeof(hkcdPlanarEntity));
