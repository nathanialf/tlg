/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

extern const hkClass D_57bca60;         /* hkMeshVertexBuffer's hkClass */
extern const hkClassMember D_1692590[]; /* derived name: hkMemoryMeshVertexBuffer's records */

void FUN_0002ae10(void *object, int finishing); /* derived name */
void FUN_000002d0(void *object);                /* derived name */

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
const hkTypeInfo D_57bdde8("hkMemoryMeshVertexBuffer", "!hkMemoryMeshVertexBuffer", FUN_0002ae10,
                           FUN_000002d0, vtableOfhkMemoryMeshVertexBuffer(),
                           sizeof(hkMemoryMeshVertexBuffer));
