/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 7 of Pool00007880's vtables tells whether the workers
 * have been handed a callback that has not been waited for. */
bool Pool00007880::FUN_000077a0() const /* derived name */
{
    return running;
}
