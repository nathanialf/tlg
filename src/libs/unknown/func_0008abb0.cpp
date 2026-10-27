/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkxTextureInplace's type info (the
 * reflection initializer passes it at 0x8acb6): construct the object in place
 * from a loaded image. */
void FUN_0008abb0(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxTextureInplace(flag);
}
