/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: slot 11 of hkSimpleLocalFrame's vtable (0x168d948) sets
 * its parent frame. */
void FUN_0000dcd0(hkSimpleLocalFrame *self, hkLocalFrame *parentFrame) /* derived name */
{
    self->parentFrame = parentFrame;
}
