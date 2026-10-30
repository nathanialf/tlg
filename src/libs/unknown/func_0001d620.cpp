/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the finish callback of hkcdPlanarSolid::NodeStorage's type info
 * (0x57ba3b0): construct the storage in place from a loaded image through
 * its inline finish constructor, which has nothing to fix up but the
 * vtable. */
void FUN_0001d620(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkcdPlanarSolid::NodeStorage(flag);
}
