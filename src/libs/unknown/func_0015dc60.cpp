/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hknpCollidePairsTask's vtable (0x16a4ee0), its
 * deleting destructor: the base destructor FUN_0015dee0, then the object's
 * 368 bytes back to the thread's heap. Written as calls because the
 * destructor has no name yet (cookbook 15, 103). */
void FUN_0015dc60(hknpCollidePairsTask *self)
{
    FUN_0015dee0(self);
    if (self) {
        D_16dc070->temp58->blockFree(self, 368);
    }
}
