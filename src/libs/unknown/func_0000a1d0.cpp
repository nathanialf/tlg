/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkColor (the class name, the string at 0x14b35c0): no members, one
 * byte. */
struct hkColor {};

/* The type info's cleanup callback, this file's (static, docs/DECISIONS.md
 * D39): nothing to clean up; the linker folded it into the empty body
 * 0x8d60, whose row is AllocatorBase's destructor. */
static void cleanupLoadedObjecthkColor(void *object) /* derived name */
{
    static_cast<hkColor *>(object)->~hkColor();
}

/* This file's static initializer (0xa1d0): hkColor's reflection, no
 * parent and no members, then its type info (no finish callback, no
 * vtable). */
const hkClass D_57b83f0("hkColor", 0, sizeof(hkColor), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
extern const hkTypeInfo D_57b8440;
const hkTypeInfo D_57b8440("hkColor", "!hkColor", 0, cleanupLoadedObjecthkColor, 0,
                           sizeof(hkColor));
