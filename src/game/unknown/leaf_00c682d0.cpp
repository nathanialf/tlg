/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_math.h"

/* derived names: 0x48 bytes copied whole (`vmovups ymm0, [r13]`, `[r13+0x20]`
 * and the word at +0x40); the fields are not traced */
struct Shape00c682d0 { /* derived name */
    u8 unknown0[0x48];
};

/* derived names: a 0x90-byte entry of the list: the shape, a point of the
 * four floats and the int the caller passes and a flag; the rest is not set
 * here */
struct Entry00c682d0 {   /* derived name */
    Shape00c682d0 shape; /* +0x0 */
    u8 unknown48[0x8];
    Float4A point; /* +0x50 */
    int value;     /* +0x60 */
    bool flag;     /* +0x64 */
    u8 unknown65[0x2b];
};

struct Holder00c682d0 { /* derived name */
    u8 unknown0[0x18];
    Array05943280<Entry00c682d0> *entries; /* +0x18 */
    int added;                             /* +0x20 */
};

/* FUN_00c682d0: an entry made in a new last slot of the holder's list, when
 * it has one, and counted: its fields set in the slot one by one, the
 * point first and the flag after the count (the base's store order) */
void FUN_00c682d0(Holder00c682d0 *holder, const Shape00c682d0 &shape, int value, float x, float y,
                  float z, float w) /* derived name */
{
    if (Array05943280<Entry00c682d0> *entries = holder->entries) {
        Entry00c682d0 &entry = *entries->append();
        entry.point = Float4A(x, y, z, w);
        entry.shape = shape;
        entry.value = value;
        ++holder->added;
        entry.flag = false;
    }
}
