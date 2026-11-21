/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: an element of a slot's list, 0x50 bytes (`add r15, 0x50`
 * over the loop); not traced */
struct Element0098cb30 { /* derived name */
    u8 unknown0[0x50];
};

/* derived names: one slot of the owner, 0x18 bytes (`lea rax, [r12+r12*2]`
 * then `[rcx+rax*8+0x290]`): its elements and their count */
struct Slot0098cb30 {          /* derived name */
    Element0098cb30 *elements; /* +0x0 */
    int count;                 /* +0x8 */
    u8 unknownc[0xc];
};

/* derived names: the object at +0x280 of the owner; the callee is given
 * its member at +0x1a0 */
struct Shared0098cb30 { /* derived name */
    u8 unknown0[0x1a0];
    u8 member1a0[0x1]; /* +0x1a0: not traced */
};

struct Owner0098cb30 { /* derived name */
    u8 unknown0[0x280];
    Shared0098cb30 *shared; /* +0x280 */
    u8 unknown288[0x8];
    Slot0098cb30 slots[1]; /* +0x290: as many as the owner has; not traced */
};

/* derived names: the work the job at 0x1342934 (FUN_00d680b0's job, its
 * function stored at 0x134292c) hands this function: the owner at +0x10,
 * the slot's index at +0x18 and a count of the finished parts at +0x20 */
struct Work0098cb30 { /* derived name */
    u8 unknown0[0x10];
    Owner0098cb30 *owner; /* +0x10 */
    unsigned index;       /* +0x18 */
    u8 unknown1c[0x4];
    int *finished; /* +0x20 */
};

void FUN_0097acd0(Owner0098cb30 *owner, Element0098cb30 *element, unsigned index,
                  u8 *shared); /* derived name */

/* derived name: each element of the work's slot handed to FUN_0097acd0
 * with the owner, the slot's index and the shared object's member, then the
 * work counted finished (`lock inc`).
 * NONMATCHING: greedy's assignment: the base takes the owner into rcx and
 * copies it to r13 in the loop's preheader, the constant 0x1a0 into rdx;
 * the build takes the owner straight into r13 and the constant into rax
 * (the instructions and the spills are the base's otherwise). */
void FUN_0098cb30(Work0098cb30 *work) /* derived name */
{
    Owner0098cb30 *owner = work->owner;
    const unsigned index = work->index;
    u8 *member = owner->shared->member1a0;
    const int count = owner->slots[index].count;
    for (int i = 0; i < count; ++i)
        FUN_0097acd0(owner, &owner->slots[index].elements[i], index, member);
    __sync_fetch_and_add(work->finished, 1);
}
