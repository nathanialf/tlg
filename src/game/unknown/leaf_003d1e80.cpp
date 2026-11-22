/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_math.h"

/* derived names: the element of an array appended to by FUN_003ccba0 (0x3cce2d, 0x3cd23c, 0x3cd334) and FUN_003cd420 (0x3ce06a):
 * an int, two 16-byte aligned points copied lane by lane, an int and a third point; the fields are not traced */
struct Record003d1e80 { /* derived name */
    int unknown0;       /* +0x0 */
    Float4A unknown10;  /* +0x10 */
    Float4A unknown20;  /* +0x20 */
    int unknown30;      /* +0x30 */
    Float4A unknown40;  /* +0x40 */
};

/* FUN_003d1e80: the append (the count raised, the block grown when it is
 * full, then the element's copy) */
template void Array05943280<Record003d1e80>::push(const Record003d1e80 &);
