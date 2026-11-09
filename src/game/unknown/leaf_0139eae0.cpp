/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a qsort comparison of 0x10-byte entries (FUN_0139e980 passes
 * it with the size 0x10, lea at 0x139ea52): 1 when the first entry's unsigned
 * 64-bit key is above the second's, -1 otherwise. Class and method unknown. */
struct Entry0139eae0 { /* derived name */
    u64 unknown0;
    u8 unknown8[8];
};

// NONMATCHING: the base keeps the constant select as a branch on one shared return block (`mov eax, 1; cmp; ja ret; mov eax, -1; ret`) where 4.0.0 forms a cmov from this source and from the `?:`; 4.0.0's CodeGenPrepare turns a select into a branch only for an expensive operand (CodeGenPrepare.cpp:4672), and the region has 8 such `mov eax, 1; cmp; jcc; mov eax, -1` sites against 23,920 cmovs; no source form found
int FUN_0139eae0(const void *first, const void *second) /* derived name */
{
    if (static_cast<const Entry0139eae0 *>(first)->unknown0 >
        static_cast<const Entry0139eae0 *>(second)->unknown0) {
        return 1;
    }
    return -1;
}
