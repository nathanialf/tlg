/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 8 of hkSkinBinding's vtable (0x16a3860) returns the
 * name of its skin. Slot 8 of the forwarding writer at 0x16a6410 reaches
 * the same body. */
const char *hkSkinBinding::FUN_000aa530() const /* derived name */
{
    return skin->getName();
}
