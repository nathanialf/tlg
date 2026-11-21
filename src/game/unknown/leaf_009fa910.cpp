/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: a 0xf0-byte entry of the table below: a counted reference
 * at +0xc8 and the key it is found by at +0xd0; the rest not traced */
struct Entry009fa910 /* derived name */
{
    u8 unknown0[0xc8];
    Ref00503fb0<Object016b9108> heldc8; /* +0xc8 */
    const void *keyd0;                  /* +0xd0 */
    u8 unknownd8[0x18];
};

/* derived names: the entries at +0x10, their count at +0x18 */
struct Table009fa910 /* derived name */
{
    /* the first entry with the key, -1 when none has it */
    int find(const void *key) const /* derived name */
    {
        for (int i = 0; i < count; ++i)
            if (entries[i].keyd0 == key)
                return i;
        return -1;
    }

    /* the entry's reference, held by the copy returned */
    Ref00503fb0<Object016b9108> at(int i) const /* derived name */
    {
        return entries[i].heldc8;
    }

    u8 unknown0[0x10];
    Entry009fa910 *entries; /* +0x10 */
    int count;              /* +0x18 */
};

/* derived name: the object the entry with the key refers to, null when no
 * entry has it (FUN_00742080 asks three times) */
// NONMATCHING: copy placement of the returned pointer: the base sets rax from r14 before the
// `lock inc` and again before the `lock xadd` (its exits return without a move) and compares
// [r14 + 8] the second time; the build moves r14 at one exit and compares [rbx]. 25 of 64.
Object016b9108 *FUN_009fa910(const Table009fa910 *table, const void *key)
{
    int i = table->find(key);
    if (i < 0)
        return 0;
    return table->at(i).get();
}
