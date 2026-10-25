/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_libc.h"

/* derived names: a memory copy with a signed int count, widened by sign
 * extension for the imported memcpy (the builtin's call stays inside a
 * frame, docs/DECISIONS.md D11); its callers (0x8dd7, 0xf040, 0x14045,
 * 0x946ca) copy the smaller of two sizes. The aligned copy beside it starts
 * at 0x91100. */
void FUN_000910e0(void *dst, const void *src, int n) /* derived name */
{
    memcpy(dst, src, n);
}
