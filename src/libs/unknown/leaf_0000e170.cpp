/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 13 of hkSimpleLocalFrame's vtable (address point
 * 0x168d8f0) returns a child frame by index. */
hkLocalFrame *hkSimpleLocalFrame::FUN_0000e170(int index) const /* derived name */
{
    return children.data[index];
}
