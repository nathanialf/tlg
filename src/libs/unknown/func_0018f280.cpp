/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"

/* derived names: slot 3 of hknpSolverStageTask's second-base vtable (0x16a67a8):
 * the this-adjusting thunk of primary slot 6 (FUN_0018f140, too large to inline
 * into it), back from the task interface at +0x10 to the object, the two
 * buffers passed through. Written as a call because the overrider's body is
 * not written yet; the object is never null here, so the conversion goes
 * through a reference. */
void FUN_0018f280(hknpTaskInterface *self, hkStringBuf *name,
                  hkStringBuf *description) /* derived name */
{
    FUN_0018f140(&static_cast<hknpSolverStageTask &>(*self), name, description);
}
