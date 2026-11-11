/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_math.h"

/* derived names: passes its three arguments, a result pointer, a 16-byte
 * vector (read unaligned by the callee) and a float in xmm0 (spilled by the
 * callee), to FUN_013f3670. Neither function returns the result pointer in rax
 * (FUN_013f3670 ends in a call and `ret` with nothing moved to rax), so the
 * result is an ordinary pointer, not a hidden struct return; the callers
 * FUN_01027740 and FUN_0107b510 read it back with aligned loads. The types
 * beyond the widths are not traced. */
void FUN_013f3670(Float4A *result, const Float4 &value, float scale); /* derived name */

// NONMATCHING: the base calls FUN_013f3670 (`call; pop rbp; ret`) where this source gives a
// sibling call (`jmp`); the property of the call or of the callee's declaration that refuses the
// sibling call is not found (a struct return refuses it but adds the result pointer's copy to rax,
// which neither function has)
void FUN_013f33a0(Float4A *result, const Float4 &value, float scale) /* derived name */
{
    FUN_013f3670(result, value, scale);
}
