/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: slot 10 of hkSimpleLocalFrame's vtable (0x168d940)
 * returns its parent frame; the next slot (FUN_0000dcd0) sets it. */
hkLocalFrame *FUN_0000dcc0(const hkSimpleLocalFrame *self) /* derived name */
{
    return self->parentFrame;
}
