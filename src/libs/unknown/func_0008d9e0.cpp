/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hkxEnvironment::Variable's type info
 * (0x57c8100): construct the struct in place from a loaded image, its two
 * strings finished. */
void FUN_0008d9e0(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxEnvironmentVariable(flag);
}
