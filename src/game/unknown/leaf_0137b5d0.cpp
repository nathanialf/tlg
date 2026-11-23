/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"

/* derived names: a 64-byte group of two buffers of 32-bit values, the one
 * being filled chosen by its holder, and a count at +0x38 */
struct Group0137b5d0 {             /* derived name */
    Array05943280<u32> buffers[2]; /* +0x0, +0x18 */
    u8 unknown30[0x8];             /* not traced */
    int pending;                   /* +0x38 */
    u8 unknown3c[0x4];             /* not traced */
};

/* derived names: the holder of the groups: the buffer in use at +0x10 (the
 * other one is filled), a count of the values added at +0x14 */
struct Holder0137b5d0 { /* derived name */
    u8 unknown0[0x10];
    unsigned current; /* +0x10 */
    int added;        /* +0x14 */
    u8 unknown18[0x8];
    Array05943280<Group0137b5d0> groups; /* +0x20 */
};

/* FUN_0137b5d0: a value added to the buffer not in use of a group (the
 * index `xor rax, 1` of the holder's current one), counted in the group
 * unless the flag is set, and in the holder (callers FUN_01376650,
 * FUN_0137ac50 and FUN_0137b6e0, not written) */
void FUN_0137b5d0(Holder0137b5d0 *holder, int group, u32 value, bool counted) /* derived name */
{
    Group0137b5d0 &entry = holder->groups.at(group);
    entry.buffers[holder->current ^ 1].push(value);
    if (!counted)
        ++entry.pending;
    ++holder->added;
}
