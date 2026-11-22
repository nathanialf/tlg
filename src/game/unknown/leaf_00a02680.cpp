/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_math.h"
#include "tlg_simd.h"

/* derived names: the 128-byte element FUN_00a02680 appends (its callers
 * FUN_00a02120 and FUN_00a092d0 build one on the stack, a normalised
 * three-float vector at +0x20 of it among others): its words up to +0x38
 * copied as one block (`vmovups ymm` of +0x0 and +0x18), two four-byte
 * vectors at +0x40 and +0x50 copied lane by lane, then the vector at +0x60
 * and the int at +0x70 as one block (`mov ecx, [r15+0x70]` before the
 * `vmovaps` of +0x60). The fields' use is not traced. */
struct Element00a02680 { /* derived name */
    u8 unknown0[0x38];
    Float4A unknown40; /* +0x40 */
    Float4A unknown50; /* +0x50 */
    Vec4 unknown60;    /* +0x60 */
    int unknown70;     /* +0x70 */
};

/* FUN_00a02680 */
template void Array05943280<Element00a02680>::push(const Element00a02680 &);
