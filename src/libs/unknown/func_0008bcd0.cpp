/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkxVertexSelectionChannel's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
static void finishLoadedObjecthkxVertexSelectionChannel(void *object,
                                                        int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxVertexSelectionChannel(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthkxVertexSelectionChannel(void *object) /* derived name */
{
    static_cast<hkxVertexSelectionChannel *>(object)->~hkxVertexSelectionChannel();
}

/* The class's vtable, read from an object its finish constructor builds
 * (cookbook 166). derived name. */
static const void *vtableOfhkxVertexSelectionChannel() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hkxVertexSelectionChannel)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkxVertexSelectionChannel(flag);
    return object.vtable;
}

/* This file's static initializer (0x8bcf0): hkxVertexSelectionChannel's reflection,
 * hkReferencedObject's as the parent, its one member, version 1, then its
 * type info (its finish callback, the destructor, the vtable). */
const hkClass D_57c7a00("hkxVertexSelectionChannel", &D_57b8640, sizeof(hkxVertexSelectionChannel),
                        0, 0, 0, 0, D_16a2540, 1, 0, 0, 0, 1);
extern const hkTypeInfo D_57c7a50;
const hkTypeInfo D_57c7a50("hkxVertexSelectionChannel", "!hkxVertexSelectionChannel",
                           finishLoadedObjecthkxVertexSelectionChannel,
                           cleanupLoadedObjecthkxVertexSelectionChannel,
                           vtableOfhkxVertexSelectionChannel(), sizeof(hkxVertexSelectionChannel));
