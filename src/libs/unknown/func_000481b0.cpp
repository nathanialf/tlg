/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"

/* derived names: the complete destructor of RefArrays (slot 0 of its vtable
 * 0x1698f40; the same body fills slot 0 of 0x1698f80) runs the base
 * destructor 0x48040. The class's destructor is inline (cookbook 9), so its
 * complete variant is its own function; written as the destructor's call
 * because the inline body is not written yet. */
void FUN_000481b0(RefArrays *self) /* derived name */
{
    self->RefArrays::~RefArrays();
}
