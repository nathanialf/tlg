/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING: as 0xbf40, the inline body refused under -g at cost 330
// against 325 (docs/NOTES.md, Round 52); equal without -g.
void hkQuaternion::FUN_0001a1c0(const hkMatrix3 &r) /* derived name */
{
    setFromRotation(r);
}
