/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkSimpleLocalFrame's type info
 * (0x3a08): construct the frame in place from a loaded image. */
void FUN_000037f0(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkSimpleLocalFrame(flag);
}
