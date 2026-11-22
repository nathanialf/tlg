/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_math.h"

/* derived names: the element of an array appended to by FUN_003c6e00 (0x3c723b, 0x3c79e5):
 * two 16-byte aligned points copied lane by lane, then three ints copied as one 4-byte and one 8-byte move; the fields are not traced */
struct Record003c7f10 { /* derived name */
    Float4A unknown0;   /* +0x0 */
    Float4A unknown10;  /* +0x10 */
    int unknown20;      /* +0x20 */
    int unknown24;      /* +0x24 */
    int unknown28;      /* +0x28 */
};

/* FUN_003c7f10: the append (the count raised, the block grown when it is
 * full, then the element's copy) */
template void Array05943280<Record003c7f10>::push(const Record003c7f10 &);
