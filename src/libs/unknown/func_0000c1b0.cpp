/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0x8d60. */
static void cleanupLoadedObjecthkFourTransposedPointsf(void *object) /* derived name */
{
    static_cast<hkFourTransposedPointsf *>(object)->~hkFourTransposedPointsf();
}

/* This file's static initializer (0xc1b0): hkFourTransposedPointsf's
 * reflection, no parent and its one member, then its type info (no finish
 * callback, no vtable). */
const hkClass D_57b8488("hkFourTransposedPointsf", 0, sizeof(hkFourTransposedPointsf), 0, 0, 0, 0,
                        D_168d650, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57b84d8;
const hkTypeInfo D_57b84d8("hkFourTransposedPointsf", "!hkFourTransposedPointsf", 0,
                           cleanupLoadedObjecthkFourTransposedPointsf, 0,
                           sizeof(hkFourTransposedPointsf));
