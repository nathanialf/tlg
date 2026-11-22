/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_math.h"
#include "tlg_game_name.h"

/* derived names: the element of an array appended to by FUN_0036cb30 (0x370740, 0x3707af):
 * four 16-byte aligned points copied lane by lane, then a Name (its count raised, its index stored); the fields are not traced */
struct Record003713a0 { /* derived name */
    Float4A unknown0;   /* +0x0 */
    Float4A unknown10;  /* +0x10 */
    Float4A unknown20;  /* +0x20 */
    Float4A unknown30;  /* +0x30 */
    Name name;          /* +0x40 */
};

/* FUN_003713a0: the append (the count raised, the block grown when it is
 * full, then the element's copy) */
template void Array05943280<Record003713a0>::push(const Record003713a0 &);
