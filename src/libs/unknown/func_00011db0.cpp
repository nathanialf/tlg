/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hkStringBuf::FUN_00011db0()
{
    for (int i = 0; i < getLength(); i++) {
        char c = string.data[i];
        if (c >= 'A' && c <= 'Z') {
            c += 'a' - 'A';
        }
        string.data[i] = c;
    }
}
