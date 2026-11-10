/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a qsort comparison of pointers (FUN_013a4c60 passes it with the
 * size 8, lea at 0x13a4f2b): orders the records they point to by the unsigned
 * 32-bit key at +0x40, -1, 0 or 1. The record type is not traced. */
struct Record00d1df80 { /* derived name */
    u8 unknown0[0x40];
    u32 unknown40;
};

// NONMATCHING: greedy's assignment: the base gives the first pointer and its key rax/eax and the second rcx, the compile the reverse (rcx/ecx first, rax second); every instruction else equal. The operands swapped in the source move the registers but lose the load fold (30 bytes)
int FUN_00d1df80(const void *first, const void *second) /* derived name */
{
    const Record00d1df80 *a = *static_cast<Record00d1df80 *const *>(first);
    const Record00d1df80 *b = *static_cast<Record00d1df80 *const *>(second);
    if (a->unknown40 >= b->unknown40) {
        return a->unknown40 > b->unknown40;
    }
    return -1;
}
