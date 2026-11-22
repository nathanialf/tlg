/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_math.h"

/* derived names: the 32-byte element of an array appended to by
 * FUN_00f3c260, FUN_00faf970, FUN_00ffe820 and seven more: an int, then a 16-byte
 * aligned point copied lane by lane; the fields are not traced
 * (FUN_00f51f20 and FUN_00f52000 are the same bytes, each over its own
 * element) */
struct Record00f52000 { /* derived name */
    int unknown0;       /* +0x0 */
    Float4A unknown10;  /* +0x10 */
};

/* FUN_00f52000: the append (the count raised, the block grown when it is
 * full, then the element's copy) */
template void Array05943280<Record00f52000>::push(const Record00f52000 &);
