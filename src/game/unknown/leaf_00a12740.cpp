/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_libc.h"

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
extern const char D_15a2be0[11]; /* derived name: the format of two numbers apart */

/* derived name: a handler FUN_00a104a0 stores beside FUN_00a12740: reads two
 * numbers from the event's name at +0x14 (each -1 when absent) and, unless
 * both are negative, appends an entry of that name with their squares */
// NONMATCHING: 45/124, 439 bytes against 465: the base's growth looks the block's owner up with a
// null default (`movzx edx, byte [rsi-0x10]; xor edi, edi; cmp edx, 0xa`: reallocateOwnedBlock's
// form, tlg_game_block.h; with push() growing through it, as a diagnostic, 84/124), and the
// entry's name is released at an address formed again in the release's block (`shl rcx, 5;
// lock xadd [rcx+r12+0x10]`) where the build shares the copy's (`lea rax`); seven functions of
// the base have that release (0x301ea0, 0x370c20, 0x48b520, 0x4b5960, 0x4bbcf0, this one,
// 0xa4a4e0), no matched row
void FUN_00a12560(Event00a104a0 *event) /* derived name */
{
    Holder00a12740 *holder = D_57c9390->unknown58->unknown18;
    float first = -1.0f;
    float second = -1.0f;
    sscanf(event->unknown14.string(), D_15a2be0, &first, &second);
    if (first < 0.0f && second < 0.0f)
        return;
    Entry00a12740 entry;
    entry.name = event->unknown14;
    entry.unknown4 = first * first;
    entry.unknown8 = second * second;
    entry.unknownc = false;
    holder->entries.push(entry);
}

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
