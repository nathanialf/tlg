/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_math.h"

/* derived names: the element of an array appended to by FUN_00208ba0, FUN_00a67170 and six more:
 * four 16-byte aligned points copied lane by lane, an 8-byte word, six more points, then three ints copied as one 4-byte and one 8-byte move; the fields are not traced */
struct Record01344560 { /* derived name */
    Float4A unknown0;   /* +0x0 */
    Float4A unknown10;  /* +0x10 */
    Float4A unknown20;  /* +0x20 */
    Float4A unknown30;  /* +0x30 */
    void *unknown40;    /* +0x40 */
    Float4A unknown50;  /* +0x50 */
    Float4A unknown60;  /* +0x60 */
    Float4A unknown70;  /* +0x70 */
    Float4A unknown80;  /* +0x80 */
    Float4A unknown90;  /* +0x90 */
    Float4A unknowna0;  /* +0xa0 */
    int unknownb0;      /* +0xb0 */
    int unknownb4;      /* +0xb4 */
    int unknownb8;      /* +0xb8 */
};

/* FUN_01344560: the append that returns the new element's index (the old
 * count kept across the growth and the copy, then returned) */
template unsigned Array05943280<Record01344560>::add(const Record01344560 &);
