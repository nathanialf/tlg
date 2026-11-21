/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_math.h"

/* derived names: the 0x50-byte element FUN_01270790 appends (its callers
 * FUN_0125e010, FUN_0147f830 and FUN_0147fb40), the layout of
 * leaf_01005270.cpp's in another unit: an int, three 16-byte aligned
 * four-float vectors copied lane by lane, an int at +0x40 and a counted
 * reference at +0x48, its count raised behind the null test and the
 * released mark. The fields' use and the referenced class are not traced. */
struct Element01270790 { /* derived name */
    int unknown0;
    Float4A unknown10;                 /* +0x10 */
    Float4A unknown20;                 /* +0x20 */
    Float4A unknown30;                 /* +0x30 */
    int unknown40;                     /* +0x40 */
    Ref00503fb0<Object016b9108> ref48; /* +0x48 */
};

/* FUN_01270790 */
template void Array05943280<Element01270790>::push(const Element01270790 &);

/* FUN_012708d0: a copy of an array of them with its own lock (the lock's word
 * cleared after the four fields, then the block made and the elements
 * copied one by one) */
template Array01343a80<Element01270790>::Array01343a80(const Array01343a80<Element01270790> &);
