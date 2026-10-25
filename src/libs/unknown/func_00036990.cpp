/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hknpConstraintCinfo's type info
 * (0x57beab0): construct it in place from a loaded image through its inline
 * finish constructor, which finishes the name at +0x18. */
void FUN_00036990(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpConstraintCinfo(flag);
}
