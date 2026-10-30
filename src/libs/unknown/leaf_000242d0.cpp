/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 3 of hkSkinBinding's vtable returns its reflected class.
 * The class's key function, so its vtable and its inline destructor's three
 * variants (0xaa370, 0xaa380, 0xaa3d0) are emitted here. */
const hkClass *hkSkinBinding::getClassType() const /* derived name */
{
    return &D_57bd288;
}
