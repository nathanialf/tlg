/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: 84 of 86, the first copy loop's count only: the base expands
// smin(old, new) with ~new first (`mov esi, r13d; not esi; mov edx, ebx`),
// this compile ~old first; IndVars' LFTR in the array's assignment expands
// the select's SCEV, whose operand order follows the select (its true value
// first), and the top's cmov needs the select as written (docs/NOTES.md,
// Round 62A). Hand IR with the two xors swapped compiles to the base.
void LoadedImage::FUN_001a0620(RawImage &rawOut) const
{
    rawOut = image;
}
