/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type infos' own callbacks, this file's (static, docs/DECISIONS.md
 * D39): nothing to clean up in either class; the linker folded both into
 * the empty body 0xe5c0. */
static void cleanupLoadedObjecthkPackedVector3(void *object)
{
    static_cast<hkPackedVector3 *>(object)->~hkPackedVector3();
}

static void cleanupLoadedObjecthkPackedVector8_3(void *object)
{
    static_cast<hkPackedVector8_3 *>(object)->~hkPackedVector8_3();
}

/* This file's static initializer (0x155a0): hkPackedVector3's reflection
 * (no parent, its one member) and type info, then hkPackedVector8_3's,
 * neither with a finish callback or a vtable. The type infos' names are
 * the base's strings. */
const hkClass D_57b98e0("hkPackedVector3", 0, sizeof(hkPackedVector3), 0, 0, 0, 0, D_168e770, 1, 0,
                        0, 0, 0);
extern const hkTypeInfo D_57b9930;
const hkTypeInfo D_57b9930("hkPackedVector3", "!hkPackedVector3", 0,
                           cleanupLoadedObjecthkPackedVector3, 0, sizeof(hkPackedVector3));
const hkClass D_57b9960("hkPackedVector8_3", 0, sizeof(hkPackedVector8_3), 0, 0, 0, 0, D_168e7a0, 1,
                        0, 0, 0, 0);
extern const hkTypeInfo D_57b99b0;
const hkTypeInfo D_57b99b0("hkPackedVector8_3", "!hkPackedVector8_3", 0,
                           cleanupLoadedObjecthkPackedVector8_3, 0, sizeof(hkPackedVector8_3));
