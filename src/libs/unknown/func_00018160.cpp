/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_libc.h"

/* derived names: the string library's memory fill, a wrapper over the
 * imported memset beside FUN_00017e70 (memcpy) and FUN_00018150 (memmove);
 * the count is an unsigned 32-bit int, widened by zero extension. Callers
 * fill with 0 or 0xff (0x5ef0d, 0x915b1). The value is an int: the builtin
 * memset becomes llvm.memset, whose value is a byte, and the library call
 * it lowers to widens that byte again (`movzbl %sil, %esi`); an unsigned
 * char parameter is already known zero-extended and gives no movzbl. */
void FUN_00018160(void *dst, int value, unsigned int n) /* derived name */
{
    memset(dst, value, n);
}
