/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the world's handler of the signal at +0x10 of its object at
 * +0x658: marks the id in the bit field at +0x678. */
void hknpWorld::FUN_0004bc90(u8 id)
{
    bits678.set(id);
}
