/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the string library's 16-byte clear beside its memory fill
 * (FUN_00018160): the buffer's whole 16-byte words set to the zero vector of
 * the constant table (row 2, +0x20). The buffered stream's readers
 * (0x94787, 0x94813, 0x94926, 0x94a95, 0x94d04) call it. */
void FUN_00018250(void *dst, int numBytes) /* derived name */
{
    Vec4 *d = static_cast<Vec4 *>(dst);
    const Vec4 zero = D_14b2060[2];
    for (int i = numBytes >> 4; i > 0; i--) {
        *d++ = zero;
    }
}
