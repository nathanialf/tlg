/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hkResourceContainer::FUN_0017fa60(hkArray<hkResourceHandle *> &handlesOut)
{
    for (hkResourceContainer *child = FUN_001806b0(HK_NULL, HK_NULL); child;
         child = FUN_001806b0(HK_NULL, child)) {
        child->FUN_0017fa60(handlesOut);
    }
    for (hkResourceHandle *handle = FUN_0017ff90(HK_NULL, HK_NULL, HK_NULL); handle;
         handle = FUN_0017ff90(HK_NULL, HK_NULL, handle)) {
        handlesOut.pushBack(handle);
    }
}
