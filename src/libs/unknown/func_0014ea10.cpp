/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"

/* derived names: slot 2 of hknpAddActiveBodyPairsTask's second-base vtable (0x16a4158):
 * the this-adjusting thunk of primary slot 5 (FUN_0014e850, too large to inline
 * into it), back from the task interface at +0x10 to the object. Written as
 * a call because the overrider's body is not written yet; the object is
 * never null here, so the conversion goes through a reference. */
void FUN_0014ea10(hknpTaskInterface *self) /* derived name */
{
    FUN_0014e850(&static_cast<hknpAddActiveBodyPairsTask &>(*self));
}
