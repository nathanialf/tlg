/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The finish constructor: the name finished, the listeners (not
 * serialized) an empty array, and a finished gun's type reset (each
 * derived gun's finish constructor then sets its own). */
hknpFirstPersonGun::hknpFirstPersonGun(hkFinishLoadedObjectFlag flag)
    : hkReferencedObject(flag), name(flag)
{
    if (flag.finishing) {
        type = WEAPON_TYPE_INVALID;
    }
}
