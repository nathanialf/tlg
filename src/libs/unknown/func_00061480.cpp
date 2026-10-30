/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the finish callback of hknpMaterialLibrary's type info
 * (registered at 0x6156d): construct the object in place from a loaded
 * image through its inline finish constructor. */
void FUN_00061480(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpMaterialLibrary(flag);
}
