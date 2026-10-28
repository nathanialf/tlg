/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Slot 6 of the debug command executor's vtable: a line command written
 * with its ends and color, the others ignored. */
void hkDebugCommandProcessor::print(const hkCommand &command, hkOstream &stream) const
{
    if (command.secondaryType == 0) {
        const hkDebugLineCommand &line = static_cast<const hkDebugLineCommand &>(command);
        stream.FUN_00008440("hkDebugLineCommand Start=")
            .FUN_000086b0(line.start.quad)
            .FUN_00008440(" End=")
            .FUN_000086b0(line.end.quad)
            .FUN_00008440(" Color=")
            .FUN_00008550(line.color);
    }
}
