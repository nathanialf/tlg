/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkxBlob's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
static void finishLoadedObjecthkxBlob(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxBlob(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthkxBlob(void *object) /* derived name */
{
    static_cast<hkxBlob *>(object)->~hkxBlob();
}

/* The class's vtable, read from an object its finish constructor builds
 * (cookbook 166). derived name. */
static const void *vtableOfhkxBlob() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hkxBlob)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkxBlob(flag);
    return object.vtable;
}

/* This file's static initializer (0x8bde0): hkxBlob's reflection,
 * hkReferencedObject's as the parent, its one member, version 1, then its
 * type info (its finish callback, the destructor, the vtable). */
const hkClass D_57c7a80("hkxBlob", &D_57b8640, sizeof(hkxBlob), 0, 0, 0, 0, D_16a2570, 1, 0, 0, 0,
                        1);
extern const hkTypeInfo D_57c7ad0;
const hkTypeInfo D_57c7ad0("hkxBlob", "!hkxBlob", finishLoadedObjecthkxBlob,
                           cleanupLoadedObjecthkxBlob, vtableOfhkxBlob(), sizeof(hkxBlob));
