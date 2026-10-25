/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the cleanup callback of hkxVertexDescription::ElementDecl's
 * type info (0x57c7f10): destroy the declaration in place. */
void FUN_0008ce20(void *object) /* derived name */
{
    static_cast<hkxVertexDescriptionElementDecl *>(object)->~hkxVertexDescriptionElementDecl();
}
