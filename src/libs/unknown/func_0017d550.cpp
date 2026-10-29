/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: hkAlignSceneToNodeOptions's node name setter, beside its
 * finish constructor 0x17d520 (the getter of the same member, 0x17d540,
 * is a discarded copy with no row). Every reference reaches it through
 * slot 7 of hkMemoryResourceHandle's vtable, whose identical setter of the
 * name at +0x18 the linker folded onto this copy. */
void hkAlignSceneToNodeOptions::FUN_0017d550(const char *newName) /* derived name */
{
    nodeName = newName;
}
