/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_indices00d10a20.h"

/* FUN_00d10ca0: an index set by name in one of the tables FUN_00d0e4a0 fills
 * (the name's index its hash) */
// NONMATCHING: FUN_00d10ca0, 15/117 at 399 bytes against the base's 438 (the 64 and 128 bucket forms the same):
// the base keeps the new entry's `next` address as a phi of the two paths (`lea r13, [r14+0x10]` on
// the free list's, `rax+0x20` on the new block's) and counts the block's chain down in 64 bits
// (`dec rbx`, the last index a phi of 0 and n-1 in r8); the build stores through the entry and
// counts in 32 bits. The value stays in ecx in the base (moved to r15d in the build).
template void IndexTable00d10a20::set<int>(const Name &name, unsigned hash, int value);
