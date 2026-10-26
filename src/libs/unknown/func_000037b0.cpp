/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkLocalFrameGroup's type info
 * (0x393c): construct the group in place from a loaded image. */
void FUN_000037b0(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkLocalFrameGroup(flag);
}
