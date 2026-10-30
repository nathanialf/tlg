/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

extern const hkClass D_57bd680;         /* hkMeshMaterial's hkClass */
extern const hkClassMember D_1691e80[]; /* derived name: hkMemoryMeshMaterial's records */

void FUN_000246d0(void *object, int finishing); /* derived name */
void FUN_000002d0(void *object);                /* derived name */

/* The class's vtable, read from an object its out-of-line finish
 * constructor builds on the stack. derived name. */
static const void *vtableOfhkMemoryMeshMaterial() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hkMemoryMeshMaterial)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkMemoryMeshMaterial(flag);
    return object.vtable;
}

/* This file's static initializer (0x246f0): hkMemoryMeshMaterial's reflection,
 * hkMeshMaterial's as the parent, nine members, version 2,
 * then its type info (its finish callback, the destructor, the vtable). */
const hkClass D_57bd458("hkMemoryMeshMaterial", &D_57bd680, sizeof(hkMemoryMeshMaterial), 0, 0, 0,
                        0, D_1691e80, 9, 0, 0, 0, 2);
extern const hkTypeInfo D_57bd4a8;
const hkTypeInfo D_57bd4a8("hkMemoryMeshMaterial", "!hkMemoryMeshMaterial", FUN_000246d0,
                           FUN_000002d0, vtableOfhkMemoryMeshMaterial(),
                           sizeof(hkMemoryMeshMaterial));
