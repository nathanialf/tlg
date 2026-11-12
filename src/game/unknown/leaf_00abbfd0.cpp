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
};

static inline bool isAsked(const int *ids, u32 n, int id) /* derived name */
{
    for (int i = 0; i < n; i++) {
        if (id == ids[i])
            return true;
    }
    return false;
}

// NONMATCHING: the base keeps each loop's int index sign-extended at every use (`movsxd rbx,
// ecx` in the loop: the parked IndVarSimplify class of leaf_00f501a0.cpp) where the build
// widens it, and loads the stack's pointer at the entry; returns 1 or 0 as `mov eax`
int FUN_00abbfd0(IdHolder00abbfd0 *holder, const int *ids, u32 n, int wholeStack) /* derived name */
{
    if (wholeStack) {
        for (int i = holder->depth - 1; i >= 0; i--) {
            if (isAsked(ids, n, holder->stack[i]))
                return 1;
        }
    } else if (holder->depth > 0) {
        if (isAsked(ids, n, holder->stack[holder->depth - 1]))
            return 1;
    }
    for (int i = 0; i < holder->count; i++) {
        if (isAsked(ids, n, holder->list[i]))
            return 1;
    }
    return 0;
}
