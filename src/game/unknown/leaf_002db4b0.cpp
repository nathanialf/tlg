/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_math.h"

/* derived names: the element of an array appended to by FUN_002d4c70 (0x2d4f9f and five more):
 * four 16-byte aligned points copied lane by lane, then three ints copied as one 8-byte and one 4-byte move; the fields are not traced */
struct Record002db4b0 { /* derived name */
    Float4A unknown0;   /* +0x0 */
    Float4A unknown10;  /* +0x10 */
    Float4A unknown20;  /* +0x20 */
    Float4A unknown30;  /* +0x30 */
    int unknown40;      /* +0x40 */
    int unknown44;      /* +0x44 */
    int unknown48;      /* +0x48 */
};

/* FUN_002db4b0: the append (the count raised, the block grown when it is
 * full, then the element's copy) */
template void Array05943280<Record002db4b0>::push(const Record002db4b0 &);
