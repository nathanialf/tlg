/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_math.h"

/* derived names: converts four unsigned ints to four floats (the 16-bit halves
 * blended with the magic exponents and added, the back end's unsigned
 * conversion of a vector) and stores them through its first argument; slot 7
 * of the vtable at 0x16c54e8 by the walk back from its pointer at 0x16c5530
 * (no constructor stores it). The types beyond the widths are not traced. */
struct UInt4 { /* derived name */
    u32 x;
    u32 y;
    u32 z;
    u32 w;
};

/* The four are converted before the first is stored (the base converts them
 * as one vector). */
void FUN_01328620(Float4 *out, const UInt4 *in) /* derived name */
{
    float x = in->x;
    float y = in->y;
    float z = in->z;
    float w = in->w;
    out->x = x;
    out->y = y;
    out->z = z;
    out->w = w;
}
