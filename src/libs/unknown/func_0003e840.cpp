/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The character context's constructor (D14's Class16969d0 row). */
Class16969d0::Class16969d0(const hknpCharacterStateManager *stateManager, int initialState)
    : characterType(0), stateManager(stateManager), currentState(initialState),
      previousState(initialState), filterEnable(true), maxLinearAcceleration(625.0f),
      maxLinearSpeed(20.0f), gain(1.0f), previousSurfaceVelocity(_mm_setzero_ps()),
      numUpdatesInCurrentState(0)
{
    stateManager->addReference();
}
