/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hkxMaterialShader's type info:
 * construct the object in place from a loaded image (the finish
 * constructor is inline: its four strings finished in order). */
void FUN_0008a490(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxMaterialShader(flag);
}
