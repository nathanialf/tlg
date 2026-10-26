/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the character buffer made from a string pointer: empty in
 * its own storage, then the string assigned. */
hkStringBuf::hkStringBuf(const hkStringPtr &source)
{
    FUN_000116c0(this, source.cString());
}
