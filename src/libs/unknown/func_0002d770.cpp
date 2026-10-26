/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 15 of the world's object at +0x380 sets the two shared
 * floats its slot 14 reads, the second as its negation. */
void hknpWorldObject380::FUN_0002d770(float value0, float value1)
{
    D_16dc5e0 = value0;
    D_16dc5e4 = -value1;
}
