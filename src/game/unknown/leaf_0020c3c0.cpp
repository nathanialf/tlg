/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_math.h"
#include "tlg_simd.h"

/* derived names: the element of an array appended to by no direct caller in [0x1a3e00, 0x600000):
 * eight 16-byte aligned points copied lane by lane, then a vector in one aligned move; the fields are not traced */
struct Record0020c3c0 { /* derived name */
    Float4A unknown0;   /* +0x0 */
    Float4A unknown10;  /* +0x10 */
    Float4A unknown20;  /* +0x20 */
    Float4A unknown30;  /* +0x30 */
    Float4A unknown40;  /* +0x40 */
    Float4A unknown50;  /* +0x50 */
    Float4A unknown60;  /* +0x60 */
    Float4A unknown70;  /* +0x70 */
    Vec4 unknown80;     /* +0x80 */
};

/* FUN_0020c3c0: the append (the count raised, the block grown when it is
 * full, then the element's copy) */
template void Array05943280<Record0020c3c0>::push(const Record0020c3c0 &);
