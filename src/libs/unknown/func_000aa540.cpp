/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 9 of hkSkinBinding's vtable (0x16a3860) sets the name
 * of its skin. */
void hkSkinBinding::FUN_000aa540(const char *newName) /* derived name */
{
    skin->setName(newName);
}
