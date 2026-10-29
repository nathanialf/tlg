/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpCharacterStateManager::FUN_00035ba0(hknpCharacterState *handler,
                                             hknpCharacterStateType state)
{
    handler->addReference();
    if (registeredState[state]) {
        registeredState[state]->removeReference();
    }
    registeredState[state] = handler;
}
