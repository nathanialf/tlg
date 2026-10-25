/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 7 of hkSkinBinding's vtable (0x16a3860) hands a mesh
 * section on to the same slot of its skin. */
void hkSkinBinding::FUN_000aa520(const hkMeshSection &section) /* derived name */
{
    skin->unknownVirtual7(section);
}
