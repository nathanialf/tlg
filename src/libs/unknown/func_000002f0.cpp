/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hkMonitorStreamColorTable::ColorPair's
 * type info (0x57af360; hkMonitorStreamFrameInfo's at 0x57af460 holds the
 * same body): construct the pair in place from a loaded image, which runs
 * the finish constructor of its hkStringPtr at +0. */
void FUN_000002f0(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    FUN_0000e5c0(&static_cast<hkMonitorStreamColorTableColorPair *>(object)->colorName, flag);
}
