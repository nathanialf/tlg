/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"
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
 * tests that string, not the second, before deleting it). The third job
 * (0xbd2190) loads a compute shader from the shader cache: its file name is
 * the job's two strings, the profile and a hash of the table's strings.
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

/* the 32-bit FNV-1a hash of a string (offset basis 0x811c9dc5, prime
 * 0x1000193; 0xbd223d), each char sign-extended; an empty string hashes to 0 */
static unsigned HashName00bd2190(const char *name) /* derived name */
{
    if (!name[0])
        return 0;
    unsigned hash = 0x811c9dc5;
    for (int i = 0, n = strlen(name); i < n; i++)
        hash = (hash ^ name[i]) * 0x1000193;
    return hash;
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
    first = new char[0x201];
    second = new char[0x201];
    pairs = new Pair00bc62a0[32];
    // NONMATCHING: slot 2 of 0x16b7770 (0xbd2190): not written beyond the
    // file's name and the frees: the file is then read through the object at
    // +0x28 of a global (its slot 2 given the path and the size's address, the
    // reader's 0x100-byte name copied by strncpy, "file not found %s\n" when it
    // returns none), its bytes copied into a new reference-counted 0x40-byte
    // object, made a shader by FUN_01303ee0 and stored at +0xc00 of the owner
    // by the count (16 bytes each), the read's block released by its tag
    job = [count, first, second, pairs, owner]() -> int {
        char name[0x400];
        name[0] = 0;
        unsigned hash = 0;
        if (pairs) {
            for (Pair00bc62a0 *pair = pairs; pair->first || pair->second; pair++) {
                strcat(name, pair->first);
                strcat(name, pair->second);
            }
            hash = HashName00bd2190(name);
        }
        sprintf(name, "ps4_shader_cache/%s_%s_%s_%08x.sb", first, second, "cs_5_0", hash);
        char path[0x400];
        sprintf(path, "data_trico/%s", name);
        delete[] first;
        delete[] second;
        FreePairs00bc62a0(pairs);
        return 0;
    };
    run = job;
    run();
}
