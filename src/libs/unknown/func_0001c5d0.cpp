/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type infos' own callbacks, this file's (static, docs/DECISIONS.md
 * D39): nothing to clean up in either class; the linker folded both into
 * the empty body 0x1c1e0. */
static void cleanupLoadedObjecthkAabb(void *object)
{
    static_cast<hkAabb *>(object)->~hkAabb();
}

static void cleanupLoadedObjecthkAabbUint32(void *object)
{
    static_cast<hkAabbUint32 *>(object)->~hkAabbUint32();
}

/* This file's static initializer (0x1c5d0): hkAabb's reflection (no
 * parent, its two members) and type info, then hkAabbUint32's (its six
 * members), neither with a finish callback or a vtable. The type infos'
 * names are the base's strings. */
const hkClass D_57b9c20("hkAabb", 0, sizeof(hkAabb), 0, 0, 0, 0, D_168eb70, 2, 0, 0, 0, 0);
extern const hkTypeInfo D_57b9c70;
const hkTypeInfo D_57b9c70("hkAabb", "!hkAabb", 0, cleanupLoadedObjecthkAabb, 0, sizeof(hkAabb));
const hkClass D_57b9ca0("hkAabbUint32", 0, sizeof(hkAabbUint32), 0, 0, 0, 0, D_168ebc0, 6, 0, 0, 0,
                        0);
extern const hkTypeInfo D_57b9cf0;
const hkTypeInfo D_57b9cf0("hkAabbUint32", "!hkAabbUint32", 0, cleanupLoadedObjecthkAabbUint32, 0,
                           sizeof(hkAabbUint32));
