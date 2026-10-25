/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 12 of hkSimpleLocalFrame's vtable (address point
 * 0x168d8f0) returns the number of its child frames. */
int hkSimpleLocalFrame::FUN_0000e160() const /* derived name */
{
    return children.size;
}
