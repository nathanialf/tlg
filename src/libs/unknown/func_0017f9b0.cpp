/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hkMemoryResourceContainer::FUN_0017f9b0(void *argument)
{
    hkArray<hkResourceHandle *> handles;
    FUN_0017fa60(handles);
    for (int i = 0; i < handles.size; i++) {
        handles[i]->FUN_0017f770(argument);
    }
}
