/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_math.h"
#include "tlg_simd.h"

/* derived names: the 0x60-byte element FUN_0078dac0 appends (called at
 * 0x787818 and 0x787a3c): a vector copied whole (`vmovaps`), then five
 * 16-byte aligned four-float vectors copied lane by lane. The fields' use
 * is not traced. */
struct Element0078dac0 {  /* derived name */
    Vec4 unknown0;        /* +0x0 */
    Float4A unknown10[5]; /* +0x10 */
};

/* FUN_0078dac0 */
template void Array05943280<Element0078dac0>::push(const Element0078dac0 &);
