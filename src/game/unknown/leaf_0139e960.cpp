/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a qsort comparison of pointers (FUN_00be8900 passes it with the
 * size 8, lea at 0xbe8ab6): orders the records they point to by the unsigned
 * 32-bit key at +0xc, -1, 0 or 1. The record type is not traced. */
struct Record0139e960 { /* derived name */
    u8 unknown0[0xc];
    u32 unknownc;
};

// NONMATCHING: greedy's assignment: the base gives the first pointer and its key rax/eax and the second rcx, the compile the reverse (rcx/ecx first, rax second); every instruction else equal. The operands swapped in the source move the registers but lose the load fold (30 bytes)
int FUN_0139e960(const void *first, const void *second) /* derived name */
{
    const Record0139e960 *a = *static_cast<Record0139e960 *const *>(first);
    const Record0139e960 *b = *static_cast<Record0139e960 *const *>(second);
    if (a->unknownc >= b->unknownc) {
        return a->unknownc > b->unknownc;
    }
    return -1;
}
