/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Slot 0 of its vtable, the complete destructor: the node name's
 * destructor is out of line. */
hkAlignSceneToNodeOptions::~hkAlignSceneToNodeOptions()
{
    FUN_0000e5d0(&nodeName);
}
