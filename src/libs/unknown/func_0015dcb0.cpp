/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"

/* derived names: slots 0 and 1 of hknpCollidePairsTask's second-base vtable
 * (0x16a4f28; slot 1, 0x15dcc0, is the deleting destructor's): the
 * this-adjusting thunk of its complete destructor, back from the task
 * interface at +0x10 to the object, running the base destructor FUN_0015dee0
 * that the complete one (FUN_0015dc50) jumps to. Written as a call because
 * the destructor has no name yet; the object is never null here, so the
 * conversion goes through a reference. */
void FUN_0015dcb0(hknpTaskInterface *self) /* derived name */
{
    FUN_0015dee0(&static_cast<hknpCollidePairsTask &>(*self));
}
