/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the shape watcher's handler of its shape's change signal:
 * gathers the flags and marks the owner changed (tlg_hk_reflect.h). */
void ShapeWatcher::FUN_00155b00(u8 flags) /* derived name */
{
    changeFlags |= flags;
    owner->anyShapeChanged = true;
}
