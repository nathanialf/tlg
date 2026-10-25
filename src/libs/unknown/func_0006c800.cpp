/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: hknpMaterialDescriptor's finish constructor (its type info 0x57c1fc0): the
 * only member to finish is the name string at +0. The same body is the
 * finish callback of hkxAttributeGroup's type info (0x57c6d38). */
void FUN_0006c800(hknpMaterialDescriptor *self, hkFinishLoadedObjectFlag flag) /* derived name */
{
    FUN_0000e5c0(&self->name, flag);
}
