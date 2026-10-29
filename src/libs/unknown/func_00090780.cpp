/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hkPrimaryCommandDispatcher::FUN_00090780(u32 primaryType,
                                              hkSecondaryCommandDispatcher *dispatcher)
{
    if (dispatcher) {
        dispatcher->addReference();
    }
    if (dispatchers[primaryType]) {
        dispatchers[primaryType]->removeReference();
    }
    dispatchers[primaryType] = dispatcher;
}
