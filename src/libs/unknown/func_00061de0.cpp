/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hknpBodyQualityLibrary's type info (0x57c1a78):
 * construct the object in place from a loaded image through its out-of-line
 * finish constructor. */
void FUN_00061de0(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    FUN_00071190(static_cast<hknpBodyQualityLibrary *>(object), flag);
}
