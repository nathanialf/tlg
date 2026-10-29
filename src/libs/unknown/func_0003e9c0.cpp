/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpCharacterContext::FUN_0003e9c0(int state, const hknpCharacterInput &input,
                                        hknpCharacterOutput &output)
{
    const int previous = currentState;
    stateManager->FUN_00035c40(static_cast<hknpCharacterStateType>(previous))
        ->leaveState(*this, state, input, output);
    currentState = state;
    numUpdatesInCurrentState = 0;
    stateManager->FUN_00035c40(static_cast<hknpCharacterStateType>(state))
        ->enterState(*this, previous, input, output);
}
