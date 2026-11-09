/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: greedy's assignment, 0x15700's class: each of the five blocks'
// construction loops, the base zeroes the second loop's counter before the
// first (`xor eax; movabs rcx; xor edx`, the first loop on rdx), where this
// compile gives the first loop rax and rematerializes the zero after it;
// 132 of 177, 852 against 900 bytes (docs/NOTES.md, Round 88A).

/* The critical section with the spin count, no blocks, then five blocks
 * added, each at the head of the blocks and its entries at the head of the
 * free ones. */
Object00015700::Object00015700(int spinCount) : lock(spinCount)
{
    firstBlock = HK_NULL;
    freeEntries = HK_NULL;
    addBlock();
    addBlock();
    addBlock();
    addBlock();
    addBlock();
}
