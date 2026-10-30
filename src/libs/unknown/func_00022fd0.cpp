/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

extern const hkClass D_57bd408;         /* hkMeshBody's hkClass */
extern const hkClassMember D_1691530[]; /* derived name: hkMemoryMeshBody's records */

void FUN_00022fb0(void *object, int finishing); /* derived name */
void FUN_000002d0(void *object);                /* derived name */

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
const hkTypeInfo D_57bccf0("hkMemoryMeshBody", "!hkMemoryMeshBody", FUN_00022fb0, FUN_000002d0,
                           vtableOfhkMemoryMeshBody(), sizeof(hkMemoryMeshBody));
