/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Slot 5 of the debug command executor's vtable (address point 0x16a31e0):
 * a line command drawn through the debug display, the others ignored. */
void hkDebugCommandProcessor::exec(const hkCommand &command)
{
    if (command.secondaryType == 0) {
        const hkDebugLineCommand &line = static_cast<const hkDebugLineCommand &>(command);
        D_57c88c0->FUN_001839d0(line.start, line.end, line.color, 0, D_57c8720);
    }
}
