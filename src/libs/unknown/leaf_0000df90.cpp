/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 7 of hkSimpleLocalFrame's vtable (address point
 * 0x168d8f0) copies the translation row of its transform out. */
void hkSimpleLocalFrame::FUN_0000df90(Vec4 &position) const /* derived name */
{
    position = transform.translation;
}
