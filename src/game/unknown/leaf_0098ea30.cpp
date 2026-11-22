/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_math.h"
#include "tlg_simd.h"

/* derived names: the 0x60-byte element FUN_0098ea30 appends (called at
 * 0x98e8c6 and 0xea3c6a): four 16-byte aligned four-float vectors copied
 * lane by lane, a vector and two floats copied as one block (+0x50 before
 * the vector at +0x40, `vmovaps`), then a counted reference. The fields' use is not traced. */
struct Element0098ea30 {               /* derived name */
    Float4A unknown0[4];               /* +0x0 */
    Vec4 unknown40;                    /* +0x40 */
    float unknown50[2];                /* +0x50 */
    Ref00503fb0<Object016b9108> ref58; /* +0x58 */
};

/* FUN_0098ea30 */
template void Array05943280<Element0098ea30>::push(const Element0098ea30 &);
