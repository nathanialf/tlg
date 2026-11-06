/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkxTextureInplace's type info (the
 * reflection initializer passes it at 0x8acb6): construct the object in place
 * from a loaded image. */
static void finishLoadedObjecthkxTextureInplace(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxTextureInplace(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthkxTextureInplace(void *object) /* derived name */
{
    static_cast<hkxTextureInplace *>(object)->~hkxTextureInplace();
}

extern const hkClassMember D_16a1dd0[]; /* derived name: hkxTextureInplace's records */

/* The address of hkxTextureInplace's vtable, read from an object finished
 * in a 16-byte aligned buffer: the finish constructor is inline, but the
 * strings' in it are out of line (0xe5c0), so the object is built on the
 * stack, as in func_000224f0.cpp. */
static const void *vtableOfhkxTextureInplace() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hkxTextureInplace)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkxTextureInplace(flag);
    return object.vtable;
}

/* This file's static initializer (0x8ac00): hkxTextureInplace's reflection
 * over hkReferencedObject's (version 1), its four members, then its type
 * info. */
const hkClass D_57c7530("hkxTextureInplace", &D_57b8640, sizeof(hkxTextureInplace), 0, 0, 0, 0,
                        D_16a1dd0, 4, 0, 0, 0, 1);
extern const hkTypeInfo D_57c7580;
const hkTypeInfo D_57c7580("hkxTextureInplace", "!hkxTextureInplace",
                           finishLoadedObjecthkxTextureInplace,
                           cleanupLoadedObjecthkxTextureInplace, vtableOfhkxTextureInplace(),
                           sizeof(hkxTextureInplace));
