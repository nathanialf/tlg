/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the length of an hkStringPtr's string, 0 when it holds
 * none; the stream writer at 0x8965 writes that many bytes of it. */
int hkStringPtr::FUN_0000e770() const /* derived name */
{
    const char *string = cString();
    return string ? FUN_00017fe0(string) : 0;
}
