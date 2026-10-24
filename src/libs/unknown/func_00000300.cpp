/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the cleanup callback of hkMonitorStreamColorTable::ColorPair's
 * type info (0x57af368; hkMonitorStreamFrameInfo's at 0x57af468 holds the
 * same body): destroy the pair in place, which destroys its hkStringPtr. */
void FUN_00000300(void *object) /* derived name */
{
    FUN_0000e5d0(&static_cast<hkMonitorStreamColorTableColorPair *>(object)->colorName);
}
