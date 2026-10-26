/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the int FUN_0002af50 finds in what follows the record's
 * entries (read by FUN_001623a0 beside the record's second int). */
s32 FUN_00034850(const Pair08Owner *self)
{
    return *FUN_0002af50(FUN_0002af30(self));
}
