/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"
#include "tlg_hk_thread.h"
#include "tlg_lib_unknown.h"

/* The arrays filled by the step stage on the stack and, when they hold
 * entries or dependencies, built and handed to the owner's slot 7 outside
 * the "Physics" timer, then given back to it. derived name. */
void hknpWorld::FUN_000514a0(RefArraysOwner *owner)
{
    ThreadBuffer &stream = *D_16dc078;
    stream.timerBegin("TtPhysics");
    RefArrays1698f80 arrays;
    FUN_00050dc0(arrays, HK_NULL);
    if (arrays.array10.getSize() || arrays.array20.getSize()) {
        void *built = arrays.FUN_00092650(owner, 12);
        stream.timerEnd("Et");
        owner->unknownVirtual7(built);
        stream.timerBegin("TtPhysics");
        arrays.FUN_00092e70(owner);
    }
    stream.timerEnd("EtPhysics");
}
