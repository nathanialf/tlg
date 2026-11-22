/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_math.h"

/* derived names: the element of an array appended to by FUN_00416db0 (0x41c78a) and FUN_0041c7c0 (0x41d885, 0x41dcde):
 * two 16-byte aligned points copied lane by lane, an int, then two more points; the fields are not traced */
struct Record00422a30 { /* derived name */
    Float4A unknown0;   /* +0x0 */
    Float4A unknown10;  /* +0x10 */
    int unknown20;      /* +0x20 */
    Float4A unknown30;  /* +0x30 */
    Float4A unknown40;  /* +0x40 */
};

/* FUN_00422a30: the append (the count raised, the block grown when it is
 * full, then the element's copy) */
template void Array05943280<Record00422a30>::push(const Record00422a30 &);
