/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"

/* derived names: a handler FUN_00a104a0 stores after its name's hash (lea at
 * 0xa1089e, the record at 0x5826c10; the event as leaf_00a11860.cpp's):
 * takes the entry named by the event's name at +0x14 out of the array at
 * +0x58 of the object at +0x18 of the record at +0x58 of the object the
 * pointer at 0x57c9390 holds, the last entry moved into its place
 * (removeSwap). An entry is a name, two floats and a byte, the three copied as
 * one block (`mov al, [r15+r12+0xc]` before the quad at +0x4); their
 * meanings are not traced. */
struct Event00a104a0 { /* derived name */
    u8 unknown0[0x10];
    Name unknown10; /* +0x10: the node the event is about */
    Name unknown14; /* +0x14 */
};

struct Entry00a12740 { /* derived name */
    Name name;         /* +0x0 */
    float unknown4;    /* +0x4: squared by FUN_00a12560, which appends the entries */
    float unknown8;    /* +0x8: squared by FUN_00a12560 */
    bool unknownc;     /* +0xc */
};

struct Holder00a12740 { /* derived name */
    u8 unknown0[0x58];
    Array05943280<Entry00a12740> entries; /* +0x58 */
};

struct Member057c9390_58 { /* derived name */
    u8 unknown0[0x18];
    Holder00a12740 *unknown18; /* +0x18 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x58];
    Member057c9390_58 *unknown58; /* +0x58 */
};

extern Object057c9390 *D_57c9390;

void FUN_00a12740(Event00a104a0 *event) /* derived name */
{
    Array05943280<Entry00a12740> &entries = D_57c9390->unknown58->unknown18->entries;
    for (unsigned i = 0; i < entries.size(); ++i) {
        if (entries.at(i).name == event->unknown14) {
            entries.removeSwap(i);
            return;
        }
    }
}
