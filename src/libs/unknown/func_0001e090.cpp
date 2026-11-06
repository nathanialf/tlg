/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0x1c1e0. */
static void finishLoadedObjecthkcdFourAabb(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkcdFourAabb(flag);
}

static void cleanupLoadedObjecthkcdFourAabb(void *object) /* derived name */
{
    static_cast<hkcdFourAabb *>(object)->~hkcdFourAabb();
}

/* This file's static initializer (0x1e090): hkcdFourAabb's reflection
 * (hkClass 0x57ba890: no parent, its one enum and six members), then its
 * type info (no vtable). */
const hkClass D_57ba890("hkcdFourAabb", 0, sizeof(hkcdFourAabb), 0, 0, D_168fdb0, 1, D_168fc60, 6,
                        0, 0, 0, 0);
extern const hkTypeInfo D_57ba8e0;
const hkTypeInfo D_57ba8e0("hkcdFourAabb", "!hkcdFourAabb", finishLoadedObjecthkcdFourAabb,
                           cleanupLoadedObjecthkcdFourAabb, 0, sizeof(hkcdFourAabb));
