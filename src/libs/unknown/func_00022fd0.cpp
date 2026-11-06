/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: the finish callback of hkMemoryMeshBody's type info (0x57bccf0):
 * construct the object in place from a loaded image through its out-of-line
 * finish constructor. */
static void finishLoadedObjecthkMemoryMeshBody(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkMemoryMeshBody(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthkMemoryMeshBody(void *object) /* derived name */
{
    static_cast<hkMemoryMeshBody *>(object)->~hkMemoryMeshBody();
}

extern const hkClass D_57bd408;         /* hkMeshBody's hkClass */
extern const hkClassMember D_1691530[]; /* derived name: hkMemoryMeshBody's records */

/* The class's vtable, read from an object its out-of-line finish
 * constructor builds on the stack. derived name. */
static const void *vtableOfhkMemoryMeshBody() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hkMemoryMeshBody)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkMemoryMeshBody(flag);
    return object.vtable;
}

/* This file's static initializer (0x22fd0): hkMemoryMeshBody's reflection,
 * hkMeshBody's as the parent, five members,
 * then its type info (its finish callback, the destructor, the vtable). */
const hkClass D_57bcca0("hkMemoryMeshBody", &D_57bd408, sizeof(hkMemoryMeshBody), 0, 0, 0, 0,
                        D_1691530, 5, 0, 0, 0, 0);
extern const hkTypeInfo D_57bccf0;
const hkTypeInfo D_57bccf0("hkMemoryMeshBody", "!hkMemoryMeshBody",
                           finishLoadedObjecthkMemoryMeshBody, cleanupLoadedObjecthkMemoryMeshBody,
                           vtableOfhkMemoryMeshBody(), sizeof(hkMemoryMeshBody));
