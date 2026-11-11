/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include <functional>

/* derived names: FUN_00bc62a0 (29894 bytes, its owner in rdi) parses
 * whitespace-separated words into a table of 32 pairs of strings (each a copy
 * by strlen, new char[] and memcpy, or the pair zeroed), copies two 0x200-byte
 * strings into new 0x201-byte buffers, and hands the lot to a
 * std::function<int()> job: three of them, their implementations' vtables
 * 0x16b76d0, 0x16b7720 and 0x16b7770 (the `lea`s at 0xbc7776, 0xbc932d and
 * 0xbcb15d), each built on the heap (0x38 bytes: the captures are 0x28) and
 * called through a copy (the copy's slot 2 called directly, 0xbc77fc). Each
 * job captures by copy, in this order, an int, the two strings, the table and
 * the owner, passes them on and frees the strings and the table with delete[]
 * (the table's pairs up to the first whose first string is null: the base
 * tests that string, not the second, before deleting it). The third job's body
 * (0xbd2190, 1210 bytes: a hashed name, two sprintfs, a file read) is not
 * written yet; its vtable stays in its holder files.
 * NONMATCHING (slots 2 of 0x16b76d0 and 0x16b7720, 0xbd1fc0 and 0xbd20a0): the
 * base loads the call's arguments from the closure in ascending offset order,
 * the implementation in rbx; this source gives the reverse order, in r14.
 * Slots 0 and 1: the base copies the closure's last 8 bytes before its first
 * 32, this source the other way round. */
struct Pair00bc62a0 { /* derived name */
    char *first;
    char *second;
};

struct Owner00bc62a0 { /* derived name */
    u8 unknown0[8];
    u8 unknown8[0x4f0]; /* +0x8, passed beside the owner to FUN_0139e450 */
    u8 unknown4f8[1];   /* +0x4f8, the object FUN_00bd2650 works on */
};

int FUN_0139e450(Owner00bc62a0 *owner, void *part, int count, char *first, char *second,
                 Pair00bc62a0 *pairs); /* derived name */
int FUN_00bd2650(void *part, int count, char *first, char *second,
                 Pair00bc62a0 *pairs); /* derived name */

static void FreePairs00bc62a0(Pair00bc62a0 *pairs) /* derived name */
{
    for (unsigned int i = 0; i < 32; i++) {
        if (!pairs[i].first)
            break;
        delete[] pairs[i].first;
        delete[] pairs[i].second;
    }
    delete[] pairs;
}

// NONMATCHING: not written beyond the lambdas
void FUN_00bc62a0(Owner00bc62a0 *owner, int count) /* derived name */
{
    char *first = new char[0x201];
    char *second = new char[0x201];
    Pair00bc62a0 *pairs = new Pair00bc62a0[32];
    std::function<int()> job = [count, first, second, pairs, owner]() -> int {
        FUN_0139e450(owner, owner->unknown8, count, first, second, pairs);
        delete[] first;
        delete[] second;
        FreePairs00bc62a0(pairs);
        return 0;
    };
    std::function<int()> run;
    run = job;
    run();
    first = new char[0x201];
    second = new char[0x201];
    pairs = new Pair00bc62a0[32];
    job = [count, first, second, pairs, owner]() -> int {
        FUN_00bd2650(owner->unknown4f8, count, first, second, pairs);
        delete[] first;
        delete[] second;
        FreePairs00bc62a0(pairs);
        return 0;
    };
    run = job;
    run();
}
