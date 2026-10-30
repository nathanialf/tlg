/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: the cleanup callback of hkMemoryMeshShape::Section's type info
 * (registered by 0x23e10): destroy the section in place. */
void hkMemoryMeshShape::Section::FUN_00023cf0(void *object)
{
    static_cast<Section *>(object)->~Section();
}
