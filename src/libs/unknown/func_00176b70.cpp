/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 0 of hknpCharacterProxy's vtable (0x16a5b70): the proxy leaves the
 * world's two body signals and its post-solve signal, then its body's own
 * signal, removes its body and releases its shape. The deleting destructor
 * (slot 1, 0x176b20) is the compiler's, emitted before this one. */
hknpCharacterProxy::~hknpCharacterProxy()
{
    world->signals.signal50.FUN_000933e0(this);
    world->signals.signal58.FUN_000933e0(this);
    world->signals.postSolveSignal.FUN_000933e0(this);
    world->FUN_0004fbd0(1, bodyId)->FUN_000933e0(this);
    world->FUN_0004e980(&bodyId, 1, 0);
    shape->removeReference();
}
