/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_simd.h"

/* derived names: two vectors copied whole (`vmovups ymm2, [r15]`) */
struct Shape00c681c0 { /* derived name */
    Vec4 unknown0;     /* +0x0: not traced */
    Vec4 unknown10;    /* +0x10: not traced */
};

/* derived names: a 64-byte entry of the list: the shape, two cleared words,
 * the two floats and the int the caller passes */
struct Entry00c681c0 { /* derived name */

    Entry00c681c0(const Shape00c681c0 &shape, float first, float second, int value)
        : shape(shape), unknown20(0), unknown24(0), first(first), second(second), value(value)
    {
    }

    Shape00c681c0 shape; /* +0x0 */
    int unknown20;       /* +0x20 */
    float unknown24;     /* +0x24 */
    float first;         /* +0x28 */
    float second;        /* +0x2c */
    int value;           /* +0x30 */
};

struct List00c681c0 { /* derived name */
    u8 unknown0[0x18];
    Array05943280<Entry00c681c0> entries; /* +0x18 */
};

struct Holder00c681c0 { /* derived name */
    u8 unknown0[0x18];
    List00c681c0 *list; /* +0x18 */
    u8 unknown20[0x4];
    int added; /* +0x24 */
};

/* FUN_00c681c0: an entry made in a new last slot of the holder's list, when
 * it has one, and counted (its caller FUN_0020e690 is not written) */
void FUN_00c681c0(Holder00c681c0 *holder, const Shape00c681c0 &shape, int value, float first,
                  float second) /* derived name */
{
    if (List00c681c0 *list = holder->list) {
        new (list->entries.append()) Entry00c681c0(shape, first, second, value);
        ++holder->added;
    }
}
