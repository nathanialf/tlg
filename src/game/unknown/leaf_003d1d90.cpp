/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_math.h"

/* derived names: the element of an array appended to by FUN_003c8210 (0x3c84ee and five more):
 * two 16-byte aligned points copied lane by lane and an int; the fields are not traced */
struct Record003d1d90 { /* derived name */
    Float4A unknown0;   /* +0x0 */
    Float4A unknown10;  /* +0x10 */
    int unknown20;      /* +0x20 */
};

/* FUN_003d1d90: the append (the count raised, the block grown when it is
 * full, then the element's copy) */
template void Array05943280<Record003d1d90>::push(const Record003d1d90 &);
