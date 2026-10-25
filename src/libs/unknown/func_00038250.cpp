/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hknpBodyCinfo's type info
 * (0x57bedf8): construct it in place from a loaded image through its inline
 * finish constructor, which finishes the name at +0x20. */
void FUN_00038250(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpBodyCinfo(flag);
}
