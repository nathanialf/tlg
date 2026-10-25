/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hkxVertexDescription's type info (0x57c7f90):
 * construct the object in place from a loaded image through its
 * out-of-line finish constructor. */
void FUN_0008ce40(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    FUN_0008c0a0(static_cast<hkxVertexDescription *>(object), flag);
}
