/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hknpCharacterStateManager::hknpCharacterStateManager()
{
    for (int i = 0; i < HKNP_CHARACTER_STATE_COUNT; i++) {
        registeredState[i] = 0;
    }
}

hknpCharacterStateManager::~hknpCharacterStateManager()
{
    for (int i = 0; i < HKNP_CHARACTER_STATE_COUNT; i++) {
        if (registeredState[i]) {
            registeredState[i]->removeReference();
            registeredState[i] = 0;
        }
    }
}
