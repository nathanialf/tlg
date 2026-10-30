/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hkMemoryMeshShape::FUN_0002ad50(const hkMeshSection &section)
{
    sections[section.sectionIndex].material = section.material;
}
