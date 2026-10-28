/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the whole object cleared to zero vectors or filled with
 * ones, then the choice stored. */
void Object0017a360::FUN_0017a360(bool enabled)
{
    if (enabled) {
        hkString::memSet16(this, &D_14b2060[2], sizeof(*this) / 16);
    } else {
        hkString::memSet4(this, 1, sizeof(*this) / 4);
    }
    timersEnabled = enabled;
}
