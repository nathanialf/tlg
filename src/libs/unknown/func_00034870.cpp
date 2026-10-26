/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the int after the one FUN_00034850 reads (FUN_001623a0
 * reads both). */
s32 FUN_00034870(const Pair08Owner *self)
{
    return FUN_0002af50(FUN_0002af30(self))[1];
}
