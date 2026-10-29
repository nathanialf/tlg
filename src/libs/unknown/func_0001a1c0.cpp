/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* As 0xbf40: the inline body refused under -g until D33. */
void hkQuaternion::FUN_0001a1c0(const hkMatrix3 &r) /* derived name */
{
    setFromRotation(r);
}
