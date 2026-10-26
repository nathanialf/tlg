/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkcdPlanarGeometry's finish constructor: the entity's (the debugger
 * cleared), the unserialized vertices null, and a finished geometry runs
 * FUN_0009a8a0. */
hkcdPlanarGeometry::hkcdPlanarGeometry(hkFinishLoadedObjectFlag flag)
    : hkcdPlanarEntity(flag), vertices(0)
{
    if (flag.finishing) {
        FUN_0009a8a0(0);
    }
}
