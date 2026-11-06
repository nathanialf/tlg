/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0x1c1e0. */
static void finishLoadedObjecthkcdAdf(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkcdAdf(flag);
}

/* The cleanup callback (0x1f1e0): the field destroyed in place, its
 * voxels' storage given back, then its nodes'. */
static void cleanupLoadedObjecthkcdAdf(void *object) /* derived name */
{
    static_cast<hkcdAdf *>(object)->~hkcdAdf();
}

/* This file's static initializer (0x1f260): hkcdAdf's reflection (hkClass
 * 0x57bb290: no parent, its seven members), then its type info (the
 * cleanup callback 0x1f1e0, no vtable). */
const hkClass D_57bb290("hkcdAdf", 0, sizeof(hkcdAdf), 0, 0, 0, 0, D_16900c0, 7, 0, 0, 0, 0);
extern const hkTypeInfo D_57bb2e0;
const hkTypeInfo D_57bb2e0("hkcdAdf", "!hkcdAdf", finishLoadedObjecthkcdAdf,
                           cleanupLoadedObjecthkcdAdf, 0, sizeof(hkcdAdf));
