/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: the finish callback of hkMemoryMeshVertexBuffer's type info (0x57bdde8):
 * construct the object in place from a loaded image (the finish constructor
 * is out of line). */
static void finishLoadedObjecthkMemoryMeshVertexBuffer(void *object,
                                                       int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkMemoryMeshVertexBuffer(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthkMemoryMeshVertexBuffer(void *object) /* derived name */
{
    static_cast<hkMemoryMeshVertexBuffer *>(object)->~hkMemoryMeshVertexBuffer();
}

extern const hkClass D_57bca60;         /* hkMeshVertexBuffer's hkClass */
extern const hkClassMember D_1692590[]; /* derived name: hkMemoryMeshVertexBuffer's records */

/* The class's vtable, read from an object its out-of-line finish
 * constructor builds on the stack. derived name. */
static const void *vtableOfhkMemoryMeshVertexBuffer() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hkMemoryMeshVertexBuffer)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkMemoryMeshVertexBuffer(flag);
    return object.vtable;
}

/* This file's static initializer (0x2ae30): hkMemoryMeshVertexBuffer's reflection,
 * hkMeshVertexBuffer's as the parent, eight members, version 1,
 * then its type info (its finish callback, the destructor, the vtable). */
const hkClass D_57bdd98("hkMemoryMeshVertexBuffer", &D_57bca60, sizeof(hkMemoryMeshVertexBuffer), 0,
                        0, 0, 0, D_1692590, 8, 0, 0, 0, 1);
extern const hkTypeInfo D_57bdde8;
const hkTypeInfo D_57bdde8("hkMemoryMeshVertexBuffer", "!hkMemoryMeshVertexBuffer",
                           finishLoadedObjecthkMemoryMeshVertexBuffer,
                           cleanupLoadedObjecthkMemoryMeshVertexBuffer,
                           vtableOfhkMemoryMeshVertexBuffer(), sizeof(hkMemoryMeshVertexBuffer));
