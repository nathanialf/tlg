/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hkxAttributeGroup's loaded-object cleanup: the group destroyed in place,
 * its attributes from the last, then its name. */
void FUN_00088a00(void *object)
{
    static_cast<hkxAttributeGroup *>(object)->~hkxAttributeGroup();
}
