/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_libc.h"

/* derived names: the string library's memory copy, a wrapper over the
 * imported memcpy; the count is an unsigned 32-bit int, widened by zero
 * extension. */
// NONMATCHING: the base calls memcpy without a tail call inside a frame
// (push rbp; call; pop rbp; ret), the lowering of the llvm.memcpy intrinsic;
// -ffreestanding makes memcpy an ordinary call here, which is tail-called
// (mov edx, edx; jmp). docs/NOTES.md, Round 14.
void FUN_00017e70(void *dst, const void *src, unsigned int n) /* derived name */
{
    memcpy(dst, src, n);
}
