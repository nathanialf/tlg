/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 5 of hkSimpleLocalFrame's vtable (address point
 * 0x168d8f0) copies its transform out, row by row (a struct copy compiles
 * to 256-bit moves; the base moves one row at a time). */
void hkSimpleLocalFrame::FUN_0000df30(Mat4 &out) const /* derived name */
{
    out.r[0] = transform.r[0];
    out.r[1] = transform.r[1];
    out.r[2] = transform.r[2];
    out.r[3] = transform.r[3];
}
