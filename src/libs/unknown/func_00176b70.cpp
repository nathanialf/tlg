/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING (unclaimed, blocked): every instruction equal written as
// hknpCharacterProxy's out-of-line virtual destructor (its deleting variant
// 0x176b20 equal too), but the destructor stores the class's vtable
// 0x16a5b70, which neither vtables file names: a ruling is asked
// (docs/NOTES.md, Round 66A). Until then the body stands as the free
// function its deleting destructor (func_00176b20.cpp) calls.
void FUN_00176b70(hknpCharacterProxy *self) /* derived name */
{
    hknpWorld *world = self->world;
    world->signals.signal50.FUN_000933e0(self);
    world->signals.signal58.FUN_000933e0(self);
    world->signals.postSolveSignal.FUN_000933e0(self);
    world->FUN_0004fbd0(1, self->bodyId)->FUN_000933e0(self);
    world->FUN_0004e980(&self->bodyId, 1, 0);
    self->shape->removeReference();
}
