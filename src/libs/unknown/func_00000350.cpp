/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_monitor.h"

/* derived names: the finish callback of hkMonitorStreamStringMap's type info
 * (0x57af560): construct the map in place from a loaded image through its
 * out-of-line finish constructor. */
void FUN_00000350(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    FUN_0000d500(static_cast<hkMonitorStreamStringMap *>(object), flag);
}
