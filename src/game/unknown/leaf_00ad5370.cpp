/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: FUN_0043c0c0's component (leaf_0043c0c0.cpp) */
struct Component0043c0c0;

void FUN_0043c0c0(Component0043c0c0 *self, u32 code); /* derived name */

/* derived names: a row of a transition table: the state, then for each
 * state it is left from, two codes (-1 for none) handed to the component.
 * 0x2c bytes. */
struct Transition00ad5370 { /* derived name */
    int state;              /* +0x0 */

    struct Codes { /* derived name */
        int first;
        int second;
    } codes[5]; /* +0x4 */
};

extern const Transition00ad5370 D_14f0c00[5];

/* derived names: two state machines of the object at +0x380 of the
 * component FUN_0043c7b0 steps (the first through the table at 0x14f0ae0
 * there, the second here): each a target and a current state, -1 for
 * none. Mode 2 of the second is left again from where the first is unless
 * the first rests in state 0. The byte at +0x14 makes a step a code 99. */
struct Machines00ad5370 { /* derived name */
    bool step(Component0043c0c0 *component);

    int target;   /* +0x0 */
    int current;  /* +0x4 */
    int target8;  /* +0x8 */
    int currentc; /* +0xc */
    u32 unknown10;
    bool unknown14; /* +0x14 */
};

// NONMATCHING: 68/71 at the base's 205 bytes: the mode-2 test's two conditions in the
// other order (the base tests the byte at +0x14 first, then the mode; stage 1 folds them
// into `and (mode == 2), (byte == 0)` with the goal's phi, and selection splits the `and`
// in that order); everything else equal
/* FUN_00ad5370: true while the second machine moves. In mode 2 the goal is
 * state 2 itself; the row of the codes is the goal's, but for a step out of
 * states 1 and 2, the target's */
bool Machines00ad5370::step(Component0043c0c0 *component)
{
    int goal = target8;
    if (!unknown14 && goal == 2) {
        goal = 2;
        int first = current != -1 ? current : target;
        if (first != 0 && (unsigned)currentc >= 2)
            currentc = 0;
    }
    int from = currentc;
    if (from == goal) {
        unknown14 = false;
        currentc = -1;
        return false;
    }
    bool moved = false;
    if (from != -1) {
        moved = true;
        if (unknown14) {
            FUN_0043c0c0(component, 99);
        } else {
            int to = from == 1 || from == 2 ? target8 : goal;
            if (to != from) {
                const Transition00ad5370::Codes codes = D_14f0c00[to].codes[from];
                if (codes.first != -1)
                    FUN_0043c0c0(component, codes.first);
                if (codes.second != -1)
                    FUN_0043c0c0(component, codes.second);
            }
        }
    }
    return moved;
}
