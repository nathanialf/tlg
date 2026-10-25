/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"

/* derived names: slot 0 of hknpSolveDataTask's second-base vtable (0x16a56d8):
 * the this-adjusting thunk of its complete destructor FUN_0016eaa0, back from
 * the task interface at +0x10 to the object. Written as a call because the
 * destructor has no name yet; the object is never null here, so the
 * conversion goes through a reference. */
void FUN_0016ec20(hknpTaskInterface *self) /* derived name */
{
    FUN_0016eaa0(&static_cast<hknpSolveDataTask &>(*self));
}
