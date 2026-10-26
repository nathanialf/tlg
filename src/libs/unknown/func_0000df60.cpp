/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 6 of hkSimpleLocalFrame's vtable (address point
 * 0x168d8f0) sets its transform, row by row as slot 5 copies it out. */
void hkSimpleLocalFrame::FUN_0000df60(const Mat4 &newTransform) /* derived name */
{
    transform.r[0] = newTransform.r[0];
    transform.r[1] = newTransform.r[1];
    transform.r[2] = newTransform.r[2];
    transform.r[3] = newTransform.r[3];
}
