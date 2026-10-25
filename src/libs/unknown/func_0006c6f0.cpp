/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: hknpMaterial's finish constructor (its type info 0x57c1f40): the
 * only member to finish is the name string at +0. */
void FUN_0006c6f0(hknpMaterial *self, hkFinishLoadedObjectFlag flag) /* derived name */
{
    FUN_0000e5c0(&self->name, flag);
}
