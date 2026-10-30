/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hkStaticClassNameRegistry::FUN_0017eca0(hkArray<const hkClass *> &classesOut) const
{
    checkIfReady();
    int numClasses = 0;
    for (const hkClass *const *c = classes; *c; c++) {
        numClasses++;
    }
    const hkClass **out = classesOut.expandBy(numClasses);
    for (int i = 0; classes[i]; i++) {
        out[i] = classes[i];
    }
}
