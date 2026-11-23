/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_nametable.h"

/* derived names: an entry of the table of 32 buckets FUN_0057f6b0 makes and
 * fills, 0x18 bytes: the hash (the name's index) at +0x0, the name at +0x4,
 * a 32-bit value at +0x8 (`mov [rax+8], ecx`), the next entry at +0x10 */
struct Entry0057fa50 { /* derived name */
    u32 hash;          /* +0x0 */
    Name name;         /* +0x4 */
    u32 value;         /* +0x8 */
    u8 unknownc[0x4];
    Entry0057fa50 *next; /* +0x10 */
};

/* FUN_0057fa50 */
// NONMATCHING: FUN_0057fa50, 15/117 at 399 bytes against the base's 438 (the 64 and 128 bucket forms the same):
// the base keeps the new entry's `next` address as a phi of the two paths (`lea r13, [r14+0x10]` on
// the free list's, `rax+0x20` on the new block's) and counts the block's chain down in 64 bits
// (`dec rbx`, the last index a phi of 0 and n-1 in r8); the build stores through the entry and
// counts in 32 bits. The value stays in ecx in the base (moved to r15d in the build).
template void NameTable<Entry0057fa50, 32>::set<u32>(const Name &name, unsigned hash, u32 value);
