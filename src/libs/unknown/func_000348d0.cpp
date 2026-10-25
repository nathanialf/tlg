/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: forwards a flag to FUN_0002b390 from another file; the bool
 * is passed on, so the incoming byte is widened again for the call (0x15d87c
 * calls it with false). */
void FUN_000348d0(Pair08Owner *self, bool enable) /* derived name */
{
    FUN_0002b390(self, enable);
}
