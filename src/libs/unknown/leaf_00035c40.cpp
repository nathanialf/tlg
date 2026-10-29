/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hknpCharacterState *
hknpCharacterStateManager::FUN_00035c40(hknpCharacterStateType state) const /* derived name */
{
    return registeredState[state];
}
