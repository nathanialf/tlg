/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: hkxAttribute's finish constructor, reached from the finish
 * callback of its type info (FUN_0008b870): the only member to finish is the
 * name string at +0. */
void FUN_0017d790(hkxAttribute *self, hkFinishLoadedObjectFlag flag) /* derived name */
{
    FUN_0000e5c0(&self->name, flag);
}
