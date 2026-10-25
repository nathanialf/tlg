/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkxVertexDescription::ElementDecl's
 * type info (0x57c7f10): construct the declaration in place from a loaded
 * image through its inline finish constructor. */
void FUN_0008ce10(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxVertexDescriptionElementDecl(flag);
}
