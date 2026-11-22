/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_math.h"

/* derived names: the element of an array appended to by FUN_00d4a7a0:
 * an 8-byte word, three 16-byte aligned points copied lane by lane, then a second 8-byte word; the fields are not traced */
struct Record00d4cc90 { /* derived name */
    void *unknown0;     /* +0x0 */
    Float4A unknown10;  /* +0x10 */
    Float4A unknown20;  /* +0x20 */
    Float4A unknown30;  /* +0x30 */
    void *unknown40;    /* +0x40 */
};

/* FUN_00d4cc90: the append (the count raised, the block grown when it is
 * full, then the element's copy) */
template void Array05943280<Record00d4cc90>::push(const Record00d4cc90 &);
