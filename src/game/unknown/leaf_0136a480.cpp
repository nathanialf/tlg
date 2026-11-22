/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_math.h"

/* derived names: the element of an array appended to by FUN_007204d0,
 * FUN_00728510, FUN_00728ac0 and six more: an 8-byte word, three 16-byte
 * aligned points copied lane by lane, then a second 8-byte word; the
 * fields are not traced */
struct Record0136a480 { /* derived name */
    void *unknown0;     /* +0x0 */
    Float4A unknown10;  /* +0x10 */
    Float4A unknown20;  /* +0x20 */
    Float4A unknown30;  /* +0x30 */
    void *unknown40;    /* +0x40 */
};

/* FUN_0136a480: the append that returns the new element's index (the old
 * count kept across the growth and the copy, then returned) */
template unsigned Array05943280<Record0136a480>::add(const Record0136a480 &);
