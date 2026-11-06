/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: the finish callback of hkMemoryMeshMaterial's type info (0x57bd4a8):
 * construct the object in place from a loaded image through its out-of-line
 * finish constructor. */
static void finishLoadedObjecthkMemoryMeshMaterial(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkMemoryMeshMaterial(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthkMemoryMeshMaterial(void *object) /* derived name */
{
    static_cast<hkMemoryMeshMaterial *>(object)->~hkMemoryMeshMaterial();
}

extern const hkClass D_57bd680;         /* hkMeshMaterial's hkClass */
extern const hkClassMember D_1691e80[]; /* derived name: hkMemoryMeshMaterial's records */

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
const hkTypeInfo D_57bd4a8("hkMemoryMeshMaterial", "!hkMemoryMeshMaterial",
                           finishLoadedObjecthkMemoryMeshMaterial,
                           cleanupLoadedObjecthkMemoryMeshMaterial, vtableOfhkMemoryMeshMaterial(),
                           sizeof(hkMemoryMeshMaterial));
