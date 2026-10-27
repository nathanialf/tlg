/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"
#include "tlg_lib_unknown.h"

/* derived names: slot 1 of hknpCollidePairsTask's second-base vtable
 * (0x16a4f28), the this-adjusting thunk of its deleting destructor
 * (FUN_0015dc60): back from the task interface at +0x10 to the object, the
 * base destructor FUN_0015dee0, then the object's 0x170 bytes back to the
 * thread's heap. Written as calls because the destructor has no name yet
 * (cookbook 15); the object is never null here, so the conversion goes
 * through a reference. */
void FUN_0015dcc0(hknpTaskInterface *self) /* derived name */
{
    hknpCollidePairsTask &task = static_cast<hknpCollidePairsTask &>(*self);
    FUN_0015dee0(&task);
    D_16dc070->temp58->blockFree(&task, 368);
}
