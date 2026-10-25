/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkpBridgeAtoms' type info
 * (0x57c3038): construct the atoms in place from a loaded image through the
 * inline finish constructor, which re-initialises the bridge atom with its
 * own constraint data when finishing. */
void FUN_00078610(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpBridgeAtoms(flag);
}
