/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_monitor.h"

/* derived names: the finish callback of hkMonitorStreamStringMap::StringMap's
 * type info (0x57af4e0): construct the entry in place from a loaded image
 * through its out-of-line finish constructor. */
void FUN_00000320(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    FUN_0000d520(static_cast<hkMonitorStreamStringMapStringMap *>(object), flag);
}
