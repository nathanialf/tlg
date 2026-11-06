/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hkAlignSceneToNodeOptions's type info (0x57c7288):
 * construct the object in place from a loaded image through its
 * out-of-line finish constructor. */
static void finishLoadedObjecthkAlignSceneToNodeOptions(void *object,
                                                        int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkAlignSceneToNodeOptions(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthkAlignSceneToNodeOptions(void *object) /* derived name */
{
    static_cast<hkAlignSceneToNodeOptions *>(object)->~hkAlignSceneToNodeOptions();
}

extern const hkClassMember D_16a18c0[]; /* derived name: hkAlignSceneToNodeOptions's records */

/* The address of hkAlignSceneToNodeOptions's vtable, read from an object finished in a
 * 16-byte aligned buffer (the finish constructor is out of line, 0x17d520, so the object is
 * built on the stack, as hkcdStaticAabbTree's in func_0001ff50.cpp). */
static const void *vtableOfhkAlignSceneToNodeOptions() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hkAlignSceneToNodeOptions)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkAlignSceneToNodeOptions(flag);
    return object.vtable;
}

/* This file's static initializer (0x89ee0): hkAlignSceneToNodeOptions's reflection over
 * hkReferencedObject's (version 2), its nine members, then its type info. */
const hkClass D_57c7238("hkAlignSceneToNodeOptions", &D_57b8640, sizeof(hkAlignSceneToNodeOptions),
                        0, 0, 0, 0, D_16a18c0, 9, 0, 0, 0, 2);
extern const hkTypeInfo D_57c7288;
const hkTypeInfo D_57c7288("hkAlignSceneToNodeOptions", "!hkAlignSceneToNodeOptions",
                           finishLoadedObjecthkAlignSceneToNodeOptions,
                           cleanupLoadedObjecthkAlignSceneToNodeOptions,
                           vtableOfhkAlignSceneToNodeOptions(), sizeof(hkAlignSceneToNodeOptions));
