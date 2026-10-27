/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the ints after the tail's optional 16-byte blocks: one
 * when any flag is set, one more for bit 1 and one for bit 0. */
// NONMATCHING: the base scales each of the three counts by 16 on its own
// (`setne; shlq $4`, `andb $2; shrb $1; shlq $4`, `andq $1; shlq $4`) and adds
// them; this sums the counts and shifts once (docs/NOTES.md, Round 30).
const s32 *FUN_0002af50(const Pair08Tail *tail)
{
    const Vec4 *block = reinterpret_cast<const Vec4 *>(tail);
    block += tail->flags != 0;
    block += (tail->flags & 2) >> 1;
    block += tail->flags & 1;
    return reinterpret_cast<const s32 *>(block);
}
