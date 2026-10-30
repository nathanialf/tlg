/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The index is advanced in the compare (cookbook 111): the loop keeps its
 * test at the top. */
const hkClass *hkStaticClassNameRegistry::FUN_0017ec90(const char *className) const
{
    checkIfReady();
    int i = 0;
    while (classes[i] != 0) {
        if (FUN_00017f40(className, classes[i++]->FUN_00004200()) == 0) {
            return classes[i - 1];
        }
    }
    return 0;
}
