/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: an object holding a stack of ids (+0x5428, its depth at
 * +0x5430) and a list of ids (+0x5440, its count at +0x5448). FUN_00abbfd0
 * says whether any of the n ids asked for is on the stack (every entry from
 * the top down, or only the top one) or in the list. */
struct IdHolder00abbfd0 { /* derived name */
    u8 unknown0[0x5428];
    int *stack; /* +0x5428 */
    int depth;  /* +0x5430 */
    u8 unknown5434[0xc];
    int *list; /* +0x5440 */
    u32 count; /* +0x5448 */

    int listAt(int index) const
    {
        return list[index];
    } /* derived name */
};

/* the ids asked for: a pointer and a count in two registers (rsi, edx), read
 * through an int index under an unsigned counter (`movsxd rbx, ecx` at each
 * use); written as one value, which two parameters would pass the same way */
struct Ids00abbfd0 { /* derived name */
    const int *ids;
    u32 count;

    int at(int index) const
    {
        return ids[index];
    } /* derived name */
};

static inline bool isAsked(Ids00abbfd0 ids, int id) /* derived name */
{
    for (u32 i = 0; i < ids.count; i++) {
        if (id == ids.at(i))
            return true;
    }
    return false;
}

// NONMATCHING: the indices are the base's now (17 of 64: unsigned counters over an int index,
// `movsxd` at each use). Left: the base loads the stack's pointer and its depth at the entry,
// before the test of the last parameter, and in both of its arms tests the count of ids asked
// for before the depth (`test edx, edx; je; test r8d, r8d; jle`), the build the depth first
int FUN_00abbfd0(IdHolder00abbfd0 *holder, Ids00abbfd0 ids, int wholeStack) /* derived name */
{
    if (wholeStack) {
        for (int i = holder->depth - 1; i >= 0; i--) {
            if (isAsked(ids, holder->stack[i]))
                return 1;
        }
    } else if (holder->depth > 0) {
        if (isAsked(ids, holder->stack[holder->depth - 1]))
            return 1;
    }
    for (u32 i = 0; i < holder->count; i++) {
        if (isAsked(ids, holder->listAt(i)))
            return 1;
    }
    return 0;
}
